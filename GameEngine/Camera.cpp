//
//  Camera.cpp
//  GameEngine
//
//  Created by Matvey Kravtsov on 19/01/2017.
//  Copyright © 2017 Matvey Kravtsov. All rights reserved.
//

#include "Camera.hpp"
#include "BaseEngine.hpp"

glm::mat4 Camera::getViewMatrix()
{
    
    Transform* t = getGO()->getTransform();
    
    glm::mat4 m = t->getRotationMatrix();
    m[0] = -m[0];
    m[2] = -m[2];
    return glm::inverse(t->getTranslationMatrix() * m);
    
    /*
    glm::vec3 p = getGO()->getTransform()->position;
    glm::vec3 f = getGO()->getTransform()->getFront();
    glm::vec3 u = getGO()->getTransform()->getUp();
    glm::mat4 view = glm::lookAt(p, p + f, u);
    return view;
     */
    
}

glm::mat4 Camera::getProjectionMatrix()
{
    glm::mat4 proj = glm::perspective(glm::radians(45.0f), ratio, 0.1f, 100.0f);
    return proj;
}

glm::mat4 Camera::getMatrix()
{
    return getProjectionMatrix() * getViewMatrix();
}
 
