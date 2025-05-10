#include "SpreadsheetCell.h"
#include <cstddef>

class SpreadsheetApplication;

class Spreadsheet {

public:
  Spreadsheet(size_t width, size_t height);
  Spreadsheet(const Spreadsheet &src);
  Spreadsheet(Spreadsheet &&src) noexcept;
  virtual ~Spreadsheet();

  void setCellAt(size_t x, size_t y, const SpreadsheetCell &cell);
  SpreadsheetCell &getCellAt(size_t x, size_t y) const;
  SpreadsheetCell &getCellAt(size_t x, size_t y);
  void verifyCoordinate(size_t x, size_t y) const;
  size_t getId() const;

  Spreadsheet &operator=(const Spreadsheet &src);
  Spreadsheet &operator=(Spreadsheet &&src) noexcept;
  friend void swap(Spreadsheet &first, Spreadsheet &second) noexcept;

private:
  Spreadsheet() = default;
  bool inRange(size_t value, size_t upper) const;
  size_t mWidth = 0;
  size_t mHeight = 0;
  size_t mId = 0;
  SpreadsheetCell **mCells = nullptr;
  static inline size_t sCounter = 0;
};
