#include <iostream>

int main() {
  int myArray[3] = {};

  for (auto it : myArray) {
    std::cout << it << std::endl;
  }
}
