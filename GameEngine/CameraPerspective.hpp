//
//  CameraPerspective.hpp
//  GameEngine
//
//  Created by Matvey Kravtsov on 19/02/2017.
//  Copyright © 2017 Matvey Kravtsov. All rights reserved.
//

#ifndef CameraPerspective_hpp
#define CameraPerspective_hpp

#include "BaseEngine.hpp"

class CameraPerspective : public Camera
{
    
public:
    CameraPerspective(GLfloat fov, GLfloat ratio, GLfloat znear, GLfloat zfar): _ratio(ratio), _fov(fov), _znear(znear), _zfar(zfar) {}
    glm::mat4 calcProjectionMatrix();
    bool isOrtho() { return false; };
    
protected:
    GLfloat _ratio = 1.0f;
    GLfloat _fov = 45.0f;
    GLfloat _znear = 0.1f;
    GLfloat _zfar = 100.0f;
};

#endif /* CameraPerspective_hpp */
