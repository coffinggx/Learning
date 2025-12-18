#include<stdio.h>
#define MAX 10

typedef struct{
  int front;
  int rear;
  int items[MAX];
  int size;
}CQueue;

void init(CQueue *q){
  q->front = 0;
  q->rear= 0;
  q->size = 0;
}

int isFull(CQueue *q){
  return (q->size == MAX -1);
}
int isEmpty(CQueue *q){
  return (q->size ==0 );
}
void enqueue(CQueue *q, int data){
  if(isFull(q)){
    return;
  }
  q->rear = (q->front + q->size)%(MAX -1);
  q->items[q->rear] = data;
  q->size++;
}

int dequeue(CQueue *q){
  if(isEmpty(q)){
    return -1;
  }
  int data = q->items[q->front];
  q->front = (q->front + 1) % (MAX - 1 );
  q->size--;
  return data;
}

void print(CQueue *q){
  if(isEmpty(q)){
    return;
  }
  int i;
  for( i = q->front; i != q->rear; i=(i+1)%(MAX- 1)){
    printf("%d ", q->items[i]);
  }
  printf("%d ", q->items[i]);
  printf("\n");
  // printf("%d\n",q->items[q->rear]);
}

int main(){
  CQueue q;
  init(&q);
  enqueue(&q,1);
  enqueue(&q,2);
  // printf("%d\n",dequeue(&q));
  // printf("%d\n",dequeue(&q));
  print(&q);
  return 0;
}
