#include <iostream>
#include <memory>
#include <set>

int main() {
  std::unique_ptr<int> ptr = std::make_unique<int>(1);

  // std::unique_ptr<int> ptr2 = std::move(ptr);

  std::cout << *ptr << std::endl;

  std::set<double> col1;
  col1.insert(1.0);

  return 0;
}
