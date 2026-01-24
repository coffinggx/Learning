#include<iostream>
using namespace std;
#define Cap 3
class Deque{
  int rear;
  int front;
  int size;
  int items[Cap];
  public:
  Deque();
  void insertHead();
  void insertTail();
  int removeHead();
  int removeTail();
  bool isEmpty();
  bool isFull();
};
bool Deque::isFull(){
  if(size == Cap){
    return true;
  } 
  return false;
}
bool Deque::isEmpty(){
  return (size == 0)? true:false;
}
Deque::Deque(){
  front = 0;
  rear =0;
  size =0;
}

void Deque::insertHead(){
  if(isFull()){
    return;
  }
  f
}

