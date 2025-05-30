#include "GamePiece.h"
#include <memory>

class ChessPiece : public GamePiece {
public:
  virtual std::unique_ptr<GamePiece> clone() const override;
};

inline std::unique_ptr<GamePiece> ChessPiece::clone() const {
  return std::make_unique<ChessPiece>(*this);
}
