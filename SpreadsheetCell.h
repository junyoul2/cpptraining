#include <string>
#include <string_view>

class SpreadsheetCell {
public:
  enum class Color { Red = 1, Green, Blue, Yellow };
  void setColor(Color color);
  Color getColor() const;

public:
  SpreadsheetCell();
  SpreadsheetCell(double inValue);
  SpreadsheetCell(std::string_view inString);
  SpreadsheetCell(SpreadsheetCell const &inCell);

  void set(double inValue);
  double getValue() const;

  void set(std::string_view inString);
  std::string getString() const;

  SpreadsheetCell add(const SpreadsheetCell &cell) const;

  // SpreadsheetCell &operator=(double inValue);
  SpreadsheetCell &operator=(const SpreadsheetCell &inCell);
  SpreadsheetCell operator+(const SpreadsheetCell &cell) const;
  SpreadsheetCell operator+(const double rhs) const;

private:
  std::string doubleToString(double inValue) const;
  double stringToDouble(std::string_view inString) const;
  double mValue = 0;
  Color mColor = Color::Red;
};

SpreadsheetCell operator+(const SpreadsheetCell &lhs,
                          const SpreadsheetCell &rhs);
