cmake_minimum_required(VERSION 3.24)

project(RotexEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(external/SDL EXCLUDE_FROM_ALL)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME}
  PRIVATE
    src/main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)