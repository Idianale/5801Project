cmake_minimum_required(VERSION 3.15)
project(src)

set(CMAKE_CXX_STANDARD 17)

add_executable(src
        Candidate.cpp
        Candidate.h
        Candidates.cpp
        Candidates.h
        main.cpp
    )


include_directories(Google_tests)

