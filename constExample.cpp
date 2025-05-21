#include <iostream>

constexpr int getArraySize() { return 32; }

int main() {
  constexpr int size = getArraySize();
  int array[size];

  std::cout << size << std::endl;

  return 0;
}
