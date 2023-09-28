#ifndef CELL_H
#define CELL_H

#include <cstdint>

/// @brief Cell class is a representation of a cell in the grid
class Cell {
 public:
  Cell() = default;
  ~Cell() = default;

  enum STATE { NONE, ALIVE, DEAD };
  /// @brief State of the cell
  STATE state = NONE;
  /// @brief Set the number of neighbors and change the state of the cell based on rules of the game of life
  void setNeighbors(uint16_t neighbors_);

 private:
  uint16_t neighbors = 0;
};

#endif