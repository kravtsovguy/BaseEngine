//
//  CameraScript.cpp
//  GameEngine
//
//  Created by Matvey Kravtsov on 20/01/2017.
//  Copyright © 2017 Matvey Kravtsov. All rights reserved.
//

#include "CameraScript.hpp"

void CameraScript::update()
{
    BaseEngine* be = &BaseEngine::shared();
    Transform* t = getGO()->getTransform();

    GLfloat cameraSpeed = 5.0f * be->deltaTime;
    if(be->input->keys[GLFW_KEY_W])
        t->position += cameraSpeed * t->getFront();
    if(be->input->keys[GLFW_KEY_S])
        t->position -= cameraSpeed * t->getFront();
    if(be->input->keys[GLFW_KEY_A])
        t->position += cameraSpeed * t->getLeft();
    if(be->input->keys[GLFW_KEY_D])
        t->position -= cameraSpeed * t->getLeft();
    
    double xpos = be->input->xpos;
    double ypos = be->input->ypos;
    
    if(lastX < 0.01 && lastY < 0.01)
    {
        lastX = xpos;
        lastY = ypos;
    }
    
    
    GLfloat xoffset = lastX - xpos;
    GLfloat yoffset = ypos - lastY;
    lastX = xpos;
    lastY = ypos;
    
    t->setEulersAngles(t->getEulersAngles() + sensitivity * glm::vec3(yoffset,xoffset,0));
    
    glm::vec3 rot = t->getEulersAngles();
    
    if (rot.x > 89.0f)
        rot.x = 89;
    
    if (rot.x < -89.0f)
        rot.x = -89;
    
    if (glm::abs(rot.y) > 360)
        rot.y = 0;
    
    t->setEulersAngles(rot);
     
}
