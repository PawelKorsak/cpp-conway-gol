message("TESTING ENABLED")

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG main
)

FetchContent_MakeAvailable(googletest)

include(GoogleTest)

enable_testing()

add_executable(tests tests.cpp)

target_link_libraries(tests lib GTest::gtest_main GTest::gtest)

gtest_discover_tests(tests)

