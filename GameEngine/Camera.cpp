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
    glm::mat4 m = getGO()->getTransform()->getModelMatrix();
    //m[0] *= -1;
    //m[2] *= -1;
    
    if (m == _mModel)
        return _mView;
    
    _mModel = m;
    _mView = glm::inverse(m);
    return _mView;
    
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
    if (_mProj != glm::mat4())
        return _mProj;
    
    _mProj = calcProjectionMatrix() * glm::scale(glm::vec3(1,1,-1));
    return _mProj;
}

glm::mat4 Camera::getMatrix()
{
    return getProjectionMatrix() * getViewMatrix();
}
 
