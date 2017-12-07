#include <iostream>
#include "trainings/window.hh"


int main()
{
    Window window;
    GLFWwindow* window_ptr(window.create());

    if(window_ptr == nullptr)
    {
        std::cout << "Ups, something goes wrong!" << std::endl;
        return -1;
    }
    std::cout << "Jupi!" << std::endl;
   
    uint32_t val;
    std::cin >> val;


    return 0;
}
