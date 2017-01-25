//
//  UserScript.hpp
//  GameEngine
//
//  Created by Matvey Kravtsov on 22/01/2017.
//  Copyright © 2017 Matvey Kravtsov. All rights reserved.
//

#ifndef UserScript_hpp
#define UserScript_hpp

#include "BaseEngine.hpp"

class UserScript : public Component
{
    virtual void start();
    virtual void update();
};

#endif /* UserScript_hpp */
