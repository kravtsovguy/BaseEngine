//
//  Transform.cpp
//  GameEngine
//
//  Created by Matvey Kravtsov on 19/01/2017.
//  Copyright © 2017 Matvey Kravtsov. All rights reserved.
//

#include "Transform.hpp"

#include "GameObject.hpp"

void Transform::lookAt(glm::vec3 center, glm::vec3 worldUp)
{
    /*
    glm::vec3 front = center - position;
    
    glm::vec3 right = glm::normalize(glm::cross(worldUp, front));
    
    glm::vec3 up = glm::normalize(glm::cross(front, right));
    
     */
    
    //setFront(front);
    //setUp(up);
    //setRight(right);
    
    //glm::quat q = glm::toQuat(glm::mat3(right,up,front));
    
    //glm::mat3 m = {right,up,front};
    //glm::quat q = glm::conjugate(glm::toQuat(glm::lookAt(position, center, up)));
    //rotation = glm::degrees(glm::eulerAngles(q));
    
    
}

glm::vec3 Transform::getLeft()
{
    return getRotationMatrix()[0];
}

glm::vec3 Transform::getUp()
{
    return getRotationMatrix()[1];
}

glm::vec3 Transform::getFront()
{
    return getRotationMatrix()[2];
}
glm::mat4 Transform::getTranslationMatrix()
{
    return glm::translate(position);
}

glm::mat4 Transform::getRotationMatrix()
{
    //return glm::toMat4(qrotation);
    
    glm::mat4 rX = glm::rotate(glm::radians(rotation[0]), glm::vec3(1.0f, 0.0f, 0.0f));
    glm::mat4 rY = glm::rotate(glm::radians(rotation[1]), glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 rZ = glm::rotate(glm::radians(rotation[2]), glm::vec3(0.0f, 0.0f, 1.0f));
              
    if (getGO()->name == "user" && /* DISABLES CODE */ (false))
    {
        glm::mat4 m = rY * rX * rZ;
        cout << m[0][0] << " " << m[1][0] << " " << m[2][0] << endl;
        cout << m[0][1] << " " << m[1][1] << " " << m[2][1] << endl;
        cout << m[0][2] << " " << m[1][2] << " " << m[2][2] << endl;
        cout << "----------------------------------" << endl;
    }
    
    return rY * rX * rZ;
}


glm::mat4 Transform::getScaleMatrix()
{
    return glm::scale(scale);
}

glm::mat4 Transform::getModelMatrix()
{
    return getTranslationMatrix() * getRotationMatrix() * getScaleMatrix();
}

glm::vec3 Transform::getEulersAngles()
{
    return rotation;
    //return glm::degrees(glm::eulerAngles(qrotation));
}

void Transform::setEulersAngles(glm::vec3 angles)
{
    rotation = angles;
    /*
    glm::quat qPitch = glm::angleAxis(glm::radians(angles.x), glm::vec3(1, 0, 0));
    glm::quat qYaw = glm::angleAxis(glm::radians(angles.y), glm::vec3(0, 1, 0));
    glm::quat qRoll = glm::angleAxis(glm::radians(angles.z),glm::vec3(0,0,1));
    qrotation = qYaw * qPitch * qRoll;
     */
}
