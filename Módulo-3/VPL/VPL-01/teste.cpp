#include <iostream>
#include <string>
#include <list>

int main(){
  std::list<int> lista;
  lista.push_back(5);
  lista.push_back(7);
  lista.push_back(1);
  lista.push_back(2);
  
  std::cout << *lista.rbegin() << std::endl;
  return 0;
}