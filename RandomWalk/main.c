#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCALE 10
#define HEIGHT 720
#define WIDTH 1080
#define AGENT_PIXEL 2

// typedef enum { POS_X, NEG_X, POS_Y, NEG_Y } Direction;

typedef struct {
  int vx, vy;
} Velocity;

typedef struct {
  int x, y;
  Uint64 color;
} Agent;

Uint64
generate_vibrant_color() {    // this function create vibrant colors as range is
                              // from 128..255 as 0 is dark and 255 is bright
  int r = 128 + rand() % 128; // 128..255
  int g = 128 + rand() % 128;
  int b = 128 + rand() % 128;
  return (r << 16) | (g << 8) |
         b; // this basically shifts bits and join with OR operator
}
// creating multiple agents with new color for each
void create_agents(Agent *pagents, int agents) {
  for (int i = 0; i < agents; ++i) {
    Uint64 color = generate_vibrant_color();
    printf("0x%06lX\n", color);
    pagents[i] = (Agent){WIDTH / 2, HEIGHT / 2, color};
  }
}

// generate random velocity or say direction to which it will be going
Velocity get_rand_velocity() {
  int choice = rand() % 4;
  switch (choice) {
  case 0:
    return (Velocity){1, 0};
  case 1:
    return (Velocity){0, 1};
  case 2:
    return (Velocity){-1, 0};
  case 3:
    return (Velocity){0, -1};
  default:
    return (Velocity){0, 0};
  }
}

// since random_velocity function increase by 1 pixel so we need line and only
// update the line
void move_agent(SDL_Surface *psurface, Agent *pagent) {
  Velocity v = get_rand_velocity();
  for (int i = 0; i < SCALE; ++i) {
    pagent->x += v.vx;
    pagent->y += v.vy;
    // printf("x: %d, y:%d\n", pagent->x, pagent->y);
    SDL_FillRect(psurface,
                 &(SDL_Rect){pagent->x, pagent->y, AGENT_PIXEL, AGENT_PIXEL},
                 pagent->color);
  }
}

// Was experimenting with enum but it was getting larger and complicated
// Direction get_rand_direction() {
//   int choice = rand() % 4;
//   switch (choice) {
//   case 0:
//     return POS_X;
//   case 1:
//     return POS_Y;
//   case 2:
//     return NEG_X;
//   case 3:
//     return NEG_Y;
//   default:
//     return POS_X;
//   }
// }

int main(int argc, const char *argv[]) {
  int agents = 0;
  switch (argc) {
  case 1:
    agents = 5;
    break;
  case 2:
    agents = atoi(argv[1]);
    break;
  default:
    printf("Usuage: %s <number_of_agents>\n", argv[0]);
    return -1;
    break;
  }

  srand(time(NULL));
  // creating sdl window
  SDL_Window *window =
      SDL_CreateWindow("Random Walk", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
  if (window == NULL) {
    fprintf(stderr, "Sdl window cannot be initialized");

    return -1;
  }

  // dynamic memory allocation for agents
  Agent *pagents = calloc(agents, (sizeof(Agent)));
  // creating multiple agents
  create_agents(pagents, agents);

  // get drawing surface from window
  SDL_Surface *surface = SDL_GetWindowSurface(window);
  int running = 1;

  // infinite loop for continous drawing
  while (running) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        // for quiting
        running = 0;
      }
    }

    // Experimental stuffs
    // switch (dir) {
    //  case POS_X:
    //    rect.x += v.vx;
    //    rect.y += 0;
    //    break;
    //  case POS_Y:
    //    rect.x += 0;
    //    rect.y += v.vy;
    //    break;
    //  case NEG_X:
    //    rect.x -= v.vx;
    //    rect.y += 0;
    //    break;
    //  case NEG_Y:
    //    rect.x += 0;
    //    rect.y -= v.vy;
    //    break;
    //  default:
    //    rect.x += v.vx;
    //    rect.y += v.vy;
    // break;
    //  }
    // printf("%d", agents);

    // iterate for different agents
    for (int i = 0; i < agents; ++i) {
      move_agent(surface, &pagents[i]);
    }
    move_agent(surface, &pagents[0]);
    // update for single line at a time
    SDL_UpdateWindowSurface(window);

    // delay for updating
    SDL_Delay(20);
  }
  // freeing allocated memory
  free(pagents);
}
