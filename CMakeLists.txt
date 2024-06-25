cmake_minimum_required(VERSION 3.15)

set(LIBRARY_NAME linkholderlib)

project(${LIBRARY_NAME} VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
add_subdirectory(include)