# project name
project(DesignPatterns)

# minimum version
cmake_minimum_required(VERSION 2.8)

# add support of c++11
add_definitions(-std=c++11)

# add header files
set(HEADERS FactoryMethod.h)

# add source files
aux_source_directory(. SRC_LIST)

# compile and generate exe
add_executable(${PROJECT_NAME} ${HEADERS} ${SRC_LIST})

