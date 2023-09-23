message("INCLUDING EXTERNS")
FetchContent_Declare(
  SDL
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG release-2.28.3
)
FetchContent_MakeAvailable(SDL)