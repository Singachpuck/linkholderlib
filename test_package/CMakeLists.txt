cmake_minimum_required(VERSION 3.15)
project(PackageTest CXX)

find_package(linkholderlib CONFIG REQUIRED)

add_executable(${PROJECT_NAME} src/test.cpp)
target_link_libraries(${PROJECT_NAME} linkholderlib::linkholderlib)
