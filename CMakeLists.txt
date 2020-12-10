cmake_minimum_required(VERSION 3.17.2)
project(Learn
    VERSION 0.1.0
    DESCRIPTION "HelloGL"
    LANGUAGES CXX)

# Project wide C++ standard
set(CMAKE_CXX_STANDARD 17)

# GLFW Settings
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(lib)
add_subdirectory(src)
