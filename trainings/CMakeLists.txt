
set(SOURCES
    ${CMAKE_SOURCE_DIR}/trainings/WindowCreator.cc
    ${CMAKE_SOURCE_DIR}/trainings/FrameBufferHandler.cc
    ${CMAKE_SOURCE_DIR}/trainings/RenderingLoop.cc
    ${CMAKE_SOURCE_DIR}/trainings/ShaderLoader.cc
    )

add_library(trainings STATIC ${SOURCES})
