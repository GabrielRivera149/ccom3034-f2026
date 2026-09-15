// ip-hash.cpp - hash an IP address string into a small (16-bit) number

#include <iostream>
#include <string>

int d = 16;			// bits que quiero en el hash
int z = 2654435769;		// una constante "random" impar
				// en realidad el alpha de Knuth
				// o https://en.wikipedia.org/wiki/Hash_function#Fibonacci_hashing
int w = 32; 			// tamaño de int

int getOctet(std::string ip) {
  // convierte el proximo octeto de un ip address a un numero 0-255
  int end = ip.find(".");	// encuentra el .
  int octet = std::stoi(ip.substr(0, end)); // corta el string
				// y conviertelo a int
  return octet;
}
  
unsigned int hashCode(std::string ip) {
  // convierte un ip como "136.145.54.33" a el entero 2291217953
  // 136 * 256^3 + 145 * 256^2 + 54 * 256 + 33
  unsigned int val = 0;

  for (int i = 3; i >= 0; i--) {
    val *= 256;
    val += getOctet(ip);
    ip = ip.substr(ip.find(".") + 1);
  }
  return val;
}
  
unsigned int hash(std::string x) {
  // multiplicative hash
  // https://en.wikipedia.org/wiki/Hash_function#Multiplicative_hashing
  return ((unsigned)(z * hashCode(x))) >> (w-d);
}


int main() {
  std::string x;

  std::cout << "Dame un IP address: " ;
    std::cin >> x;
  std::cout << x <<
    " tiene hashCode " << hashCode(x) <<
    " y hash " << hash(x) << std::endl;
}
