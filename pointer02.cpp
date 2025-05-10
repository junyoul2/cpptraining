#include <iostream>

void func(char *str) { std::cout << "char* version" << std::endl; }
void func(int i) { std::cout << "int version" << std::endl; }

int main() {
  func(nullptr);
  return 0;
}
