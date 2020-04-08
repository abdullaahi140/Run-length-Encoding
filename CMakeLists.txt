cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Playground_Games_Submission CXX)

# creating diretories for binaries, source, include and object files
file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/include)
file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/obj)
file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/src)
file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/test)

# setting the location to store binary and object files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/obj)

# setting the location for compiler to find header files
include_directories(${CMAKE_SOURCE_DIR}/include)

# add -g flag to compiler to allow exectable to be debugged
add_compile_options(-g)
# adding compress.cpp library as dependancy
add_library(compress src/compress.cpp)
# setting the executable
add_executable(main main.cpp)
# linking main file with it's dependancies
target_link_libraries(main compress)

# creating the test executable
add_executable(test_compress test/test_compress.cpp)
target_link_libraries(test_compress compress)