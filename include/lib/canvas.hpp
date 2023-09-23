#ifndef LIB_H
#define LIB_H

#include <SDL.h>
#include <cstdint>
#include <string>
#include "SDL_render.h"
#include "SDL_video.h"

class Canvas {
 public:
  Canvas(const uint16_t& X_size_, const uint16_t& Y_size_);
  ~Canvas() = default;

 private:
  struct Status {
    bool initialised;
  };
  struct Dimensions {
    uint16_t X;
    uint16_t Y;
  };

  SDL_Surface* screen;
  SDL_Window* window;
  SDL_Renderer* renderer;

  Dimensions dimensions;
  Status status;

  bool InitialiseSDL();
};

#endif