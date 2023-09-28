message("TESTING ENABLED")

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG main
)

FetchContent_MakeAvailable(googletest)

include(GoogleTest)

enable_testing()

add_executable(tests gridTests.cpp)

target_link_libraries(tests canvas GTest::gtest_main GTest::gtest)

gtest_discover_tests(tests)

