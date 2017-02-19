//
//  Camera.hpp
//  GameEngine
//
//  Created by Matvey Kravtsov on 19/01/2017.
//  Copyright © 2017 Matvey Kravtsov. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#include "headers.h"
#include "Component.hpp"

class Camera : public Component
{
public:
    glm::mat4 getViewMatrix();
    glm::mat4 getProjectionMatrix();
    glm::mat4 getMatrix();
    virtual bool isOrtho() = 0;
    
protected:
    virtual glm::mat4 calcProjectionMatrix() = 0;
    glm::mat4 _mProj;
    glm::mat4 _mView;
    glm::mat4 _mModel;
};

#endif /* Camera_hpp */
