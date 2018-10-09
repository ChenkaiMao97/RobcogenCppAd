cmake_minimum_required(VERSION 2.8.12)
project(pybind_robots)
add_subdirectory(pybind11)

find_package(PythonLibs REQUIRED)

set(EIGEN_ROOT $ENV{EIGEN_ROOT}   CACHE PATH "Path to Eigen headers")
set(CPPAD_ROOT $ENV{CPPAD_ROOT}   CACHE PATH "Path to CppAD headers")

SET(CMAKE_CXX_FLAGS "-g -Wall -O3 -march=native -mtune=native -D EIGEN_NO_DEBUG -std=c++11")


# Include directories
include_directories(${EIGEN_ROOT})
include_directories(${CPPAD_ROOT})
include_directories(${PYTHON_INCLUDE_DIRS})

# Add the binaries

#add_executable(acrobot_test src/acrobot_test.cpp  src/acrobot_wrapper.h src/forward_euler.h src/eigen_util.h)
pybind11_add_module(pybind_robots src/acrobot_test.cpp)
