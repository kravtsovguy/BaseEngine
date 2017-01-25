//
//  Input.cpp
//  GameEngine
//
//  Created by Matvey Kravtsov on 19/01/2017.
//  Copyright © 2017 Matvey Kravtsov. All rights reserved.
//

#include "Input.hpp"

Input* current;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    std::cout << key << std::endl;
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    
    if(action == GLFW_PRESS)
        current->keys[key] = true;
    else if(action == GLFW_RELEASE)
        current->keys[key] = false;
    
    
     for (int i = 0; i < current->keyCallback.size(); i++)
     {
         current->keyCallback[i](current->keys);
     }
    
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    current->xpos = xpos;
    current->ypos = ypos;
    
    for (int i = 0; i < current->cursorposCallback.size(); i++)
    {
        current->cursorposCallback[i](xpos, ypos);
    }
    
}


Input::Input(Window* window)
{
    current = this;
    glfwSetKeyCallback(window->w, key_callback);
    glfwSetCursorPosCallback(window->w, mouse_callback);
}
