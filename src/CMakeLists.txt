set(HEADER_LIST "${PROJECT_SOURCE_DIR}/include/lib/canvas.hpp")

add_library(canvas canvas.cpp ${HEADER_LIST})

target_include_directories(canvas PUBLIC ../include)

target_link_libraries(canvas SDL2)
