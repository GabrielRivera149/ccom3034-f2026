# IP hash

A test program for hashing IP addresses (32-bit IPv4 addresses) to a
small (16-bit) integer.

Compile the test program:
```
g++ -o ip-hash ip-hash.cpp
```

Then run it and give it an IP address (string).

```
$ ./ip-hash
Dame un IP address: 24.50.234.230
24.50.234.230 tiene hashCode 405990118 y hash 63804
$ ./ip-hash 
Dame un IP address: 136.145.180.154
136.145.180.154 tiene hashCode 2291250330 y hash 26814
```

# Main

The file main.cpp uses hashtable.h to provide a hash table for IP addresses.

HashTable uses any-array.h and sllist.h to build hash tables.

HashTable calls add() and find() as methods of SLList, which are currently unimplemented.

Implement add() and find() in sllist.h so that our hash table implementation works.

