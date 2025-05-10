#include <memory>

class Simple {
public:
  void go() {}
  virtual ~Simple() {} // Add a destructor
};

void leaky() {
  std::unique_ptr<Simple> mySimplePtr = std::make_unique<Simple>();
  mySimplePtr->go();
}

int main() {
  leaky();
  return 0;
}
