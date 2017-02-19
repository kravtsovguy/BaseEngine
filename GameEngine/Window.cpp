//
//  Window.cpp
//  GameEngine
//
//  Created by Matvey Kravtsov on 19/01/2017.
//  Copyright © 2017 Matvey Kravtsov. All rights reserved.
//

#include "Window.hpp"


Window::Window()
{
    std::cout << "Starting GLFW context, OpenGL 3.3" << std::endl;

    if(!glfwInit())
    {
        exit(EXIT_FAILURE);
    }
    
#ifdef __APPLE__
    // Select OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
#else
    // Select OpenGL 4.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
#endif
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
}

void Window::init(GLint width, GLint height, const std::string& title)
{
    this->width = width;
    this->height = height;
    this->title = title;
    
    w = glfwCreateWindow(width,height,title.c_str(), nullptr, nullptr);
    if (w == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(w);
    
    glfwSwapInterval(1);
    
    int widthG, heightG;
    glfwGetFramebufferSize(w, &widthG, &heightG);
    glViewport(0, 0, widthG, heightG);
    
    glfwSetInputMode(w, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}
