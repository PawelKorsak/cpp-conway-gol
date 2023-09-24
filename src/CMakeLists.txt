set(LIB_HEADER_DIR "${PROJECT_SOURCE_DIR}/include/lib")

set(HEADER_LIST "${LIB_HEADER_DIR}/canvas.hpp" "${LIB_HEADER_DIR}/grid.hpp" "${LIB_HEADER_DIR}/cell.hpp")

add_library(canvas canvas.cpp grid.cpp cell.cpp ${HEADER_LIST})

target_include_directories(canvas PUBLIC ../include)

target_link_libraries(canvas SDL2)
