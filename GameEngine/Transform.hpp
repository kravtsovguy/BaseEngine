//
//  Transform.hpp
//  GameEngine
//
//  Created by Matvey Kravtsov on 19/01/2017.
//  Copyright © 2017 Matvey Kravtsov. All rights reserved.
//

#ifndef Transform_hpp
#define Transform_hpp

#include "headers.h"
#include "Component.hpp"

class Transform : public Component
{
public:
    glm::vec3 position = glm::vec3(0,0,0);
    
    glm::quat qrotation = glm::quat(0,0,0,1);
    glm::vec3 scale = glm::vec3(1,1,1);
    
    glm::vec3 getEulersAngles();
    void setEulersAngles(glm::vec3 angles);
    
    glm::mat4 getModelMatrix();
    
    glm::mat4 getTranslationMatrix();
    glm::mat4 getRotationMatrix();
    glm::mat4 getScaleMatrix();
    
    glm::vec3 getFront();
    glm::vec3 getUp();
    glm::vec3 getRight();
    glm::vec3 getLeft();
    
    //void setFront(glm::vec3 v);
    //void setUp(glm::vec3 v);
    //void setRight(glm::vec3 v);
    
    void lookAt(glm::vec3 center, glm::vec3 up = {0,1,0});
    
protected:
    glm::vec3 rotation = glm::vec3(0,0,0);
    
};

#endif /* Transform_hpp */
