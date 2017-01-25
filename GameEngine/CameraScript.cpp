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
        t->position -= cameraSpeed * t->getRight();
    if(be->input->keys[GLFW_KEY_D])
        t->position += cameraSpeed * t->getRight();
    
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
    
    
    if (getGO()->name == "camera")
    {
        //glm::vec3 v = getGO()->getTransform()->getFront();
        glm::vec3 v = getGO()->getTransform()->getEulersAngles();
        
        //glm::vec3 v = glm::degrees(glm::eulerAngles(glm::quat(glm::radians(rotation))));
        //cout << v.x << " " << v.y << " " << v.z << "\n";
        //cout << xpos << " " << ypos << endl;
    }
    
    
    
    //t->setEulersAngles(t->getEulersAngles() +  glm::vec3(0,0,45 * be->deltaTime));
    
    
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
