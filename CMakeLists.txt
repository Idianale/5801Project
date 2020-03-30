cmake_minimum_required(VERSION 3.15)
project(repo-Team16)

set(CMAKE_CXX_STANDARD 17)

include_directories(includes/src)

add_executable(repo-Team16 main.cpp, Candidate.cpp, Candidate.h)