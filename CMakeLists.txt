cmake_minimum_required(VERSION 3.6)
project(Rendr)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/model.cpp src/model.h src/window.cpp src/window.h src/renderer.h src/ray_tracer.cpp src/ray_tracer.h src/CGL/svgparser.cpp src/CGL/svgparser.h src/CGL/tinyxml2.cpp src/CGL/tinyxml2.h src/CGL/svg.cpp src/CGL/svg.h src/CGL/color.cpp src/CGL/color.h src/math/vector2D.cpp src/math/vector2D.h src/math/vector3D.cpp src/math/vector3D.h src/math/vector4D.cpp src/math/vector4D.h src/math/matrix3x3.cpp src/math/matrix3x3.h src/texture.cpp src/texture.h src/CGL/base64.cpp src/CGL/base64.h src/CGL/lodepng.cpp src/CGL/lodepng.h src/math/transform.cpp src/math/transform.h src/CGL/misc.h src/math/triangulation.cpp src/math/triangulation.h src/CGL/triangulation.cpp src/CGL/triangulation.h)
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