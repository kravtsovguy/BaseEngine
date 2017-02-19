//
//  GameObject.cpp
//  GameEngine
//
//  Created by Matvey Kravtsov on 18/01/2017.
//  Copyright © 2017 Matvey Kravtsov. All rights reserved.
//

#include "GameObject.hpp"


GameObject::GameObject()
{
    addComponent(new Transform());
}

Transform* GameObject::getTransform()
{
    return (Transform*)findComponent<Transform>();
}
void GameObject::addComponent(Component* c)
{
    c->setGO(this);
    components.push_back(c);
}
void GameObject::removeComponent(Component* c)
{
    components.erase(remove(components.begin(), components.end(), c), components.end());
}
