cmake_minimum_required(VERSION 3.12) 

project(hellocmake LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Debug)

add_executable(a.out code.cpp)
add_executable(test.out string_test.cpp)
add_executable(two_sum.out two_sum.cpp)
add_executable(pow.out pow2.cpp)
add_executable(largestAltitude.out largestAltitude.cpp)