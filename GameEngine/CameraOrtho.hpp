//
//  CameraOrtho.hpp
//  GameEngine
//
//  Created by Matvey Kravtsov on 19/02/2017.
//  Copyright © 2017 Matvey Kravtsov. All rights reserved.
//

#ifndef CameraOrtho_hpp
#define CameraOrtho_hpp

#include "BaseEngine.hpp"

class CameraOrtho : public Camera
{
    
public:
    CameraOrtho(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat znear, GLfloat zfar): _left(left), _right(right), _bottom(bottom), _top(top), _znear(znear), _zfar(zfar) {}
    glm::mat4 calcProjectionMatrix();
    bool isOrtho() { return true; }
    
protected:
    GLfloat _left;
    GLfloat _right;
    GLfloat _bottom;
    GLfloat _top;
    GLfloat _znear;
    GLfloat _zfar;
};

#endif /* CameraOrtho_hpp */
