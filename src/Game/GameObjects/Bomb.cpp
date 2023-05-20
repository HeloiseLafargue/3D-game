#include "Bomb.h"
#include "Player.h"
#include "Pedestrian.h"
#include "Game.h"

Bomb::Bomb(Game *game, glm::vec3 pos, glm::vec3 dim): GameObject(game, pos, dim){
    material.setEmissiveColor(ofColor::darkorange);
    speed = 1;
}
Bomb::~Bomb(){}

void Bomb::draw(){
    
    material.begin();
    {
        collider->draw();
    }
    material.end();
    
}

void Bomb::update(){
    transform.move(transform.getZAxis() * +speed);
    transform.move(transform.getYAxis() * -speed);
}

void  Bomb::receiveCarCollision(Player *car){
    car->fall();
}

void Bomb::checkCollisions(){
    vector<GameObject*> collisions = game->getCollisions(this);
    for(auto c: collisions){
        c->receiveBombCollision(this);
    }
}
