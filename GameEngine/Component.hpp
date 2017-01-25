//
//  Component.hpp
//  GameEngine
//
//  Created by Matvey Kravtsov on 19/01/2017.
//  Copyright © 2017 Matvey Kravtsov. All rights reserved.
//

#ifndef Component_hpp
#define Component_hpp

#include "headers.h"
class GameObject;

class Component
{

public:
    virtual void start(){}
    virtual void update(){}
    bool enabled = true;
    GameObject* getGO()
    {
        return _go;
    }
    void setGO(GameObject* go)
    {
        _go = go;
    }
    
private:
    GameObject* _go;
};

#endif /* Component_hpp */
