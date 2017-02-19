//
//  CameraPerspective.cpp
//  GameEngine
//
//  Created by Matvey Kravtsov on 19/02/2017.
//  Copyright © 2017 Matvey Kravtsov. All rights reserved.
//

#include "CameraPerspective.hpp"

glm::mat4 CameraPerspective::calcProjectionMatrix()
{
    return glm::perspective(glm::radians(_fov), _ratio, _znear, _zfar);
}
