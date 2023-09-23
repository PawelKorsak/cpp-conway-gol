#include <gtest/gtest.h>
#include <lib/canvas.hpp>

class CanvasTests : public ::testing::Test {
 protected:
  void SetUp() override { canvas = new Canvas(X_size, Y_size); }
  void TearDown() override { delete canvas; }
  uint16_t const X_size{800};
  uint16_t const Y_size{800};
  Canvas* canvas;
};