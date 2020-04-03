cmake_minimum_required(VERSION 3.15)
project(src)

set(CMAKE_CXX_STANDARD 17)

add_executable(src
        BallotBox.cpp
        BallotBox.h
        Candidate.cpp
        Candidate.h
        Candidates.cpp
        Candidates.h
        Driver.cpp
        Election.cpp
        Election.h
        Reporter.cpp
        main.cpp
    )


include_directories(Google_tests)

