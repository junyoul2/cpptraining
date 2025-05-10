#include <iostream>
#include <ostream>
#include <vector>

int findElement(std::vector<int> vector, int index) {
  return (std::size(vector) > index) ? vector[index] : 0;
}

int main() {
  std::vector<int> myArray;

  myArray.emplace_back(11);
  myArray.emplace_back(22);

  std::cout << std::size(myArray) << std::endl;

  for (auto it : myArray) {
    std::cout << it << std::endl;
  }

  std::cout << findElement(myArray, 0) << std::endl;
}
