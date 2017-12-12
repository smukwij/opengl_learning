#include <fstream>
#include <sstream>
#include <iostream>

#include "ShaderLoader.hh"


namespace 
{
    std::string get_shaders_path()
    {
        return "/home/reczek/opengl_learning/trainings/shaders/";
    }
}




std::string ShaderLoader::load(const std::string& file_name)
{
    std::ifstream file(get_shaders_path() + file_name);

    if(true == file.is_open())
    {
        std::ostringstream oss;
        oss << file.rdbuf();
        std::cout << oss.str() << std::endl;
        return oss.str();
    }
    else
    {
        std::cout << "bad" << std::endl;
    }
    return "";
}

