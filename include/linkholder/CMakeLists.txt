set(RELATIVE_PATH ${RELATIVE_PATH}/linkholder)

add_subdirectory(model)
add_subdirectory(service)

install(FILES core.h DESTINATION ${RELATIVE_PATH})

