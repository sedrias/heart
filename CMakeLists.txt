cmake_minimum_required(VERSION 3.28)
project(heart LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(heart main.cpp)
target_compile_options(heart PRIVATE -Wall -Wextra -Wpedantic)

# Static linking: heart.exe runs on any Windows PC without MinGW DLLs
target_link_options(heart PRIVATE -static)
