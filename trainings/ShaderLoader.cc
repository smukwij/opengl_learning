#include <fstream>
#include <sstream>
#include <iostream>

#include "ShaderLoader.hh"



std::string ShaderLoader::load(const std::string& path)
{
    std::ifstream file(path);

    std::cout << path << std::endl;

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

