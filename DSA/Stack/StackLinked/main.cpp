#include <iostream>

class Node {
public:
  int data;
  Node *next;
  Node(int data);
};
Node::Node(int data) {
  this->data = data;
  next = nullptr;
}

class Stack {
private:
  Node *head;
  int size;

public:
  Stack();
  void push(int data);
  int pop();
  int top();
  bool isEmpty();
};
int Stack::top(){
  return head->data;
}
bool Stack::isEmpty() {
  if (size == 0)
    return true;
  return false;
}
Stack::Stack() { head = nullptr, size = 0; }
void Stack::push(int data) {
  Node *node = new Node(data);
  if (isEmpty()) {
    head = node;
    node->next = nullptr;
  } else {
    Node *tmp = head;
    node->next = tmp;
    head = node;
  }
  size++;
}
int Stack::pop() {
  if (isEmpty()) {
    return -1;
  }
  Node *tmp = head;
  int data = tmp->data;
  head = tmp->next;
  delete tmp;
  size--;
  return data;
}

int main() {
  Stack s = Stack();
  s.push(2);
  s.push(3);
  std::cout << s.pop();
  std::cout << s.pop();
}
