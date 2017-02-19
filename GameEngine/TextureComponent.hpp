//
//  TextureComponent.hpp
//  GameEngine
//
//  Created by Matvey Kravtsov on 24/01/2017.
//  Copyright © 2017 Matvey Kravtsov. All rights reserved.
//

#ifndef TextureComponent_hpp
#define TextureComponent_hpp

#include "headers.h"
#include "Component.hpp"

class TextureComponent : public Component
{
public:
    TextureComponent(const std::string& filename);
    GLuint texture;
};

#endif /* TextureComponent_hpp */
