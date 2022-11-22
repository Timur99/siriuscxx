cmake_minimum_required(VERSION 3.2)

project(testsiriuscxx)
set(CMAKE_CXX_STANDARD 17)
add_executable(tests tests.cpp)

add_test(NAME tests COMMAND tests)
