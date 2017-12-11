#include <iostream>

#include <glad/glad.h>
#include "trainings/WindowCreator.hh"
#include "trainings/FrameBufferHandler.hh"
#include "trainings/RenderingLoop.hh"
#include "trainings/ShaderLoader.hh"



uint32_t create_shader(const std::string& shader_path, const GLenum shader_type)
{
   
    ShaderLoader sl;
    std::string s = sl.load(shader_path);
    uint32_t shader_id = 0;
    shader_id = glCreateShader(shader_type);
    const char* ps = s.c_str();
    glShaderSource(shader_id, 1, &ps, nullptr);
    glCompileShader(shader_id);

    int32_t status = 0;
    char info_log[512];
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &status);
    if(0 == status)
    {
        glGetShaderInfoLog(shader_id, 512, nullptr, info_log);
        std::cout << "Shader compilation error: " << info_log << std::endl;
    }
    return shader_id;
}


int main()
{
    constexpr uint32_t width = 800;
    constexpr uint32_t height = 600;
 
    WindowCreator w_creator;
    GLFWwindow* window(w_creator.create(width, height));

    if(nullptr == window)
    {
        std::cerr << "Ups, something goes wrong!" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Cannot initialize GLAD!" << std::endl;
        glfwTerminate();
        return -1;
    }
     
    constexpr uint32_t left_bottom_x = 0;
    constexpr uint32_t left_bottom_y = 0;
    glViewport(left_bottom_x, left_bottom_y, width, height);

    glfwSetFramebufferSizeCallback(window, FrameBufferHandler::framebuffer_size_callback);

    const uint32_t vertex_shader_id = create_shader("/home/reczek/opengl_learning/trainings/shaders/triangle.vs", GL_VERTEX_SHADER);
    const uint32_t fragment_shader_id = create_shader("/home/reczek/opengl_learning/trainings/shaders/triangle.fs", GL_FRAGMENT_SHADER);
   
    uint32_t shader_program_id = glCreateProgram();
    glAttachShader(shader_program_id, vertex_shader_id);
    glAttachShader(shader_program_id, fragment_shader_id);
    glLinkProgram(shader_program_id);

    char info_log[512];
    int32_t status = 0;
    glGetProgramiv(shader_program_id, GL_LINK_STATUS, &status);
    if(0 == status)
    {
        glGetProgramInfoLog(shader_program_id, 512, nullptr, info_log);
        std::cout << "Linking errog: "<< info_log << std::endl;
    }

    glDeleteShader(vertex_shader_id);
    glDeleteShader(fragment_shader_id);
    float vertices [] = {-0.5f, -0.5f, 0.0f,
                         0.5f, -0.5f, 0.0f,
                         0.0f, 0.5f, 0.0f};
    uint32_t vao = 0;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    uint32_t vbo = 0;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    RenderingLoop rl;
    rl.run( window, shader_program_id, vao );

    glfwTerminate();
    return 0;
}
