#include <stdio.h>
#include <stdlib.h>
// #include <time.h>
float train_data[][2] = {{0.0, 0.0}, {1, 2.0}, {2, 4.0}, {3, 6.0}, {4, 8.0}};

#define train_count (sizeof(train_data) / sizeof(train_data[0]))
float rand_float(void) { return (float)rand() / RAND_MAX; }
float cost(float w) {
  float result = 0.0f;
  for (size_t i = 0; i < train_count; ++i) {
    float x = train_data[i][0];

    float y = x * w;
    float d = y - train_data[i][1];
    result += (d * d);
    // printf("actual: %f expected: %f\n", y, train_data[i][1]);
  }
  result /= train_count;
  return result;
}
int main() {
  // srand(time(0));

  srand(69);
  float w = rand_float() * 10.0f;
  // y = x*w
  printf("Before derivative: %f\n", cost(w));
  float ep = 1e-3;
  float rate = 1e-3;
  for (size_t i = 0; i <700; ++i) {
    float dcost = (cost(w + ep) - cost(w)) / ep;
    w -= dcost * rate;
  }
  printf("After derivative: %f\n", cost(w));
  printf("Weight: %f\n", w);
  return 0;
}
