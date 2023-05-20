#include "Bombardier.h"
#include "Game.h"

Bombardier::Bombardier(Game *game, glm::vec3 pos, glm::vec3 dim): GameObject(game, pos, dim){
    material.setEmissiveColor(ofColor::darkorange);
    speed = 2;
}
Bombardier::~Bombardier(){}

void Bombardier::draw(){
    
    material.begin();
    {
        collider->draw();
    }
    material.end();
    
}

void Bombardier::update(){
    transform.move(transform.getZAxis() * speed);
}





