#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
typedef float sample[3];

sample xor_train[] ={
  {0,0,0},
  {1,0,1},
  {0,1,1},
  {1,1,0}
};
sample *train = xor_train;

typedef struct {
  float or_w1;
  float or_w2;
  float or_b;
  float and_w1;
  float and_w2;
  float and_b;
  float nand_w1;
  float nand_w2;
  float nand_b;
} Xor;

float rand_float(){
  return rand() / 1.0f;
}
Xor rand_xor(void){
  Xor m;
  m.or_w1 = rand_float();
  m.or_w2 = rand_float();
  m.or_b = rand_float();
  m.and_w1 = rand_float();
  m.and_w2 = rand_float();
  m.and_b = rand_float();
  m.nand_w1 = rand_float();
  m.nand_w2 = rand_float();
  m.nand_b = rand_float();
  return m;

}

float sigmoidf(float x) { return 1.0f / (1.0f + expf(x)); }
float forward(Xor m, float x, float y) {
  float a  = sigmoidf(m.or_w1*x + m.or_w2*y + m.or_b);
  float b  = sigmoidf(m.and_w1*x + m.and_w2*y + m.and_b);
  return sigmoidf(m.nand_w1*a + m.nand_w2*b + m.nand_b);

}

void print_xor(Xor m){
  printf("%f\n",m.or_w1);
  printf("%f\n",m.or_w2);
  printf("%f\n",m.or_b);
  printf("%f\n",m.and_w1);
  printf("%f\n",m.and_w2);
  printf("%f\n",m.and_b);
  printf("%f\n",m.nand_w1);
  printf("%f\n",m.nand_w2);
  printf("%f\n",m.nand_b);

}

int main(void){
  srand(time(0));
  Xor m = rand_xor();
  print_xor(m);
}


