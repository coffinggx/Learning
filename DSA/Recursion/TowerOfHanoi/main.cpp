#include <cstdint>
#include<iostream>

void toh(int n, char source, char auxillary, char destination){
  if(n==1) {
    std::cout << n << " moves from " << source << "to " <<destination<< "\n";
    return;
  }
  toh(n-1, source, destination, auxillary);
  std::cout << n << " moves from " << source << "to " <<destination<< "\n";
  toh(n-1, auxillary, source, destination);
}

int main(){
  const char s = 'A';  // source
  const char a = 'B'; // auxillary
  const char d = 'C';  //destination
  uint32_t no ;
  std::cin>>no;
  toh(no, s,a,d);
  return 0;
}
