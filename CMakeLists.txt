cmake_minimum_required(VERSION 3.14)

project(app VERSION 0.1.0 LANGUAGES CXX) # name the project here

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(MAKE_TEST)
    add_subdirectory(tests)
endif()

set(CMAKE_CXX_COMPILER /usr/bin/g++)

add_subdirectory(src)

add_subdirectory(apps)