//
//  TextureComponent.cpp
//  GameEngine
//
//  Created by Matvey Kravtsov on 24/01/2017.
//  Copyright © 2017 Matvey Kravtsov. All rights reserved.
//

#include "TextureComponent.hpp"


TextureComponent::TextureComponent(const std::string& filename)
{
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    int width, height, n;
    unsigned char* image = stbi_load(filename.c_str(), &width, &height, &n, 0);
    
    GLint channel = GL_RGB;
    if (n == 4)
        channel = GL_RGBA;
    
    glTexImage2D(GL_TEXTURE_2D, 0, channel, width, height, 0, channel, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    
    glBindTexture(GL_TEXTURE_2D, 0);
    
}
