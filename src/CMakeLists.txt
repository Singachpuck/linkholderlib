find_package(Boost COMPONENTS date_time REQUIRED)

add_library(${LIBRARY_NAME})

add_subdirectory(linkholder)

target_link_libraries(${LIBRARY_NAME} Boost::date_time)

install(TARGETS ${LIBRARY_NAME})