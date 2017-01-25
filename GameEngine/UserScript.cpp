//
//  UserScript.cpp
//  GameEngine
//
//  Created by Matvey Kravtsov on 22/01/2017.
//  Copyright © 2017 Matvey Kravtsov. All rights reserved.
//

#include "UserScript.hpp"

void UserScript::start()
{
    Transform* t = getGO()->getTransform();
    //t->setEulersAngles({0,45,0});
    t->position = {0,0,0};
}

void UserScript::update()
{
    BaseEngine* be = &BaseEngine::shared();
    Transform* t = getGO()->getTransform();
    t->setEulersAngles(t->getEulersAngles() + glm::vec3(0,0,45*be->deltaTime));
    t->setEulersAngles(t->getEulersAngles() + glm::vec3(0,45*be->deltaTime, 0));
    //glm::vec3 v = t->getUp();
    //cout << v.x << " " << v.y << " " << v.z << endl;
}
