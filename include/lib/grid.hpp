#ifndef GRID_H
#define GRID_H

#include <sys/types.h>
#include <cstdint>
#include <lib/canvas.hpp>
#include <lib/cell.hpp>
#include <memory>
#include <vector>

class Grid {

 public:
  Grid(std::shared_ptr<Canvas> canvas_);
  ~Grid() = default;

  enum State { NONE, NON_INITIALIZED, INITIALIZED, ERROR };

  bool setupGrid(const uint16_t& seed, const float& fillRate);

  bool printGridToCanvas();

  void await();

  void evolve();

  void delay(const uint32_t& milliseconds);

 private:
  State state = NONE;

  std::vector<Cell> grid;
  std::shared_ptr<Canvas> canvas;

  uint16_t size_of_grid;
  uint16_t size_of_cell;
};

#endif