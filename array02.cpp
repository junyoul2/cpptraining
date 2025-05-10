#include <array>
#include <iostream>

int main() {
  std::array<int, 3> myArray = {};

  std::cout << std::size(myArray) << std::endl;

  for (auto it : myArray) {
    std::cout << it << std::endl;
  }
}
