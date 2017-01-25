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
    glm::vec3 front = center - position;
    
    glm::vec3 right = glm::normalize(glm::cross(worldUp, front));
    
    glm::vec3 up = glm::normalize(glm::cross(front, right));
    
    //setFront(front);
    //setUp(up);
    //setRight(right);
    
    //glm::quat q = glm::toQuat(glm::mat3(right,up,front));
    //rotation = glm::eulerAngles(q);
    //setRotation(q);
    
    //glm::mat3 m = {right,up,front};
    //glm::quat q = glm::conjugate(glm::toQuat(glm::lookAt(position, center, up)));
    //rotation = glm::degrees(glm::eulerAngles(q));
    
    
}

glm::vec3 Transform::getLeft()
{
    return getRotationMatrix()[0];
}

glm::vec3 Transform::getRight()
{
    return -getRotationMatrix()[0];
    //return glm::quat(glm::radians(rotation)) * glm::vec3(1,0,0);
    //return  -glm::normalize( getRotationMatrix() * glm::vec4(1,0,0,0) );
}

glm::vec3 Transform::getUp()
{
    return getRotationMatrix()[1];
    return glm::normalize( getRotationMatrix() * glm::vec4(0,1,0,0) );;
}

glm::vec3 Transform::getFront()
{
    return getRotationMatrix()[2];
    
    if (getGO()->name == "camera")
    {
        //cout << rotation[0] << " " << rotation[1] << " " << rotation[2] << endl;
        //cout << m[3].x << " " << m[3].y << " " << m[3].z << "\n";
    }
    
    
    return glm::normalize( getRotationMatrix() * glm::vec4(0,0,1,0) );
    //return glm::quat(glm::radians(rotation)) * glm::vec3(0,0,1);
    glm::mat4 m = glm::transpose(getModelMatrix());
    
    
    //return glm::normalize( glm::vec3(m[2]));
    //return glm::normalize( getRotationMatrix() * glm::vec4(0,0,1,0) );
}
glm::mat4 Transform::getTranslationMatrix()
{
    return glm::translate(position);
}

glm::mat4 Transform::getRotationMatrix()
{
    //return glm::toMat4(qrotation);
    
    //return glm::toMat4(glm::quat(glm::radians(rotation)));
    
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
    
    /*
    if (rot != model)
    {
        //cout << "0\n";
    }else{
        //cout << "1\n";
    }
     */
    
}


glm::mat4 Transform::getScaleMatrix()
{
    return glm::scale(scale);
}

glm::mat4 Transform::getModelMatrix()
{
    
    if (getGO()->name == "camera")
    {
        glm::mat4 m = getTranslationMatrix() * getRotationMatrix() * getScaleMatrix();
        
        //glm::vec3 v = glm::degrees(glm::eulerAngles(glm::quat(glm::radians(rotation))));
        //cout << v.x << " " << v.y << " " << v.z << "\n";
    }
    
    return getTranslationMatrix() * getRotationMatrix() * getScaleMatrix();
    /*
    glm::mat4 model;
    
    model = glm::translate(model, position);
    
    //glm::quat q = glm::quat(glm::radians(rotation));
    //glm::mat4 rot = model * glm::toMat4(q);
    //model = rot;
    
    
    //model = glm::rotate(model, 2 * glm::acos(q.w), glm::vec3(q.x,q.y,q.z));
    
    model = glm::rotate(model, glm::radians(rotation[0]), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(rotation[1]), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(rotation[2]), glm::vec3(0.0f, 0.0f, 1.0f));
    

    
    model = glm::scale(model, scale);
    
    
    
    return model;
    */
}

glm::vec3 Transform::getEulersAngles()
{
    return rotation;
    //return glm::degrees(glm::eulerAngles(qrotation));
}

static glm::quat toQuaternion(double pitch, double roll, double yaw)
{
    glm::quat q;
    double t0 = std::cos(yaw * 0.5f);
    double t1 = std::sin(yaw * 0.5f);
    double t2 = std::cos(roll * 0.5f);
    double t3 = std::sin(roll * 0.5f);
    double t4 = std::cos(pitch * 0.5f);
    double t5 = std::sin(pitch * 0.5f);
    
    q.w = t0 * t2 * t4 + t1 * t3 * t5;
    q.x = t0 * t3 * t4 - t1 * t2 * t5;
    q.y = t0 * t2 * t5 + t1 * t3 * t4;
    q.z = t1 * t2 * t4 - t0 * t3 * t5;
    return q;
}

void Transform::setEulersAngles(glm::vec3 angles)
{
    rotation = angles;
    /*
    glm::quat qPitch = glm::angleAxis(glm::radians(angles.x), glm::vec3(1, 0, 0));
    glm::quat qYaw = glm::angleAxis(glm::radians(angles.y), glm::vec3(0, 1, 0));
    glm::quat qRoll = glm::angleAxis(glm::radians(angles.z),glm::vec3(0,0,1));
    qrotation = qYaw * qPitch * qRoll;
    
    qrotation = glm::normalize(glm::quat(glm::radians(angles)));
     */
    //angles = glm::radians(angles);
    //qrotation = toQuaternion(angles.y, angles.x, angles.z);

    //qrotation =  glm::rotation(getEulersAngles(), angles) * qrotation;
}

/*
glm::quat Transform::getRotation()
{
    return glm::quat(glm::radians(rotation));
}

void Transform::setRotation(glm::quat qr)
{
    rotation = glm::degrees(glm::eulerAngles(qr));
}
 */
