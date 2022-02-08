#include <cstdio>   // From the old C library. Equivalent to #include <stdio.h> in C
#include <iostream> // From the C++ standard library

using namespace std;

int main(){

  // --- In the C way ---//
  printf("Hello world C!\n");

  // --- In the C++ way, using the entire namespace
  std::cout << "Hello world C++!" << std::endl;

  // --- In the C++ way, without including the namespace --- //
  cout << "Hello world C++!"<<endl;
}
