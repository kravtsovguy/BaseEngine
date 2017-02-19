//
//  CameraOrtho.cpp
//  GameEngine
//
//  Created by Matvey Kravtsov on 19/02/2017.
//  Copyright © 2017 Matvey Kravtsov. All rights reserved.
//

#include "CameraOrtho.hpp"

glm::mat4 CameraOrtho::calcProjectionMatrix()
{
    return glm::ortho(_left, _right, _bottom, _top, _znear, _zfar);
}
