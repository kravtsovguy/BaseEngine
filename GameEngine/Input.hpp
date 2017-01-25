//
//  Input.hpp
//  GameEngine
//
//  Created by Matvey Kravtsov on 19/01/2017.
//  Copyright © 2017 Matvey Kravtsov. All rights reserved.
//

#ifndef Input_hpp
#define Input_hpp

#include "headers.h"
#include "Window.hpp"

typedef void (* BEkeyfun)(const bool *keys);
typedef void (* BEcursorposfun)(double xpos, double ypos);

class Input
{
public:
    Input(Window* window);
    vector<BEkeyfun> keyCallback;
    vector<BEcursorposfun> cursorposCallback;
    double xpos,ypos;
    bool keys[2014] = {false};
};

#endif /* Input_hpp */
