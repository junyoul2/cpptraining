#include <iostream>
#include <string>

void func(std::string myString) { std::cout << myString << std::endl; }

void printDebug(std::string myString) {
  printf("main myString: %s \n",
         myString.c_str()); // __AUTO_GENERATED_PRINT_VAR_END__
}

void printDebug2(std::string &rawString) {
  std::cout << "My Test Refactoring" << std::endl;
  std::cout << rawString << std::endl;
}

int main() {
  std::string myString = "Hello, world";
  std::string rawString = R"(Hello, world)";

  func(myString);

  printDebug(myString);

  printDebug2(rawString);

  return 0;
}
