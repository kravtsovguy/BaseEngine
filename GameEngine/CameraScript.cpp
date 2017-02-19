//
//  CameraScript.cpp
//  GameEngine
//
//  Created by Matvey Kravtsov on 20/01/2017.
//  Copyright © 2017 Matvey Kravtsov. All rights reserved.
//

#include "CameraScript.hpp"

using namespace std;

void CameraScript::start()
{
    //BaseEngine* be = &BaseEngine::shared();
    Transform* t = getGO()->getTransform();
    
    //t->position = {3,3,3};
    //t->setEulersAngles({0,180,0});
    
    t->position = {3,3,-1};
    //t->setEulersAngles({ 45, 180 + 45,0});
    t->lookAt({0,0,0});
}

void CameraScript::update()
{
    BaseEngine* be = &BaseEngine::shared();
    Transform* t = getGO()->getTransform();
    
    auto v = t->getEulersAngles();
    cout << v.x << " " << v.y << " " << v.z << std::endl;

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
    
    
    GLfloat xoffset = xpos - lastX;
    GLfloat yoffset = ypos - lastY;
    lastX = xpos;
    lastY = ypos;

    t->rotate(sensitivity * glm::vec3(yoffset,0,0));
    t->rotate(sensitivity * glm::vec3(0,xoffset,0),true);
}
