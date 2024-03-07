cmake_minimum_required(VERSION 3.14)
project(question03)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD_REQUIRED True)

enable_testing()

add_subdirectory(googletest)
add_subdirectory(tests)
add_subdirectory(libs)