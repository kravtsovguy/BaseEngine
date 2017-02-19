//
//  Transform.cpp
//  GameEngine
//
//  Created by Matvey Kravtsov on 19/01/2017.
//  Copyright © 2017 Matvey Kravtsov. All rights reserved.
//

#include "Transform.hpp"

void Transform::lookAt(glm::vec3 const& center, glm::vec3 const& up)
{
    glm::vec3 f = glm::normalize(center - position);
    glm::vec3 s = glm::normalize(glm::cross(up, f));
    glm::vec3 u = glm::normalize(glm::cross(f, s));
    
    setRotation(s, u, f);
}

void Transform::setRotation(glm::vec3 const& right, glm::vec3 const& up, glm::vec3 const& front)
{
    setRotation(glm::mat3(right,up,front));
}

void Transform::setRotation(glm::mat3 const& mRot)
{
    qrotation = glm::toQuat(mRot);
}

glm::vec3 Transform::getRight()
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
    if (position == _pos)
        return _mTrans;
    
    _pos = position;
    _mTrans = glm::translate(position);
    return _mTrans;
}

glm::mat4 Transform::getRotationMatrix()
{
    if (qrotation == _rot)
        return _mRot;
    
    _rot = qrotation;
    _mRot = glm::toMat4(qrotation);
    return _mRot;
}


glm::mat4 Transform::getScaleMatrix()
{
    if (scale == _scale)
        return _mScale;
    
    _scale = scale;
    _mScale = glm::scale(scale);
    return _mScale;
}

glm::mat4 Transform::getModelMatrix()
{
    if (position == _pos && scale == _scale && qrotation == _rot)
        return _mModel;
    
    _mModel = getTranslationMatrix() * getRotationMatrix() * getScaleMatrix();
    return _mModel;
}

glm::vec3 Transform::getEulersAngles()
{
    return glm::degrees(glm::eulerAngles(qrotation));
}

void Transform::setEulersAngles(glm::vec3 const& angles)
{
    qrotation = getQuat(angles);
}

void Transform::rotate(glm::vec3 const& angles, bool world)
{
    if (world)
        qrotation = getQuat(angles) * qrotation;
    else
        qrotation = qrotation * getQuat(angles);
}
glm::quat Transform::getQuat(glm::vec3 const& angles)
{
    glm::vec3 ang = glm::radians(angles);
    glm::quat qPitch  = glm::angleAxis(ang.x, glm::vec3(1, 0, 0));
    glm::quat qYaw    = glm::angleAxis(ang.y, glm::vec3(0, 1, 0));
    glm::quat qRoll   = glm::angleAxis(ang.z, glm::vec3(0, 0, 1));
    
    return qYaw * qPitch * qRoll;
}
