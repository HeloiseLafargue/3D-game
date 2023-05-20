#include "Obstacle.h"
#include "Player.h"
#include "Game.h"


Obstacle::Obstacle(Game *game, glm::vec3 pos, glm::vec3 dim):
    GameObject(game, pos, dim){
    material.setDiffuseColor(ofColor::whiteSmoke);
    model.loadModel("Box.obj");
        
 
    
}
Obstacle::~Obstacle(){
    
}


void Obstacle::update(){
    model.update();
}

void Obstacle::draw(){
    transform.transformGL();
    model.drawFaces();
    
  //  ofDrawAxis(200);
    transform.restoreTransformGL();
    
    material.begin();
    {
        collider->draw();
    }
    material.end();
}

void Obstacle::receiveCarCollision(Player *car){
    car->brake();
    kill();
}

void Obstacle::receiveBulletCollision(GameObject *bullet){
    bullet->kill();
    kill();
}

void Obstacle::setColor(ofColor color){
    material.setEmissiveColor(color);
}

