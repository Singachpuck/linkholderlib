cmake_minimum_required(VERSION 3.15)
project(linkholderlib CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED)
include_directories( ${Boost_INCLUDE_DIRS} )

add_executable(${PROJECT_NAME} src/main.cpp src/core.cpp src/service/helper.cpp
    src/model/UrlItem.cpp src/model/UrlStatistics.cpp src/model/UrlTag.cpp)
target_link_libraries(${PROJECT_NAME} Boost::boost)
target_include_directories(${PROJECT_NAME} PUBLIC include/)

