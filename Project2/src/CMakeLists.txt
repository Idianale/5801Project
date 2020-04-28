cmake_minimum_required(VERSION 3.15)
project(electionSrc)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


include_directories(.)



find_package(Qt5 COMPONENTS Widgets REQUIRED)


add_executable(electionSrc
        BallotBox.h
        BallotBox.cpp
        Candidates.h
        Candidates.cpp
        Candidate.h
        Candidate.cpp
        Election.h
        Election.cpp
        electionwizard.cpp
        electionwizard.h
        main.cpp
        )

target_link_libraries(electionSrc Qt5::Widgets)