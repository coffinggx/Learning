// Queue is an abstract data type that serves as an ordered collection of
// entities. end of a queue is rear or tail . enqueue -- add an element to rear
// dequeue -- removes element from front
// peek -- to see next to be dequeued element
// isEmpty -- to check if empty
// Queue works on the principle of First in first out

#include <stdio.h>
#define MAX 100
typedef struct {
  int front;
  int rear;
  int count;
  int items[MAX];
} Queue;
void init(Queue *q) {
  q->front = -1;
  q->rear = -1;
  q->count = 0;
}
int isEmpty(Queue *q) { return (q->front == -1); }
int isFull(Queue *q) { return (q->rear == MAX - 1); }
void enqueue(Queue *q, int data) {
  if (isFull(q)) {
    return;
  }
  if (isEmpty(q)) {
    q->front++;
  }
  q->items[++q->rear] = data;
}
int dequeue(Queue *q) {
  if (isEmpty(q)) {
    printf("Queue underflow\n");
    return -1;
  }
  int data = q->items[q->front];
  q->front++;
  q->count--;
  return data;
}
int peek(Queue *q) {
  if (isEmpty(q)) {
    return -1;
  }
  return q->items[q->front];
}

int main() {
  Queue q;
  init(&q);
  enqueue(&q, 5);
  printf("%d\n", dequeue(&q));
  printf("%d\n", dequeue(&q));
  printf("%d\n",peek(&q));
  return 0;
}
