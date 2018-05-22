cmake_minimum_required(VERSION 2.8)

project(ServerApp)


file(GLOB SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
        [^.]*.cpp
        [^.]*.h
        [^.]*.cmake
        )

add_executable(${PROJECT_NAME} ${SOURCES})
