#pragma once

#include <string>
#include <glad/glad.h>



class Shader
{
    public:
        Shader();
        ~Shader();
        void create(const std::string& file_name, const GLenum shader_type);
        void destroy(); 

        uint32_t get_id() const;

    private:
        uint32_t _id;
};
