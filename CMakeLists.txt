cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDART 11)
include(cmake/HunterGate.cmake)

HunterGate(URL "https://github.com/nex-7/hunter/archive/v0.19.137.1.tar.gz" SHA1 "0a8badad8c0112ce52a81fb1f20f8585803265b6")

project(xml)

hunter_add_package(pugixml)
find_package(pugixml CONFIG REQUIRED)

add_executable(pack ${CMAKE_CURRENT_SOURCE_DIR}/sources/pack.cpp)
target_link_libraries(pack pugixml)
add_executable(unpack ${CMAKE_CURRENT_SOURCE_DIR}/sources/unpack.cpp)
target_link_libraries(unpack pugixml)
