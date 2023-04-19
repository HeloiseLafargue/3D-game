

#include "GameObject.h"

GameObject::GameObject(Game *game, glm::vec3 pos): game(game){
    transform.setPosition(pos);
    bAlive = true;
}
GameObject::~GameObject(){}

bool GameObject::isAlive(){
    return bAlive;
}

void GameObject::drawDebug(){
    collider.drawWireframe();
}
