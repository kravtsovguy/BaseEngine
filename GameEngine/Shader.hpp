//
//  shader.h
//  game2
//
//  Created by Matvey Kravtsov on 16/01/2017.
//  Copyright © 2017 Matvey Kravtsov. All rights reserved.
//

#ifndef shader_h
#define shader_h

#include "headers.h"

class Shader
{
public:
    // Идентификатор программы
    GLuint Program;
    // Конструктор считывает и собирает шейдер
    Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
    // Использование программы
    void Use();
};



#endif /* shader_h */
