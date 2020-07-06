cmake_minimum_required(VERSION 3.16)
project(Quaternion)

set(CMAKE_CXX_STANDARD 14)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.45.0 COMPONENTS regex)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(quaternion main.cpp complex.cpp complex.h quaternion.cpp quaternion.h imagine.cpp imagine.h)
    target_link_libraries(quaternion ${Boost_LIBRARIES})
endif()