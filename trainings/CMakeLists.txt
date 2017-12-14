
set(SOURCES
    ${CMAKE_SOURCE_DIR}/trainings/WindowCreator.cc
    ${CMAKE_SOURCE_DIR}/trainings/FrameBufferHandler.cc
    ${CMAKE_SOURCE_DIR}/trainings/RenderingLoop.cc
    ${CMAKE_SOURCE_DIR}/trainings/ShaderLoader.cc
    ${CMAKE_SOURCE_DIR}/trainings/Shader.cc
    ${CMAKE_SOURCE_DIR}/trainings/Program.cc
    ${CMAKE_SOURCE_DIR}/trainings/Vao.cc
    ${CMAKE_SOURCE_DIR}/trainings/Vbo.cc
    ${CMAKE_SOURCE_DIR}/trainings/Ebo.cc
    ${CMAKE_SOURCE_DIR}/trainings/VaoWithVbo.cc
    ${CMAKE_SOURCE_DIR}/trainings/Uniform.cc
    )

add_library(trainings STATIC ${SOURCES})
