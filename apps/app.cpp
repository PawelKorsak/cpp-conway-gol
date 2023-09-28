#include <unistd.h>
#include <iostream>
#include <lib/canvas.hpp>
#include <lib/grid.hpp>
#include <memory>

int main()
{
  std::shared_ptr<Canvas> canvas = std::make_shared<Canvas>(100,5,"Game Of Life");
  Grid grid(canvas);

  grid.setupGrid(100,0.3);
  grid.printGridToCanvas();
  grid.evolve();
  grid.printGridToCanvas();

  while(true) {
    grid.delay(100);
    grid.evolve();
    grid.printGridToCanvas();
  }
  return 0;
}