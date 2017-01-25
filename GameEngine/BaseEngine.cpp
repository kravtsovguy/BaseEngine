//
//  BaseEngine.cpp
//  GameEngine
//
//  Created by Matvey Kravtsov on 18/01/2017.
//  Copyright © 2017 Matvey Kravtsov. All rights reserved.
//

#include "BaseEngine.hpp"

void BaseEngine::buildAxis()
{
    GLfloat radius = 1;
    GLfloat height = 1;
    GLfloat r = 1.0f;
    GLfloat g = 1.0f;
    GLfloat b = 1.0f;
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.2;
    
    int mask[3] = {0};
    
    for (int i = 0; i < 3; i++)
    {
        
        mask[i] = 1;
        r = mask[1];
        g = mask[0];
        b = mask[2];
        
        vector<Vertex> v;
        angle = 0.0;
        bool q = true;
        while(q)
        {
            if (angle > 2*M_PI)
            {
                angle = 0;
                q = false;
            }
            x = radius * cos(angle);
            y = radius * sin(angle);
            
            
            if(v.size() % 6 != 0){
                
                v.push_back({x, y , height , r, g, b});
                v.push_back({x, y , height , r, g, b});
                v.push_back(v[v.size()-3]);
                v.push_back({x, y , 0 , r, g, b});
                continue;
            }
            v.push_back({x, y , height , r, g, b});
            v.push_back({x, y , 0 , r, g, b});
            
            angle = angle + angle_stepsize;
        }
        
        v.push_back({radius, 0 , height , r, g, b});
        v.push_back({radius, 0 , 0 , r, g, b});
        
        Mesh* m = new Mesh();
        m->setVerticies(v);
        
        GameObject* obj = new GameObject();
        obj->components.push_back(m);
        obj->name = "axis";
        
        Transform* t = obj->getTransform();
        t->scale = glm::vec3(0.01f,0.01f,200);

        t->position = -100.0f * glm::vec3(mask[1], -1 * mask[0], mask[2] );
        t->setEulersAngles( 90.0f * glm::vec3(mask[0],mask[1], mask[2]) );
        mask[i] = 0;
        addObject(obj);
    
    }
    
    
    /*glBindVertexArray(m.VAO);
    
    glDrawArrays(GL_TRIANGLES, 0, m.vsize);
    
    glBindVertexArray(0);*/
    
    /*
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while( angle < 2*M_PI ) {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y , height);
        glVertex3f(x, y , 0.0);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glVertex3f(radius, 0.0, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    angle = 0.0;
    while( angle < 2*M_PI ) {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y , height);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glEnd();
    */
    
}

void BaseEngine::initGLEW()
{
    glewExperimental = GL_TRUE;
    
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        exit(EXIT_FAILURE);
    }
}


void BaseEngine::init(Window* window)
{
    
    initGLEW();
    this->window = window;
    this->input = new Input(window);
    this->camera = new Camera((GLfloat)window->width/(GLfloat)window->height);
    this->shader = new Shader("shader.vs", "shader.frag");
    this->shaderT = new Shader("shader.vs", "shaderTexture.frag");
    this->root = new GameObject("root");
    
    GameObject* cam = new GameObject("camera");
    cam->getTransform()->position = glm::vec3(-3,3,-3);
    //cam->getTransform()->lookAt({0,0,0});
    cam->getTransform()->setEulersAngles( {45,45,0} );
    cam->addComponent(this->camera);
    addObject(cam);
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    glEnable(GL_DEPTH_TEST);
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glClearColor(clearColor[0], clearColor[1], clearColor[2], 1.0f);
    
    buildAxis();
}

void BaseEngine::start()
{
    callStart(root);
    
    while (!glfwWindowShouldClose(window->w))
    {
        
        GLfloat currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        
        glfwPollEvents();
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        callUpdate(root);
        
        draw(root, glm::mat4());
        
        glfwSwapBuffers(window->w);
        
        usleep((1 / 60.0) * 1000000);
    }
    
    glfwTerminate();
}

void BaseEngine::draw(GameObject *root, glm::mat4 root_model)
{
    glm::mat4 model = root_model * root->getTransform()->getModelMatrix();
    

    for (int i = 0; i < root->children.size(); i++)
    {
        draw(root->children[i], model);
    }

    Mesh* m = root->findComponent<Mesh>();
    if (!m)
        return;
    
    TextureComponent* tex = root->findComponent<TextureComponent>();
    
    Shader* _shader = shader;
    if (tex)
    {
        _shader = shaderT;
        
        
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, tex->texture);
        glUniform1i(glGetUniformLocation(_shader->program, "tex"), 0);
    }
    
    _shader->use();
    
    glm::mat4 projection;
    projection = camera->getProjectionMatrix();
    glUniformMatrix4fv(glGetUniformLocation(_shader->program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
    
    glm::mat4 view;
    view = camera->getViewMatrix();
    glUniformMatrix4fv(glGetUniformLocation(_shader->program, "view"), 1, GL_FALSE, glm::value_ptr(view));
    
    glUniformMatrix4fv(glGetUniformLocation(_shader->program, "model"), 1, GL_FALSE, glm::value_ptr(model));
    
    glBindVertexArray(m->VAO);
    
    glDrawArrays(GL_TRIANGLES, 0, m->vsize);
    
    glBindVertexArray(0);
}

void BaseEngine::stop()
{
    glfwSetWindowShouldClose(window->w, GL_TRUE);
    //glfwTerminate();
}

void BaseEngine::addObject(GameObject *obj)
{
    root->children.push_back(obj);
}
void BaseEngine::callStart(GameObject* root)
{
    for (int i = 0; i < root->children.size(); i++)
        callStart(root->children[i]);
    
    for (int i = 0; i < root->components.size(); i++)
    {
        if (!root->components[i]->enabled) continue;
        root->components[i]->setGO(root);
        root->components[i]->start();
    }
}
void BaseEngine::callUpdate(GameObject* root)
{
    for (int i = 0; i < root->children.size(); i++)
        callUpdate(root->children[i]);
    
    for (int i = 0; i < root->components.size(); i++)
    {
        if (!root->components[i]->enabled) continue;
        root->components[i]->setGO(root);
        root->components[i]->update();
    }
}
