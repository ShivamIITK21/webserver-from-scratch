set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
add_executable(server server.cpp)
target_link_libraries(server PUBLIC sockets)
target_link_libraries(server PUBLIC utils)