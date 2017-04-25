cmake_minimum_required(VERSION 3.6)
project(Rendr)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXE_LINKER_FLAGS
        "-framework SDL2"
        )

set(SOURCE_FILES src/main.cpp math.cpp math.h model.cpp model.h src/window.h)
add_executable(Rendr ${SOURCE_FILES})