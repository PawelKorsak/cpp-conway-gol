#ifndef LIB_H
#define LIB_H

#include <SDL.h>
#include <sys/types.h>
#include <cstdint>
#include <string>
#include "SDL_render.h"
#include "SDL_video.h"

class Canvas {
 public:
  Canvas(const uint16_t& grid_dimensions_, const uint16_t cell_size_, const std::string& title_);
  ~Canvas();

  void Clear();
  void AddCell(const uint16_t& x, const uint16_t y);
  void Update();
  bool Initialised();

 private:
  struct Status {
    bool initialised;
  };
  struct Dimensions {
    uint16_t grid_dimension;
    uint16_t cell_size;
    uint16_t window_size;
  };

  std::string title;

  SDL_Surface* screen;
  SDL_Window* window;
  SDL_Renderer* renderer;

  Dimensions dimensions;
  Status status;

  bool InitialiseSDL();
  bool DeInitialiseSDL();
};

#endif