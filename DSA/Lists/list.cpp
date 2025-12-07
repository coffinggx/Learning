
#include"list.h"
#include<iostream>

int List::count(){
  return m_count;
}
void List::print(){
  for(int i=0; i<m_count; ++i){
    std::cout << m_items[i];
  }
  std::cout << "\n";
}
int List::get(int index){
  if(index <0 || index > m_count){
    return -1;
  }
  return m_items[index];
}

void List::insert(int index,int val){
  if(index < 0 || index > m_count){
    return;
  }
    int *oldarray = m_items;
    m_count ++;
    m_items = new int[m_count];
    for(int i=0, j=0 ; i<m_count; ++i){
      if(i == index){
        m_items[i]  = val;
      } else {
        m_items[i] = oldarray[j];
        ++j;
      }
    }
  delete [] oldarray;
}
int List::search(int val){
  if(m_count < 0){
    return -1;
  }
  for(int i =0 ; i< m_count; ++i){ // O(n) time complexity (binary search will  be implemented later)
    if(m_items[i] == val){
      return i;
    }
  }
  return -1;
}
void List::remove(int index){
  if(index < 0|| index > m_count){
    return;
  }
  int *oldarray = m_items;
  m_count --;
  m_items = new int[m_count];
  for(int i= 0, j =0; i<m_count; ++i, ++j){ // O(n) time complexity
    if(j == index){
      ++j;
    } else{
      m_items[i] = oldarray[j];
    }
  }
}
List::List(){
  m_count = 0;
  m_items = new int[m_count];
}
List::~List(){
  delete [] m_items;
}
