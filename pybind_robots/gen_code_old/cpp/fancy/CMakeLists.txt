cmake_minimum_required(VERSION 2.8)
project(example)

set(EIGEN_ROOT $ENV{EIGEN_ROOT}   CACHE PATH "Path to Eigen headers")
set(CPPAD_ROOT $ENV{CPPAD_ROOT}   CACHE PATH "Path to CppAD headers")

SET(CMAKE_CXX_FLAGS "-g -Wall -O3 -march=native -mtune=native -D EIGEN_NO_DEBUG -std=c++11")


# Include directories
include_directories(${EIGEN_ROOT})
include_directories(${CPPAD_ROOT})

# Add the binaries
add_executable(test-tpl example)