#include "spreadpg.h"
#include <iostream>
#include <vector>

int main() {
  std::vector<Spreadsheet> vec;

  for (int i = 0; i < 2; ++i) {
    std::cout << "Iteration " << i << std::endl;
    vec.push_back(Spreadsheet{100, 100});
    std::cout << std::endl;
  }

  Spreadsheet s{2, 3};
  s = createObject();

  Spreadsheet s2(5, 6);
  s2 = s;

  Spreadsheet sheet1(5, 6);
  SpreadsheetCell &cell1 = sheet1.getCellAt(1, 1);

  const Spreadsheet sheet2(5, 6);
  const SpreadsheetCell &cell2 = sheet2.getCellAt(2, 2);

  return 0;
}
