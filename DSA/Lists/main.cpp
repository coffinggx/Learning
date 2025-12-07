#include "list.h"
#include<iostream>
int main() {
  List l;
  l.insert(0, 1);
  l.insert(1, 2);
  l.insert(2, 3);
  l.insert(3, 4);
  std::cout << l.get(0) <<std::endl;
  std::cout << l.count() <<std::endl;
  l.remove(3);
  std::cout << l.search(2) <<std::endl;
  l.print();
}
