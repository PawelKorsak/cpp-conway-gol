#include <lib/cell.hpp>

void Cell::setNeighbors(uint16_t neighbors_)
{
  neighbors = neighbors_;
  if (state == DEAD && neighbors == 3) {
    state = ALIVE;
  }
  else if (state == ALIVE && (neighbors > 3 || neighbors < 2)) {
    state = DEAD;
  }
}