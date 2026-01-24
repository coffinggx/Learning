#include <iostream>
using namespace std;
class Node {
public:
  int data;
  Node *prev;
  Node *next;

public:
  Node() {}
  Node(int data) { this->data = data;
    prev = nullptr;
    next= nullptr;
  }
};
class DLinkedList {
  int m_count;
  Node *head;
  Node *tail;

public:
  DLinkedList();
  ~DLinkedList();
  void insertionFirst(int data); // insert at beginning of a LinkedList
  void insertionLast(int data);
  void insert(int index, int data); // insert at given index
  void deletionFirst();
  void deletionLast();
  void deleteIndex(int index);
  void forwardTraversal();
  void backwardTraversal();
};

void DLinkedList::deletionFirst(){
  if(m_count == 0){
    return;
  }
  if(m_count == 1){
    delete head;
    return;
  } else {
    head = head->next;
    if(head !=nullptr){
      head->prev = nullptr;
    }
  }
  m_count --;

}
 
void DLinkedList::deletionLast(){
  if(m_count == 0){
    return;
  }
  if(m_count ==1 ){
    deletionFirst();
    return;
  }

  Node* tmp = tail;

  tail = tail->prev;
  tail->next = nullptr;

  delete tmp;
  m_count --;
}

void DLinkedList::deleteIndex(int index){
  if(index<0 || index >m_count) return;
  if(index == 0) {
    deletionFirst(); 
    return;
  } else if(index == m_count - 1){
    deletionLast();
    return;
  }
  Node* node  = head;
  for(int i =0; i<index - 1; ++i){
    node = node->next;
  }
  Node* tmp = node->next;
  tmp->next->prev = node;
  node->next = tmp->next;
  delete tmp;
  m_count--;
}

DLinkedList::DLinkedList() {
  m_count = 0;
  head = new Node;
  head = nullptr;
  tail = new Node;
  tail = nullptr;
}
DLinkedList::~DLinkedList() { delete head; }
void DLinkedList::insertionFirst(int data) {
  Node *newNode = new Node(data);
  newNode->next = head;
  newNode->prev = nullptr;
  if (head != nullptr) {
    head->prev = newNode;
  }
  head = newNode;
  if (m_count == 0) {
    tail = head;
  }
  m_count++;
}
void DLinkedList::insertionLast(int data) {
  if (m_count) {
    insertionFirst(data);
    return;
  }
  Node *newNode = new Node(data);
  tail->next = newNode;
  tail = newNode;
  m_count ++;
}

void DLinkedList::insert(int index, int data) {
  if(index < 0 && index > m_count){
    return;
  }
  if(index ==0){
    insertionFirst(data);
    return;
  } else if(index == m_count){
    insertionLast(data);
    return;
  } else{
    Node *tmp= head;
    Node *newNode= new Node(data);
    for(int i =0; i<index - 1; ++i){
      tmp = tmp->next;
    }
    newNode->prev = tmp;
    newNode->next = tmp->next;
    tmp->next->prev = newNode;
    tmp->next = newNode;
  }
  m_count ++; 
}

void DLinkedList::forwardTraversal(){
  Node *node = head;
  for(;node!=nullptr;){
    std::cout << node->data << "->";
    node = node->next;
  }
  std::cout << "nullptr\n";
}
void DLinkedList::backwardTraversal(){
  Node *node = tail;
  for(;node!=nullptr;){
    std::cout << node->data << "<-";
    node = node->prev;
  }
  std::cout << "nullptr\n";
}
int main() { 

  DLinkedList dl = DLinkedList();
  dl.insertionFirst(2);
  dl.insertionFirst(1);
  dl.insertionFirst(0);
  dl.forwardTraversal();
  dl.deletionLast();
  dl.deletionFirst();
  dl.backwardTraversal();
  return 0; }
