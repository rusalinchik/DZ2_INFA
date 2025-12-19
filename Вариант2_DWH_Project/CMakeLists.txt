cmake_minimum_required(VERSION 3.10)

project(DWH_Project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

find_package(PostgreSQL REQUIRED)

set(SOURCES
    src/main.cpp
    src/Database.cpp
    src/CSVReader.cpp
    src/DateUtils.cpp
    src/ETLProcessor.cpp
)

add_executable(dwh_app ${SOURCES})

target_link_libraries(dwh_app PostgreSQL::PostgreSQL)
