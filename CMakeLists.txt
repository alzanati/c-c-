# project name
project(DesignPatterns)

# minimum version
cmake_minimum_required(VERSION 2.8)

# add support of c++11
add_definitions(-std=c++11)

# add source files
aux_source_directory(. SRC_LIST)

# include FactoryMethod
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/FactoryMethod)
file(GLOB_RECURSE FACTORY_METHOD FactoryMethod.h)
add_library(FACT_METHOD SHARED ${FACTORY_METHOD} ${SRC_LIST})

# include Singelton
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Singelton)
file(GLOB_RECURSE SINGELTON Singelton.h)
add_library(SING SHARED ${SINGELTON} ${SRC_LIST})

# compile and generate exe
add_executable(${PROJECT_NAME} ${SING} ${FACT_METHOD} ${SRC_LIST})
