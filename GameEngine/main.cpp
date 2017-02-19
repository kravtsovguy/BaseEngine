//
//  main.cpp
//  GameEngine
//
//  Created by Matvey Kravtsov on 18/01/2017.
//  Copyright © 2017 Matvey Kravtsov. All rights reserved.
//

#include "BaseEngine.hpp"
#include "UserScript.hpp"
#include "CameraScript.hpp"

int main(int argc, const char * argv[]) {
    
    
    Window* w = new Window();
    w->init(800, 600, "Base Engine");
    BaseEngine* be = &BaseEngine::shared();
    be->init(w);
    GameObject* obj = new GameObject("user");
    //obj.getTransform()->setEulersAngles( {0,0,45} );
    obj->getTransform()->position = {0.0f,0.0f,0};
    Mesh* m = new Mesh();
    std::vector<Vertex> vertices = {
        {0.5f,  0.5f, 0.0f,      1.0f, 1.0f, 0.0f,   1.0f, 1.0f},
        {0.5f, -0.5f, 0.0f,      0.0f, 0.0f, 1.0f,   1.0f, 0.0f},
        {-0.5f, -0.5f, 0.0f,     0.0f, 0.0f, 1.0f,   0.0f, 0.0f},
        {-0.5f, -0.5f, 0.0f,     0.0f, 0.0f, 1.0f,   0.0f, 0.0f},
        {-0.5f, 0.5f, 0.0f,     1.0f, 1.0f, 0.0f,   0.0f, 1.0f},
        {0.5f, 0.5f, 0.0f,     1.0f, 1.0f, 0.0f,   1.0f, 1.0f},
        /*
        {0.5f,  0.5f, -1.0f,      1.0f, 0.0f, 0.0f,   1.0f, 1.0f},
        {0.5f, -0.5f, -1.0f,      0.0f, 0.0f, 1.0f,   1.0f, 0.0f},
        {-0.5f, -0.5f, -1.0f,     0.0f, 0.0f, 1.0f,   0.0f, 0.0f},
        
        {-0.5f, -0.5f, -1.0f,     0.0f, 0.0f, 1.0f,   0.0f, 0.0f},
        {-0.5f, 0.5f, -1.0f,     1.0f, 0.0f, 0.0f,   0.0f, 1.0f},
        {0.5f, 0.5f, -1.0f,     1.0f, 0.0f, 0.0f,   1.0f, 1.0f},
         */
    };
    
    m->setVerticies(vertices);
    obj->addComponent(m);
    obj->addComponent(new TextureComponent("awesomeface.png"));
    //obj->addComponent(new TextureComponent("container.png"));
    obj->addComponent(new UserScript());
    //obj.getTransform()->position = glm::vec3(3,0,0);
    //obj.getTransform()->rotation =  glm::vec3(0,0,45);
    //obj.getTransform()->scale = glm::vec3(2,1,1);
    be->addObject(obj);
    
    be->camera->getGO()->addComponent(new CameraScript());
    
    be->start();
    
    return 0;
}
