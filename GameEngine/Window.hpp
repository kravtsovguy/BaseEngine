//
//  Window.hpp
//  GameEngine
//
//  Created by Matvey Kravtsov on 19/01/2017.
//  Copyright © 2017 Matvey Kravtsov. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp

#include "headers.h"

class Window
{
public:
    Window();
    void init(GLint width, GLint height, const string& title);
    GLFWwindow* w;
    string title;
    GLint width, height;
    
private:
    
};

#endif /* Window_hpp */
