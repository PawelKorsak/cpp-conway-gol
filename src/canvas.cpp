#include <lib/canvas.hpp>
#include "SDL.h"
#include "SDL_render.h"
#include "SDL_timer.h"
#include "SDL_video.h"

Canvas::Canvas(const uint16_t& X_size_, const uint16_t& Y_size_)
    : dimensions{X_size_, Y_size_}
{
  status.initialised = InitialiseSDL();
}

bool Canvas::InitialiseSDL()
{

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s\n",
                 SDL_GetError());
    return false;
  }
  screen =
      SDL_CreateRGBSurfaceFrom(NULL, dimensions.X, dimensions.Y, 32, 0,
                               0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);

  window =
      SDL_CreateWindow("SDL2 Pixel Drawing", SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, dimensions.X, dimensions.Y, 0);

  renderer = SDL_CreateRenderer(window, -1, 0);
  if (renderer == NULL) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create renderer: %s\n",
                 SDL_GetError());
    return false;
  }

  if (SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255) < 0) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                 "Couldn't set render draw color: %s\n", SDL_GetError());
    return false;
  }
  if (SDL_RenderClear(renderer) < 0) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't render clear: %s\n",
                 SDL_GetError());
    return false;
  }
  SDL_RenderPresent(renderer);
  SDL_Delay(1000);
  if (SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255) < 0) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                 "Couldn't set render draw color: %s\n", SDL_GetError());
    return false;
  }
  if (SDL_RenderDrawLine(renderer, 100, 100, 200, 200) < 0) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                 "Couldn't render draw line: %s\n", SDL_GetError());
    return false;
  }
  SDL_RenderPresent(renderer);
  return true;
}