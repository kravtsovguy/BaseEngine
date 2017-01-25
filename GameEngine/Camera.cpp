//
//  Camera.cpp
//  GameEngine
//
//  Created by Matvey Kravtsov on 19/01/2017.
//  Copyright © 2017 Matvey Kravtsov. All rights reserved.
//

#include "Camera.hpp"
#include "BaseEngine.hpp"


void Camera::start()
{
    
}

//bool firstMouse;
//double lastX, lastY, yaw = -90, pitch = 0;
void Camera::update ()
{
    //cameraPos = getGO()->getTransform()->position;
    //cameraFront = getGO()->getTransform()->getFront();
    /*
    BaseEngine* be = &BaseEngine::shared();
    Camera* c = be->camera;
    
    GLfloat cameraSpeed = 5.0f * be->deltaTime;
    if(be->input->keys[GLFW_KEY_W])
        c->cameraPos += cameraSpeed * c->cameraFront;
    if(be->input->keys[GLFW_KEY_S])
        c->cameraPos -= cameraSpeed * c->cameraFront;
    if(be->input->keys[GLFW_KEY_A])
        c->cameraPos -= glm::normalize(glm::cross(c->cameraFront, c->cameraUp)) * cameraSpeed;
    if(be->input->keys[GLFW_KEY_D])
        c->cameraPos += glm::normalize(glm::cross(c->cameraFront, c->cameraUp)) * cameraSpeed;
    
    double xpos = be->input->xpos;
    double ypos = be->input->ypos;
    
    if(firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
        return;
    }
    
    GLfloat xoffset = xpos - lastX;
    GLfloat yoffset = lastY - ypos;
    lastX = xpos;
    lastY = ypos;
    
    GLfloat sensitivity = 0.05;
    xoffset *= sensitivity;
    yoffset *= sensitivity;
    
    yaw   += xoffset;
    pitch += yoffset;
    
    if(pitch > 89.0f)
        pitch = 89.0f;
    if(pitch < -89.0f)
        pitch = -89.0f;
    
    if (glm::abs(yaw) > 360) yaw = 0;
    
    
    //cout << yaw << " " << pitch << "\n";
    
    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    be->camera->cameraFront = glm::normalize(front);
     */
}


glm::mat4 Camera::getViewMatrix()
{
    
    glm::vec3 p = getGO()->getTransform()->position;
    glm::vec3 f = getGO()->getTransform()->getFront();
    glm::vec3 u = getGO()->getTransform()->getUp();
    glm::vec3 r = getGO()->getTransform()->getRight();
    Transform* t = getGO()->getTransform();
    
    glm::mat4 m = t->getRotationMatrix();
    m[0] = -m[0];
    m[2] = -m[2];
    return glm::inverse(t->getTranslationMatrix() * m);
    //return glm::inverse(t->getModelMatrix());
    //glm::mat4 view =  t->getRotationMatrix() * glm::translate(-t->position);
    //glm::mat4 view = glm::lookAt(p, p + f, cameraUp);
    
    glm::vec3 zaxis = -f;//normal(eye - target);    // The "forward" vector.
    glm::vec3 xaxis = r;//glm::normalize(cross(u, zaxis));// The "right" vector.
    glm::vec3 yaxis = u;//glm::cross(zaxis, xaxis);     // The "up" vector.
    
    glm::mat4 orientation = {
        glm::vec4( xaxis.x, yaxis.x, zaxis.x, 0 ),
        glm::vec4( xaxis.y, yaxis.y, zaxis.y, 0 ),
        glm::vec4( xaxis.z, yaxis.z, zaxis.z, 0 ),
        glm::vec4(   0,       0,       0,     1 )
    };
    
    orientation = {
        glm::vec4(xaxis,0),
        glm::vec4(yaxis,0),
        glm::vec4(zaxis,0),
        glm::vec4(0,0,0,1)};
    
    //glm::mat4 view = orientation * glm::translate(-t->position);
    
    glm::mat4 view = glm::inverse(t->getTranslationMatrix() * orientation);
    //glm::mat4 view = glm::translate(-t->position) * glm::toMat4(glm::toQuat(glm::lookAt(p, p + f, cameraUp)));
    
    //glm::mat4 view = glm::lookAt(p, p + f, u);
    
    return view;
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

void Camera::fly(bool isEnable)
{
    enabled = isEnable;
    /*if (isEnable)
    {
        BaseEngine::shared().updateCallback.push_back(update);
    }else{
        BaseEngine::shared().removeCallback(update);
    }*/
}
 
