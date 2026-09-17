#include <iostream>
#include <string>
#include "hashtable.h"

int main() {
  std::string x;

  HashTable<std::string> table ;
  
  std::cout << "Dame un IP address: " ;
  std::cin >> x;

  table.add(x);
  std::cout << table.find(x) << std::endl;
    
}
