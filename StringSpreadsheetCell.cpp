#include "StringSpreadsheetCell.h"

StringSpreadsheetCell::set(std::string_view inString)
{
  mValue = inString;
}

std::string StringSpreadsheetCell::getString()
{
  return mValue.value_or("");
}
