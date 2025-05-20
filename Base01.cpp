#include <iostream>

class Base01 {
public:
  Base01() { std::cout << "Base01 constructor" << std::endl; }
  Base01(std::string_view str) : mStr(str) {}
  ~Base01() { std::cout << "Base01 destructor" << std::endl; }

private:
  std::string mStr;
};

class Derived : public Base01 {
public:
  using Base01::Base01;
  Derived() { std::cout << "Derived constructor" << std::endl; }
  Derived(int i) : Base01(""), mInt(i) {
    std::cout << "mInt = " << mInt << std::endl;
  }
  ~Derived() { std::cout << "Derived destructor" << std::endl; }

private:
  int mInt;
};

int main() { Derived s1(2); }
