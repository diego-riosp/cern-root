cmake_minimum_required(VERSION 3.16)
project(root_project)

set(CMAKE_CXX_STANDARD 17)  # Cambia a 20 si usas C++20

# Agrega las flags de ROOT automáticamente
execute_process(COMMAND root-config --cflags --libs OUTPUT_VARIABLE ROOT_FLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ROOT_FLAGS}")

file(GLOB_RECURSE SRC_FILES *.cpp)  # Busca TODOS los .cpp en todas las subcarpetas
add_executable(mi_programa ${SRC_FILES})

