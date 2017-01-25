//
//  CameraScript.hpp
//  GameEngine
//
//  Created by Matvey Kravtsov on 20/01/2017.
//  Copyright © 2017 Matvey Kravtsov. All rights reserved.
//

#ifndef CameraScript_hpp
#define CameraScript_hpp

#include "BaseEngine.hpp"

class CameraScript : public Component
{
    virtual void update();
    
public:
    GLfloat sensitivity = 0.05f;
    
private:
    double lastX = 0, lastY = 0;
};


#endif /* CameraScript_hpp */
