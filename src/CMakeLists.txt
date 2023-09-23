set(HEADER_LIST "${PROJECT_SOURCE_DIR}/include/lib/lib.hpp")

add_library(lib lib.cpp ${HEADER_LIST})

target_include_directories(lib PUBLIC ../include)
