find_package(Boost COMPONENTS date_time REQUIRED)

add_library(${LIBRARY_NAME})

target_sources(${LIBRARY_NAME} PUBLIC core.cpp)

add_subdirectory(model)
add_subdirectory(service)

target_link_libraries(${LIBRARY_NAME} Boost::date_time)

install(TARGETS ${LIBRARY_NAME})