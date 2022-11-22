cmake_minimum_required(VERSION 3.2)

project(siriuscxx)
set(CMAKE_CXX_STANDARD 17)
add_executable(siriuscxx src/main.cpp)

enable_testing()

add_subdirectory(tests)
