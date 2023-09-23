#include <gtest/gtest.h>
#include <lib/canvas.hpp>

class CanvasTests : public ::testing::Test {
 protected:
  void SetUp() override { canvas = new Canvas(100,10,"test");}
  void TearDown() override { delete canvas; }
  Canvas* canvas;
};