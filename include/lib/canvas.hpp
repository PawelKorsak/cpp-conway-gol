#ifndef CANVAS_H
#define CANVAS_H

#include <SDL.h>
#include <sys/types.h>
#include <cstdint>
#include <string>
#include "SDL_render.h"
#include "SDL_video.h"

/// @brief Canvas class is an API for SDL2
class Canvas {
 public:
  /// @brief Construct a new Canvas object
  /// @param grid_dimensions_ The number of cells in the grid
  /// @param cell_size_ The size of each cell in pixels
  /// @param title_ The title of the window
  Canvas(const uint16_t& grid_dimensions_, const uint16_t cell_size_,
         const std::string& title_);
  ~Canvas();

  /// @brief Fill the canvas with black
  void Clear();
  /// @brief Add white cell on canvas
  /// @param x The x coordinate of the cell
  /// @param y The y coordinate of the cell
  void AddCell(const uint16_t& x, const uint16_t y);
  /// @brief Update the canvas after adding cells
  void Update();
  /// @brief Check if the canvas has been initialised
  /// @return true if initialised
  bool Initialised();
  /// @brief Wait for user input
  void WaitLoop();

  struct Status {
    bool initialised;
  };
  struct Dimensions {
    uint16_t grid_dimension;
    uint16_t cell_size;
    uint16_t window_size;
  };
  /// @brief Get the dimensions of the canvas
  /// @return Dimensions struct asigned to the canvas
  Dimensions getDimensions();

 private:
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