#include <iostream>
#include <string>
#include <string_view>

enum class Digit { FIRST, SECOND, THIRD };
void printString(std::string_view sv) { std::cout << sv << std::endl; }

int main() {
  std::string str = "str";
  std::string str2 = "Hello world!";

  printString(str2);

  auto digit1 = Digit::FIRST;
  auto digit2 = Digit::FIRST;

  if (digit1 == digit2) {
    std::cout << "digit1 == digit2" << std::endl;
  }

  Digit d1;
  Digit d2;

  d1 = Digit::FIRST;
  d2 = Digit::SECOND;

  return 0;
}
