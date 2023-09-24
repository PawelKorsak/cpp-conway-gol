#ifndef CELL_H
#define CELL_H

#include <cstdint>

class Cell {
 public:
  Cell() = default;
  ~Cell() = default;

  enum STATE { NONE, ALIVE, DEAD };

  STATE state = NONE;
  void setNeighbors(uint16_t neighbors_);

 private:
  uint16_t neighbors = 0;
};

#endif