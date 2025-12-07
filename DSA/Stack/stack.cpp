// stack implementation in cpp for generic types as well
//
#include <iostream>
#define STACK_SIZE 100
template <class T>

class Stack {
private:
  int top;
  T *nodes;

public:
  Stack();
  int empty(void);
  T pop(void);
  T peek(void);
  void push(const T &);
  ~Stack();
};
template <class T> Stack<T>::~Stack() { delete nodes; }
template <class T> Stack<T>::Stack() {
  top = -1;
  nodes = new T[STACK_SIZE];
}

template <class T> void Stack<T>::push(const T &j) {
  if (top == STACK_SIZE - 1) {
    std::cout << "Stack overflow\n";
  }
  nodes[++top] = j;
}

template <class T> T Stack<T>::pop() {
  T p;
  if (empty()) {
    std::cout << "Stack underflow\n";
    return p;
  }
  return nodes[top--];
}

template <class T> int Stack<T>::empty() { return top == -1; }
template <class T> T Stack<T>::peek() {
  T p{};
  if (!empty()) {
    return nodes[top];
  }
  std::cout << "Stack underflow\n";
  return p;
}

int main() {
  Stack<char> sc;
  sc.push('a');
  std::cout << sc.peek() << std::endl;
  sc.pop();
  std::cout << sc.peek() << std::endl;
  Stack<int> si;
  si.push(1);
  std::cout << si.peek() << std::endl;
}
