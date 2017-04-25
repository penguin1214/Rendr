cmake_minimum_required(VERSION 3.6)
project(Rendr)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp math.cpp math.h model.cpp model.h)

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS})

add_executable(Rendr ${SOURCE_FILES})

target_link_libraries(Rendr ${GLFW_LIBRARIES})
target_link_libraries(Rendr ${GLFW_STATIC_LIBRARIES})