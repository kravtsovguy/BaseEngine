//
//  Transform.cpp
//  GameEngine
//
//  Created by Matvey Kravtsov on 19/01/2017.
//  Copyright © 2017 Matvey Kravtsov. All rights reserved.
//

#include "Transform.hpp"

#include "GameObject.hpp"

void Transform::lookAt(glm::vec3 const& center, glm::vec3 const& up)
{
    
    glm::vec3 f = glm::normalize(center - position);
    
    glm::vec3 s = glm::normalize(glm::cross(up, f));
    
    glm::vec3 u = glm::normalize(glm::cross(f, s));
    
    setRotation(s, u, f);
    //qrotation = glm::conjugate(glm::toQuat(glm::lookAt(-position, center, up)));
}

void Transform::setRotation(glm::vec3 const& left, glm::vec3 const& up, glm::vec3 const& front)
{
    setRotation(glm::mat3(left,up,front));
}
void Transform::setRotation(glm::mat3 const& mRot)
{
    qrotation = glm::toQuat(mRot);
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
    return glm::toMat4(qrotation);
    
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
    //return rotation;
    return glm::degrees(glm::eulerAngles(qrotation));
}

void Transform::setEulersAngles(glm::vec3 const& angles)
{
    rotation = angles;
    qrotation = getQuat(angles);
    
}

void Transform::rotate(glm::vec3 const& angles, bool world)
{
    rotation += angles;
    
    if (world)
        qrotation = getQuat(angles) * qrotation;
    else
        qrotation = qrotation * getQuat(angles);
}
glm::quat Transform::getQuat(glm::vec3 const& angles)
{
    using namespace glm;
    
    vec3 ang = radians(angles);
    /*
    quat q;
    q = glm::rotate(q, angles);
    q = glm::rotate(q, angles.y, {0,1,0});
    q = glm::rotate(q, angles.x, {1,0,0});
    q = glm::rotate(q, angles.z, {0,0,1});
    return q;
    */
    quat qPitch  = angleAxis(ang.x, vec3(1, 0, 0));
    quat qYaw    = angleAxis(ang.y, vec3(0, 1, 0));
    quat qRoll   = angleAxis(ang.z, vec3(0, 0, 1));
    
    return qYaw * qPitch * qRoll;
}
