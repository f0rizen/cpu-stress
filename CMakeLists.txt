cmake_minimum_required(VERSION 3.13.4)
project(cpu-stresstest VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS                  "${CMAKE_CXX_FLAGS} -g -fopenmp")
set(CMAKE_EXE_LINKER_FLAGS           "${CMAKE_EXE_LINKER_FLAGS} -lboost_program_options")

add_executable(stress src/stress.cpp)