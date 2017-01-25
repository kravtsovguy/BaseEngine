//
//  Mesh.hpp
//  GameEngine
//
//  Created by Matvey Kravtsov on 19/01/2017.
//  Copyright © 2017 Matvey Kravtsov. All rights reserved.
//

#ifndef Mesh_hpp
#define Mesh_hpp

#include "headers.h"
#include "Component.hpp"
#include "Vertex.cpp"

class Mesh : public Component
{
public:
    Mesh();
    void setVerticies(vector<Vertex> vertices);
    GLuint VBO, VAO, EBO;
    GLsizei vsize;
    
private:
    vector<Vertex> verticies;
    
};

#endif /* Mesh_hpp */