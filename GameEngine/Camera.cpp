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
    
    if (m == _mModel)
        return _mView;
    
    _mModel = m;
    _mView = glm::inverse(m);
    return _mView;
    
}

glm::mat4 Camera::getProjectionMatrix()
{
    if (_mProj != glm::mat4())
        return _mProj;
    
    //change coordinate space to LH
    _mProj = calcProjectionMatrix() * glm::scale(glm::vec3(1,1,-1));
    return _mProj;
}

glm::mat4 Camera::getMatrix()
{
    return getProjectionMatrix() * getViewMatrix();
}
 
