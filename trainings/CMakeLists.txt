
set(SOURCES
    ${CMAKE_SOURCE_DIR}/trainings/RenderingLoop.cc
    ${CMAKE_SOURCE_DIR}/trainings/WindowCreator.cc
    ${CMAKE_SOURCE_DIR}/trainings/FirstObject.cc
    ${CMAKE_SOURCE_DIR}/trainings/utils/FrameBufferHandler.cc
    ${CMAKE_SOURCE_DIR}/trainings/utils/ShaderLoader.cc
    ${CMAKE_SOURCE_DIR}/trainings/utils/Shader.cc
    ${CMAKE_SOURCE_DIR}/trainings/utils/Program.cc
    ${CMAKE_SOURCE_DIR}/trainings/utils/Vao.cc
    ${CMAKE_SOURCE_DIR}/trainings/utils/Vbo.cc
    ${CMAKE_SOURCE_DIR}/trainings/utils/Ebo.cc
    ${CMAKE_SOURCE_DIR}/trainings/utils/VaoWithVbo.cc
    ${CMAKE_SOURCE_DIR}/trainings/utils/Uniform.cc
    ${CMAKE_SOURCE_DIR}/trainings/utils/Image.cc
    ${CMAKE_SOURCE_DIR}/trainings/utils/Texture.cc
    )

add_library(trainings STATIC ${SOURCES})
target_link_libraries(trainings stb_image)

