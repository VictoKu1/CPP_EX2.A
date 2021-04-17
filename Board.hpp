#include "Direction.hpp"
#include <string>

namespace ariel {
class Board {
  char **chars;
  uint rows;
  uint cols;

public:
  Board() {}
  ~Board() {}
  void post(int row, int column, Direction direction, std::string message);
  std::string read(int row, int column, Direction direction, int length);
  void show();
};
} // namespace ariel