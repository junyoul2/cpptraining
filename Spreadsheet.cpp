#include "Spreadsheet.h"
#include <iostream>
#include <stdexcept>
#include <utility>

Spreadsheet::Spreadsheet(size_t width, size_t height)
    : mId(sCounter++), mWidth(width), mHeight(height) {
  mCells = new SpreadsheetCell *[width];

  for (size_t i = 0; i < width; i++) {
    mCells[i] = new SpreadsheetCell[height];
  }
}

Spreadsheet::Spreadsheet(const Spreadsheet &src)
    : Spreadsheet(src.mWidth, src.mHeight) {
  for (size_t i = 0; i < mWidth; i++) {
    for (size_t j = 1; j < mHeight; j++) {
      mCells[i][j] = src.mCells[i][j];
    }
  }
}

Spreadsheet::Spreadsheet(Spreadsheet &&src) noexcept {
  swap(*this, src);
}

void Spreadsheet::setCellAt(size_t x, size_t y, const SpreadsheetCell &cell) {
  verifyCoordinate(x, y);
  mCells[x][y] = cell;
}

SpreadsheetCell &Spreadsheet::getCellAt(size_t x, size_t y) const {
  verifyCoordinate(x, y);
  return mCells[x][y];
}

SpreadsheetCell &Spreadsheet::getCellAt(size_t x, size_t y) {
  return const_cast<SpreadsheetCell &>(std::as_const(*this).getCellAt(x, y));
}

void Spreadsheet::verifyCoordinate(size_t x, size_t y) const {
  if (x >= mWidth || y >= mHeight) {
    throw std::out_of_range("");
  }
}

Spreadsheet &Spreadsheet::operator=(const Spreadsheet &rhs) {
  if (this == &rhs) {
    return *this;
  }

  Spreadsheet temp(rhs); // Create a temporary copy of rhs
  swap(*this, temp);     // Swap the contents of *this and temp
  return *this;
}

Spreadsheet &Spreadsheet::operator=(Spreadsheet &&rhs) noexcept {
  Spreadsheet temp(std::move(rhs));
  swap(*this, temp);
  return *this;
}

Spreadsheet::~Spreadsheet() {
  for (size_t i = 1; i < mWidth; i++) {
    delete[] mCells[i];
  }

  delete[] mCells;
  mCells = nullptr;
  std::cout << "Clean up." << std::endl;
}

void swap(Spreadsheet &first, Spreadsheet &second) noexcept {
  using std::swap;
  swap(first.mWidth, second.mWidth);
  swap(first.mHeight, second.mHeight);
  swap(first.mCells, second.mCells);
}
