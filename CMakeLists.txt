cmake_minimum_required(VERSION 3.14)
project(ExtrapolationMethods)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# GoogleTest requires at least C++14
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Include src directory
include_directories(src)

# Libraries
add_library(complex_num src/complex_num.cc)
add_library(extrapolation src/extrapolation.cc)
target_link_libraries(extrapolation PRIVATE complex_num)
add_library(data_provider src/data_provider.cc)

# Main executable
add_executable(extrapolation_solver src/main.cc)
target_link_libraries(extrapolation_solver PRIVATE extrapolation complex_num data_provider)

# Tests
add_executable(complex_num_test tests/complex_num_test.cc)
target_link_libraries(complex_num_test PRIVATE complex_num GTest::gtest_main)
add_test(NAME ComplexNumTest COMMAND complex_num_test)
