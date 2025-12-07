#include <cstddef>
#include <iostream>
using namespace std;
template <typename T> class Node {
public:
  T Value;
  Node<T> *Next;
  Node(T value) : Value(value), Next(NULL) {}
};

template <typename T> void PrintNode(Node<T> *node) {
  while (node != NULL) {
    cout << node->Value << "->";
    node = node->Next;
  }
  cout << "NULL" << endl;
}

template <typename T> class LinkedList {
private:
  int m_count;

public:
  Node<T> *Head;
  Node<T> *Tail;
  LinkedList();
  Node<T> *Get(int index);

  void InsertHead(T val);
  void InsertTail(T val);
  void Insert(int index, T val);
  int search(T val);
  void RemoveHead();
  void RemoveTail();
  void Remove(int index);

  int count();
  void PrintList();
};

template <typename T> int LinkedList<T>::count() { return m_count; }

template <typename T> LinkedList<T>::LinkedList() {
  m_count = 0;
  Head = NULL;
  Tail = NULL;
}

template <typename T> Node<T> *LinkedList<T>::Get(int index) {
  if (index > m_count || index < 0) {
    return NULL;
  }

  Node<T> *node = Head;
  for (int i = 0; i < index; ++i) {
    node = node->Next;
  }
  return node;
}
template <typename T> void LinkedList<T>::InsertHead(T val) {
  Node<T> *node = new Node<T>(val);
  node->Next = Head;
  Head = node;
  if (m_count == 0) {
    Tail = node;
  }
  m_count++;
}
template <typename T> void LinkedList<T>::InsertTail(T val) {
  // if LinkedList is empty we simply invoke InsertHead
  if (m_count == 0) {
    InsertHead(val);
    return;
  }

  Node<T> *node = new Node<T>(val);
  Tail->Next = node;
  Tail = node;
  m_count++;
}

template <typename T> void LinkedList<T>::Insert(int index, T val) {
  if (index < 0 || index > m_count) {
    return;
  }
  if (index == 0) {
    InsertHead(val);
    return;
  } else if (index == m_count) {
    InsertTail(val);
    return;
  }
  Node<T> *node = Head;
  Node<T> *newNode = new Node<T>(val);
  for (int i = 0; i < index - 1; ++i) {
    node = node->Next;
  }
  newNode->Next = node->Next;
  node->Next = newNode;
  m_count++;
}
template <typename T> int LinkedList<T>::search(T val) {
  if (m_count == 0) {
    return -1;
  }

  Node<T> *temp = Head;
  int i;
  for (i = 0; i < m_count; ++i) {
    if (temp->Value == val) {
      break;
    }
    temp = temp->Next;
  }
  return i;
}

template <typename T> void LinkedList<T>::RemoveTail() {
  if (m_count == 0) {
    return;
  }
  Node<T> *tail = Head;
  while (tail->Next->Next != NULL) {
    tail = tail->Next;
  }
  tail->Next = NULL;
  m_count--;
}
template <typename T> void LinkedList<T>::RemoveHead() {
  if (m_count == 0) {
    return;
  }
  Node<T> *node = Head;
  Node<T> *newHead = Head->Next;
  Head->Next = NULL;
  Head = newHead;
  m_count--;
}
template <typename T> void LinkedList<T>::Remove(int index) {
  if (m_count == 0 || index >= m_count) {
    return;
  }
  if (index == 0) {
    RemoveHead();
    return;
  } else if (index == m_count - 1) {
    RemoveTail();
    return;
  }
  Node<T> *node = Head;
  Node<T> *temp = Head;
  for (int i = 0; i < index - 1; ++i) {
    node = node->Next;
  }
  temp = node->Next->Next;
  node->Next = temp;
  m_count--;
}
template <typename T> void LinkedList<T>::PrintList() {
  if (m_count == 0) {
    return;
  }
  Node<T> *node = Head;
  while (node != NULL) {
    std::cout << node->Value << "->";
    node = node->Next;
  }
  std::cout << "NULL" << std::endl;
}
int main() {
  LinkedList<int> newLinkedList = LinkedList<int>();
  newLinkedList.InsertHead(12);
  newLinkedList.InsertHead(14);
  newLinkedList.Insert(2, 15);
  newLinkedList.InsertTail(16);
  newLinkedList.RemoveHead();
  newLinkedList.RemoveTail();
  newLinkedList.Remove(1);
  newLinkedList.Remove(0);
  // std::cout << newLinkedList.Get(0)->Value <<"\n";
  newLinkedList.PrintList();
  newLinkedList.InsertHead(1);
  newLinkedList.InsertHead(2);
  newLinkedList.InsertHead(3);
  newLinkedList.InsertHead(4);
  newLinkedList.PrintList();
  std::cout << newLinkedList.search(3) << std::endl;
  std::cout << newLinkedList.count() << std::endl;
}
