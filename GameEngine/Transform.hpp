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
    
    Transform(): position(0,0,0), qrotation(1,0,0,0), scale(1,1,1) {}
    
    glm::vec3 position;
    glm::quat qrotation;
    glm::vec3 scale;
    
    glm::vec3 getEulersAngles();
    void setEulersAngles(glm::vec3 const& angles);
    void rotate(glm::vec3 const& angles, bool world = false);
    glm::quat getQuat(glm::vec3 const& angles);
    
    glm::mat4 getModelMatrix();
    
    glm::mat4 getTranslationMatrix();
    glm::mat4 getRotationMatrix();
    glm::mat4 getScaleMatrix();
    
    glm::vec3 getFront();
    glm::vec3 getUp();
    glm::vec3 getLeft();
    
    void setRotation(glm::vec3 const& left, glm::vec3 const& up, glm::vec3 const& front);
    void setRotation(glm::mat3 const& mRot);
    
    void lookAt(glm::vec3 const& center, glm::vec3 const& up = {0,1,0});
    
protected:
    glm::vec3 rotation = glm::vec3(0,0,0);
    
};

#endif /* Transform_hpp */
