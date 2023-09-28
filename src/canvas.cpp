#include <cstdint>
#include <cstdlib>
#include <lib/canvas.hpp>
#include "SDL.h"
#include "SDL_render.h"
#include "SDL_video.h"

Canvas::Canvas(const uint16_t& grid_dimensions_, const uint16_t cell_size_,
               const std::string& title_)
    : dimensions({grid_dimensions_, cell_size_}), status({false}), title(title_)
{
  dimensions.window_size = dimensions.grid_dimension * dimensions.cell_size;
  status.initialised = InitialiseSDL();
}

Canvas::~Canvas()
{
  DeInitialiseSDL();
}

void Canvas::AddCell(const uint16_t& x, const uint16_t y)
{
  if (!status.initialised) {
    return;
  }
  if (x > dimensions.grid_dimension || y > dimensions.grid_dimension) {
    return;
  }
  SDL_Rect rect;
  rect.x = x * dimensions.cell_size;
  rect.y = y * dimensions.cell_size;
  rect.w = dimensions.cell_size;
  rect.h = dimensions.cell_size;

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(renderer, &rect);
}

void Canvas::Clear()
{
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
}

void Canvas::Update()
{
  SDL_RenderPresent(renderer);
}

bool Canvas::Initialised()
{
  return status.initialised;
}

void Canvas::WaitLoop()
{
  SDL_Event event;
  if (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      exit(EXIT_SUCCESS);
    }
  }
}

Canvas::Dimensions Canvas::getDimensions()
{
  return dimensions;
}

bool Canvas::InitialiseSDL()
{

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s\n",
                 SDL_GetError());
    return false;
  }
  screen = SDL_CreateRGBSurfaceFrom(NULL, dimensions.window_size,
                                    dimensions.window_size, 32, 0, 0x00FF0000,
                                    0x0000FF00, 0x000000FF, 0xFF000000);

  if (screen == nullptr) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create surface: %s\n",
                 SDL_GetError());
    return false;
  }

  window = SDL_CreateWindow("Canvas", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, dimensions.window_size,
                            dimensions.window_size, 0);

  if (window == nullptr) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window: %s\n",
                 SDL_GetError());
    return false;
  }

  renderer = SDL_CreateRenderer(window, -1, 0);

  if (renderer == NULL) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create renderer: %s\n",
                 SDL_GetError());
    return false;
  }

  return true;
}

bool Canvas::DeInitialiseSDL()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return true;
}