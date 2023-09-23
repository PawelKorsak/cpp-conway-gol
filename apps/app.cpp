#include <unistd.h>
#include <iostream>
#include <lib/canvas.hpp>

int main()
{
  Canvas canvas(100, 10, "Canvas");
  if(!canvas.Initialised()) {
    std::cout << "Canvas not initialised" << std::endl;
    return 1;
  }
  canvas.Clear();
  canvas.AddCell(0, 1);
  canvas.AddCell(1, 1);
  canvas.AddCell(2, 1);
  canvas.Update();
  std::cin.get();
  return 0;
}