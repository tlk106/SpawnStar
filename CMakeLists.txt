cmake_minimum_required(VERSION 4.0)
project(SpawnStar)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
  SDL3
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG release-3.4.0
)

FetchContent_MakeAvailable(SDL3)

add_executable(SpawnStar src/main.cpp src/star.cpp)

target_link_libraries(SpawnStar PRIVATE
  SDL3::SDL3
)