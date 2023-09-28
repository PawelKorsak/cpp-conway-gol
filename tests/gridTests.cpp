#include <gtest/gtest.h>
#include <cstdint>
#include <memory>
#include "lib/grid.hpp"

class GridTests : public ::testing::Test {
 protected:
  void SetUp() override {;};
  void TearDown() override { ; }

 private:
  const uint16_t size_of_grid = 100;
  const uint16_t size_of_cell = 5;

};