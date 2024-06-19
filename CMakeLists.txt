cmake_minimum_required(VERSION 3.15)
project(linkholderlib CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost COMPONENTS date_time REQUIRED)
# include_directories( ${Boost_INCLUDE_DIRS} )

# add_executable(${PROJECT_NAME} src/main.cpp src/core.cpp src/service/helper.cpp
#     src/model/UrlItem.cpp src/model/UrlStatistics.cpp src/model/UrlTag.cpp)


add_library(${PROJECT_NAME} src/core.cpp src/service/helper.cpp
src/model/UrlItem.cpp src/model/UrlStatistics.cpp src/model/UrlTag.cpp)
# target_include_directories(linkholderlib PUBLIC include/)
# include_directories(${PROJECT_NAME} PUBLIC include/)
target_include_directories(${PROJECT_NAME} PUBLIC include/)

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER include/core.h)

target_sources(${PROJECT_NAME} PUBLIC FILE_SET HEADERS BASE_DIRS include/
    FILES include/model/UrlItem.h include/model/UrlStatistics.h include/model/UrlTag.h include/service/helper.h)


target_link_libraries(${PROJECT_NAME} Boost::date_time)
install(TARGETS ${PROJECT_NAME} FILE_SET HEADERS)