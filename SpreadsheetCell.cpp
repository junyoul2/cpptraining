#include "SpreadsheetCell.h"

SpreadsheetCell::SpreadsheetCell() {}

SpreadsheetCell::SpreadsheetCell(double inValue) : mValue{inValue} {}

SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell &inCell)
    : mValue{inCell.mValue} {}

SpreadsheetCell &SpreadsheetCell::operator=(const SpreadsheetCell &inCell) {
  if (this != &inCell) {
    set(inCell.getValue());
  }
  return *this;
}

SpreadsheetCell::SpreadsheetCell(std::string_view inString) { set(inString); }

void SpreadsheetCell::set(double inValue) { mValue = inValue; }

double SpreadsheetCell::getValue() const { return mValue; }

void SpreadsheetCell::set(std::string_view inString) {
  mValue = stringToDouble(inString);
}

std::string SpreadsheetCell::getString() const {
  return doubleToString(mValue);
}

std::string SpreadsheetCell::doubleToString(double inValue) const {
  return std::to_string(inValue);
}

double SpreadsheetCell::stringToDouble(std::string_view inString) const {
  return std::strtod(inString.data(), nullptr);
}

void SpreadsheetCell::setColor(Color color) { mColor = color; }

SpreadsheetCell::Color SpreadsheetCell::getColor() const { return mColor; }

SpreadsheetCell SpreadsheetCell::add(const SpreadsheetCell &cell) const {
  return SpreadsheetCell(getValue() + cell.getValue());
}

SpreadsheetCell SpreadsheetCell::operator+(const SpreadsheetCell &cell) const {
  return SpreadsheetCell(getValue() + cell.getValue());
}

SpreadsheetCell SpreadsheetCell::operator+(const double rhs) const {
  return SpreadsheetCell(getValue() + rhs);
}

SpreadsheetCell operator+(const SpreadsheetCell &lhs,
                          const SpreadsheetCell &rhs) {
  return SpreadsheetCell(lhs.getValue() + rhs.getValue());
}
