cmake_minimum_required(VERSION 3.23)

project(DroneGimbalController
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(DroneGimbalController
    cplus_files/test.cpp
)