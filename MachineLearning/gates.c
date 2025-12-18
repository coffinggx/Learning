#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float sigmoidf(float x) { return 1.0f / (1.0f + expf(x)); }

typedef float sample[3];

//data for NAND gate
sample nand_train[] = {
    {0, 0, 1},
    {1, 0, 1},
    {0, 1, 1},
    {1, 1, 0},
};

// data for OR gate
sample or_train[] = {
    {0, 0, 0},
    {1, 0, 1},
    {0, 1, 1},
    {1, 1, 1},
};
//data for AND gate
sample and_train[] = {
    {0, 0, 0},
    {1, 0, 0},
    {0, 1, 0},
    {1, 1, 1},
};
sample *train = nand_train;
#define train_count 4

float cost(float w1, float w2, float b) {
  float result = 0.0f;

  for (size_t i = 0; i < train_count; ++i) {
    float x1 = train[i][0];
    float x2 = train[i][1];
    float y = sigmoidf(x1 * w1 + x2 * w2 + b);
    float d = y - train[i][2];
    result += d * d;
    // printf("Actual: %f Expected: %d\n", y, train[i][2]);
  }
  result /= train_count;
  return result;
}
float rand_float(void) { return ((float)rand() / RAND_MAX); }

int main() {
  srand(time(0));
  float w1 = rand_float() * 10 -5;
  float w2 = rand_float() * 10 - 5;
  float b = rand_float();
  float rate = 1e-1;
  float eps = 1e-1;
  for (size_t i = 0; i < 100*100; ++i) {
    float c = cost(w1, w2, b);
    float dw1 = (cost(w1 + eps, w2, b) - c) / eps;
    float dw2 = (cost(w1, w2 + eps, b) - c) / eps;
    float db = (cost(w1, w2, b + eps) - c) / eps;

    w1 -= dw1 * rate;
    w2 -= dw2 * rate;
    b -= db * rate;
    //printf("%f\n", cost(w1,w2,b));
    //printf("w1: %f w2: %f c: %f\n", w1, w2, cost(w1, w2, b));
  }
  for(size_t i =0 ; i<2; ++i){
    for(size_t j=0; j < 2; ++j){
      printf("%zu & %zu : %f\n",i,j,sigmoidf(w1*i + w2*j + b ));
    }
  }
  return 0;
}
// xor representation using and and or
int main2(){
  //since xor gate cannot be modeled using single neuron we can
  //use the combination of (x|y) OR gate , (x&y) AND gate and negtation for NAND gate 
  //and using these combiations we can model xor gate as well
  //XOR gate cannot be modeled using single neuron as XOR problem is not linearly seperable
  //XOR problem can be seen as a single function line cannot cover the behaviour of its output
  //REFERENCE: https://qph.cf2.quoracdn.net/main-qimg-a6c557af4280d1f85cacc66e048e82f3



  // XOR EXAMPLE USING OR AND NAND GATES
  for (size_t x =0 ; x < 2; ++x){
      for (size_t y =0 ; y < 2; ++y){
        printf("%zu ^ %zu: %zu\n", x,y,(x | y) & (~(x&y)));
    }
  }
  return 0;
}
