add_library(
    utils
    include/utils.hpp
    src/utils.cpp
)

target_include_directories(utils PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")