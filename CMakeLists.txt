cmake_minimum_required(VERSION 2.6)

set(CMAKE_C_COMPILER /usr/bin/clang-5.0)
set(CMAKE_CXX_COMPILER /usr/bin/clang++-5.0)
set(CMAKE_CXX_FLAGS "-Werror -pedantic -std=c++14")
set(CMAKE_EXE_LINKER_FLAG "")

project(opengl_learning)

link_directories(${CMAKE_SOURCE_DIR}/lib)
link_directories(/usr/lib/x86_64-linux-gnu )
link_directories(/usr/lib/nvidia-384)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCES
    ${SOURCES}
    ${CMAKE_SOURCE_DIR}/main.cc
    ${CMAKE_SOURCE_DIR}/glad/glad.c
    ${CMAKE_SOURCE_DIR}/trainings/WindowCreator.cc
    ${CMAKE_SOURCE_DIR}/trainings/FrameBufferHandler.cc
    ${CMAKE_SOURCE_DIR}/trainings/RenderingLoop.cc
    ${CMAKE_SOURCE_DIR}/trainings/ShaderLoader.cc
    )

add_executable(opengl_learning ${SOURCES})

target_link_libraries(opengl_learning glfw3)
target_link_libraries(opengl_learning dl)
target_link_libraries(opengl_learning pthread)
target_link_libraries(opengl_learning X11)
target_link_libraries(opengl_learning Xi)
target_link_libraries(opengl_learning Xrandr)
target_link_libraries(opengl_learning Xxf86vm )
target_link_libraries(opengl_learning GL)


