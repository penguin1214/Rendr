cmake_minimum_required(VERSION 3.6)
project(Rendr)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/math.cpp src/math.h src/model.cpp src/model.h src/window.cpp src/window.h src/renderer.h src/ray_tracer.cpp src/ray_tracer.h)
set(CMAKE_EXE_LINKER_FLAGS "-framework OpenGL")

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS})

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARIES})

add_executable(Rendr ${SOURCE_FILES})

target_link_libraries(Rendr ${GLFW_LIBRARIES})
target_link_libraries(Rendr ${GLFW_STATIC_LIBRARIES})