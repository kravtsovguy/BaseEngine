//
//  GameObject.hpp
//  GameEngine
//
//  Created by Matvey Kravtsov on 18/01/2017.
//  Copyright © 2017 Matvey Kravtsov. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include "headers.h"
#include "Vertex.hpp"
#include "Component.hpp"
#include "Transform.hpp"

class GameObject
{
public:
    GameObject();
    GameObject(const std::string& name) : GameObject()
    {
        this->name = name;
    }
    Transform* getTransform();
    void addComponent(Component* c);
    void removeComponent(Component* c);
    
    template <class T>
    T* findComponent()
    {
        class c;
        for (int i = 0;  i < components.size(); i++)
        {
            if (dynamic_cast<T*>(components[i]) != NULL)
            {
                return (T*)components[i];
                break;
            }
        }
        return nullptr;
    }
    std::vector<GameObject*> children;
    std::vector<Component*> components;
    std::string name;
    
};

#endif /* GameObject_hpp */
