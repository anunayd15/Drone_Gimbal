cmake_minimum_required(VERSION 3.23)

project(DroneGimbal
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Python Virtual Environment

set(Python3_EXECUTABLE
    "${CMAKE_CURRENT_SOURCE_DIR}/../.venv/Scripts/python.exe"
)

find_package(Python3 REQUIRED COMPONENTS Interpreter)


# MAVLink 

set(MAVLINK_DIR
    "${CMAKE_CURRENT_SOURCE_DIR}/../mavlink"
)

set(MAVLINK_GENERATED_DIR
    "${CMAKE_CURRENT_BINARY_DIR}/generated/mavlink"
)

# Generate MAVLink C Headers
add_custom_command(
    OUTPUT
        "${MAVLINK_GENERATED_DIR}/common/mavlink.h"
    
    COMMAND
        "${Python3_EXECUTABLE}"
        -m pymavlink.tools.mavgen
        --lang=C
        --wire-protocol=2.0
        --output="${MAVLINK_GENERATED_DIR}"
        "${MAVLINK_DIR}/message_definitions/v1.0/common.xml"

    DEPENDS
        "${MAVLINK_DIR}/message_definitions/v1.0/common.xml"
    
    COMMENT
        "Generating MAVLink C headers"
)

add_custom_target(generate_mavlink
    DEPENDS
        "${MAVLINK_GENERATED_DIR}/common/mavlink.h"
)

# Application

add_executable(
    DroneGimbal
    # cplus_files/test.cpp
    cplus_files/main.cpp
    cplus_files/MavlinkHandler.cpp
    cplus_files/GimbalController.cpp
)

add_dependencies(
    DroneGimbal
    generate_mavlink
)

    target_include_directories(
        DroneGimbal
        PRIVATE
            "${MAVLINK_GENERATED_DIR}"
            "${CMAKE_CURRENT_SOURCE_DIR}/cplus_files"
    )