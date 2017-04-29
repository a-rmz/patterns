cmake_minimum_required(VERSION 3.1)
project(twitter-patterns)

# Use C++11
set (CMAKE_CXX_STANDARD 11)

# Include headers into the project
include_directories(include)
include_directories(src)

# Use as source every .cpp under src/
file(GLOB SOURCES 
  "src/*.cpp"
  "src/automaton/*.cpp"
)
file(GLOB SRC_HEADERS 
  "src/*.h"
  "src/automaton/*.h"
)

add_executable(patterns ${SOURCES} ${SRC_HEADERS})
