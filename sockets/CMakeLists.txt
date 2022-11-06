add_library(
    sockets
    include/serversocket.hpp
    include/headers.hpp
    src/serversocket.cpp
)

target_include_directories(sockets PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")