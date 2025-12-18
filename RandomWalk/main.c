#include <SDL2/SDL.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SCALE 10
#define HEIGHT 600
#define WIDTH 900
#define AGENT_PIXEL 2
typedef enum { POS_X, NEG_X, POS_Y, NEG_Y } Direction;

typedef struct {
  int vx, vy;
} Velocity;

typedef struct {
  int x, y;
  Uint64 color;
} Agent;
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

void move_agent(SDL_Window *window, SDL_Surface *psurface, Agent *pagent) {
  Velocity v = get_rand_velocity();
  if (pagent->x > WIDTH && pagent->y > HEIGHT) {
    pagent->x %= (WIDTH / 2);
    pagent->y %= (HEIGHT / 2);
  }
  for (int i = 0; i < SCALE; ++i) {
    pagent->x += v.vx;
    pagent->y += v.vy;
    printf("x: %d, y:%d\n", pagent->x, pagent->y);
    SDL_FillRect(psurface,
                 &(SDL_Rect){pagent->x, pagent->y, AGENT_PIXEL, AGENT_PIXEL},
                 pagent->color);
  }
}

Direction get_rand_direction() {
  int choice = rand() % 4;
  switch (choice) {
  case 0:
    return POS_X;
  case 1:
    return POS_Y;
  case 2:
    return NEG_X;
  case 3:
    return NEG_Y;
  default:
    return POS_X;
  }
}

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
  SDL_Window *window =
      SDL_CreateWindow("Random Walk", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
  if (window == NULL) {
    fprintf(stderr, "Sdl window cannot be initialized");
    return -1;
  }

  Agent agent1 = (Agent){WIDTH / 2, HEIGHT / 2, 0xFFFFFF};
  Agent agent2 = (Agent){WIDTH / 2, HEIGHT / 2, 0xFF0000};
  Agent *pagents = calloc(agents, (sizeof(Agent)));
  pagents[0]= agent1;
  pagents[1]= agent2;
  SDL_Surface *surface = SDL_GetWindowSurface(window);
  int running = 1;
  while (running) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = 0;
      }
    }
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
    //    break;
    //  }
    for(int i=0; i<2; ++i){
      move_agent(window, surface, &pagents[i]);
    }
    SDL_UpdateWindowSurface(window);
    SDL_Delay(20);
  }
}
