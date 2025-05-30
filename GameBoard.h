#include "GamePiece.h"
#include <memory>
#include <vector>

class GameBoard {
public:
  explicit GameBoard(size_t width = kDefaultWidth,
                     size_t height = kDefaultHeight);
  GameBoard(const GameBoard &src);
  GameBoard(GameBoard &&src) = default;

  virtual ~GameBoard() = default;

  GameBoard &operator=(const GameBoard &src);
  GameBoard &operator=(GameBoard &&src) = default;

  std::unique_ptr<GamePiece> &at(size_t x, size_t y);
  const std::unique_ptr<GamePiece> &at(size_t x, size_t y) const;

  size_t getWidth() const { return mWidth; }
  size_t getHeight() const { return mHeight; }

  static const size_t kDefaultWidth = 10;
  static const size_t kDefaultHeight = 10;

  friend void swap(GameBoard &first, GameBoard &second) noexcept;

private:
  void verifyCoordinate(size_t x, size_t y) const;

  std::vector<std::vector<std::unique_ptr<GamePiece>>> mCells;
  size_t mWidth, mHeight;
};
