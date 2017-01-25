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
    
    Camera(GLfloat ratio)
    {
        this->ratio = ratio;
    }
    GLfloat ratio;
    GLfloat fov = 45.0f;
    GLfloat znear = 0.1f;
    GLfloat zfar = 100.0f;
    glm::mat4 getViewMatrix();
    glm::mat4 getProjectionMatrix();
    glm::mat4 getMatrix();
};

#endif /* Camera_hpp */
