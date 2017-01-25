//
//  BaseEngine.hpp
//  GameEngine
//
//  Created by Matvey Kravtsov on 18/01/2017.
//  Copyright © 2017 Matvey Kravtsov. All rights reserved.
//

#ifndef BaseEngine_hpp
#define BaseEngine_hpp

#include "headers.h"
#include "Vertex.hpp"
#include "GameObject.hpp"
#include "Shader.hpp"
#include "Camera.hpp"
#include "Window.hpp"
#include "Input.hpp"
#include "Mesh.hpp"
#include "Component.hpp"
#include "TextureComponent.hpp"
//class Vertex;
//class GameObject;
//class Shader;
//#include "GameObject.cpp"
//#include "Shader.h"

class BaseEngine;
typedef void (* BEupdatefun)(BaseEngine* be);

class BaseEngine
{

private:
    BaseEngine() {}
    BaseEngine( const BaseEngine&);
    BaseEngine& operator=( BaseEngine& );
public:
    static BaseEngine& shared() {
        static BaseEngine  instance;
        return instance;
    }
    
public:
    void init(Window* window);
    void start();
    void stop();
    void addObject(GameObject* obj);
    vector<GameObject*> objects;
    vector<BEupdatefun> updateCallback;
    void removeCallback(BEupdatefun callback);
    Shader* shader;
    Shader* shaderT;
    Camera* camera;
    Window* window;
    Input* input;
    GameObject* root;
    glm::vec3 clearColor = glm::vec3(0.2f, 0.3f, 0.3f);
    GLfloat deltaTime = 0.0f;	// Time between current frame and last frame

    
private:
    GLfloat lastFrame = 0.0f;
    void initGLEW();
    void draw(GameObject *root, glm::mat4 root_model);
    void callStart(GameObject* root);
    void callUpdate(GameObject* root);
    void buildCylynder();

};

#endif /* BaseEngine_hpp */