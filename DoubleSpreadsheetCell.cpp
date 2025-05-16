#include "DoubleSpreadsheetCell.h"

voud DoubleSpreadsheetCell::set(Double inDouble)
{
  mValue = inDouble;
}

void DoubleSpreadsheetCell::set(std::string_view inString)
{
  mValue = stringToDouble(inString);
}

std::string DoubleSpreadsheetCell::getString()
{
  return (mValue.has_value() ? doubleToString(mValue.value()) : "");
}
