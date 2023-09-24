#include <sys/types.h>
#include <unistd.h>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <lib/grid.hpp>
#include <memory>
#include <ostream>
#include <random>
#include "lib/canvas.hpp"
#include "lib/cell.hpp"

Grid::Grid(std::shared_ptr<Canvas> canvas_)
    : size_of_grid(canvas->getDimensions().grid_dimension),
      size_of_cell(canvas->getDimensions().cell_size),
      grid(canvas_->getDimensions().grid_dimension *
           canvas_->getDimensions().grid_dimension),
      canvas(canvas_)
{
  state = NON_INITIALIZED;
  if (size_of_cell * 10 > size_of_grid) {
    state = ERROR;
    return;
  }
  state = INITIALIZED;
}

bool Grid::setupGrid(const uint16_t& seed, const float& fillRate)
{
  if (state == INITIALIZED)
    if (fillRate > 1.0f || fillRate < 0.0f)
      return false;
  srand(seed);
  for (auto& cell : grid) {
    float lifeFactor = (std::floor(rand() % 10000) / 10000.0f);
    if (lifeFactor > fillRate)
      cell.state = Cell::DEAD;
    else
      cell.state = Cell::ALIVE;
  }
  return true;
}

bool Grid::printGridToCanvas()
{
  canvas->Clear();
  for (uint16_t y = 0; y < size_of_grid; y++) {
    for (uint16_t x = 0; x < size_of_grid; x++) {
      if (grid[size_of_grid * y + x].state == Cell::ALIVE)
        canvas->AddCell(x, y);
      if (grid[size_of_grid * y + x].state == Cell::NONE)
        return false;
    }
  }
  canvas->Update();
  return true;
}

void Grid::await()
{
  canvas->WaitLoop();
}

void Grid::evolve()
{
  for (uint16_t y = 0; y < size_of_grid; y++) {
    for (uint16_t x = 0; x < size_of_grid; x++) {
      if (x > 0 && x < size_of_grid - 1) {
        if (y > 0 && y < size_of_grid - 1) {
          uint16_t count_of_neighbors = 0;
          if (grid[size_of_grid * (y + 1) + x].state == Cell::ALIVE)
            count_of_neighbors++;
          if (grid[size_of_grid * (y + 1) + (x + 1)].state == Cell::ALIVE)
            count_of_neighbors++;
          if (grid[size_of_grid * y + (x + 1)].state == Cell::ALIVE)
            count_of_neighbors++;
          if (grid[size_of_grid * (y - 1) + (x + 1)].state == Cell::ALIVE)
            count_of_neighbors++;
          if (grid[size_of_grid * (y - 1) + x].state == Cell::ALIVE)
            count_of_neighbors++;
          if (grid[size_of_grid * (y - 1) + (x - 1)].state == Cell::ALIVE)
            count_of_neighbors++;
          if (grid[size_of_grid * y + (x - 1)].state == Cell::ALIVE)
            count_of_neighbors++;
          if (grid[size_of_grid * (y + 1) + (x - 1)].state == Cell::ALIVE)
            count_of_neighbors++;
          grid[size_of_grid * y + x].setNeighbors(count_of_neighbors);
        } else
          grid[size_of_grid * y + x].state = Cell::DEAD;
      } else
        grid[size_of_grid * y + x].state = Cell::DEAD;
    }
  }
}

void Grid::delay(const uint32_t& milliseconds)
{
  uint32_t start_time = std::chrono::duration_cast<std::chrono::milliseconds>(
                            std::chrono::system_clock::now().time_since_epoch())
                            .count();
  while ((uint32_t)std::chrono::duration_cast<std::chrono::milliseconds>(
             std::chrono::system_clock::now().time_since_epoch())
             .count() < start_time + milliseconds) {
    usleep(1000);
    await();
  }
}
