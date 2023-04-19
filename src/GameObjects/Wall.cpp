#include "Wall.h"
#include "Player.h"

Wall::Wall(Game *game, glm::vec3 pos, glm::vec3 dim): GameObject(game, pos){
    collider.setParent(transform);
    collider.set(dim.x, dim.y, dim.z);
    material.setEmissiveColor(ofColor::darkorange);
}
Wall::~Wall(){}

void Wall::draw(){
    
    material.begin();
    {
        collider.draw();
    }
    material.end();
}

void  Wall::receiveCarCollision(Player *car){
    car->stop();
}
