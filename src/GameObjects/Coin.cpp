#include "Coin.h"
#include "Player.h"


Coin::Coin(Game *game, glm::vec3 pos, glm::vec3 dim):
    GameObject(game, pos){
        
    material.setDiffuseColor(ofColor::yellow);
    collider.setPosition(pos);
    collider.set(dim.x, dim.y, dim.z);
}
Coin::~Coin(){
    
}


void Coin::update(){
    
}

void Coin::draw(){
    
    material.begin();
    {
        collider.draw();
    }
    material.end();
}
void Coin::drawDebug(){
    
    collider.drawWireframe();
}

void Coin::receiveCarCollision(Player *car){
    car->addCoins(5);
    bAlive = false;
    
}
