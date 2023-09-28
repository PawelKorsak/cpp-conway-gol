#ifndef GRID_H
#define GRID_H

#include <sys/types.h>
#include <cstdint>
#include <lib/canvas.hpp>
#include <lib/cell.hpp>
#include <memory>
#include <vector>

/// @brief Grid class is a logical representation of the world of the game of life
class Grid {

 public:
  /// @brief Constructor of the Grid class
  /// @param canvas_ shared pointer to the canvas object
  Grid(std::shared_ptr<Canvas> canvas_);
  ~Grid() = default;

  enum State { NONE, NON_INITIALIZED, INITIALIZED, ERROR };

  /// @brief Fill the grid with random cells
  /// @param seed The seed for the random number generator
  /// @param fillRate The factor of cells that will be alive to the total number of cells
  bool setupGrid(const uint16_t& seed, const float& fillRate);

  /// @brief Print the grid to the canvas
  bool printGridToCanvas();

  /// @brief Evolve the grid to the next generation
  void evolve();

  /// @brief Delay the program for a given number of milliseconds
  void delay(const uint32_t& milliseconds);

 private:
  State state = NONE;

  std::vector<Cell> grid;
  std::vector<Cell> old_grid;
  std::shared_ptr<Canvas> canvas;

  uint16_t size_of_grid;
  uint16_t size_of_cell;

  void await();
};

#endif