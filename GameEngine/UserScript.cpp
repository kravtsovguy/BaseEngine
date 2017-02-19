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
    //t->setEulersAngles({0,0,0});
    //t->rotate({0,0,45});
    //t->rotate({0,45,0},1);

    t->position = {-1,-1,-1};
}

void UserScript::update()
{
    BaseEngine* be = &BaseEngine::shared();
    Transform* t = getGO()->getTransform();
    //t->position = be->camera->getGO()->getTransform()->position;

    //t->qrotation = be->camera->getGO()->getTransform()->qrotation;
    //t->lookAt(be->camera->getGO()->getTransform()->position);
    //t->rotate({0, 45*be->deltaTime,45*be->deltaTime});
    //t->rotate({0,45*be->deltaTime,0});
}
