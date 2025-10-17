cmake_minimum_required(VERSION 4.0)
project(GameFr LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Collect all .cpp/.c files under src/ (CONFIGURE_DEPENDS makes CMake re-run when files change)
file(GLOB GAMEFR_SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${CMAKE_SOURCE_DIR}/src/util/*.cpp
)

file(GLOB GAMEFR_INCLUDE
   ${CMAKE_SOURCE_DIR}/include/*.h
   ${CMAKE_SOURCE_DIR}/include/*.hpp
)

add_library(GameFr ${GAMEFR_SOURCES})

target_include_directories(GameFr PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

