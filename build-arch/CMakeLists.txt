cmake_minimum_required(VERSION 3.16)
project(root_project)

set(CMAKE_CXX_STANDARD 17)  # Change to 20 if you use C++20

execute_process(COMMAND root-config --cflags --libs OUTPUT_VARIABLE ROOT_FLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ROOT_FLAGS}")

file(GLOB_RECURSE SRC_FILES *.cpp)
add_executable(program ${SRC_FILES})
