#include "GameObjectContainer.h"
#include "GameObject.h"


GameObjectContainer::GameObjectContainer(){}

void GameObjectContainer::add(GameObject* g){
    gameObjects.push_back(g);
}

GameObjectContainer::~GameObjectContainer(){
    clear();
}

void GameObjectContainer::update(){
    for(auto g: gameObjects){
        if(g->isAlive()){
            g->update();
            g->checkCollisions();
        }
    }
    removeDead();
}

void GameObjectContainer::draw(){
    for(auto g: gameObjects){
        if(g->isAlive()){
            g->draw();
        }
    }
}
void GameObjectContainer::drawDebug(){
    for(auto g: gameObjects){
        g->drawDebug();
    }
}

void GameObjectContainer::removeDead(){
    vector<GameObject*> alive;
    for(auto g: gameObjects){
        if(g->isAlive())
            alive.push_back(g);
        else
            delete g;
    }
    gameObjects.clear();
    gameObjects = alive;
}

void GameObjectContainer::clear(){
    for(auto g: gameObjects){
        delete g;
    }
    gameObjects.clear();
}

vector<GameObject *> GameObjectContainer::getCollisions(GameObject *gameObject){
    vector<GameObject *> collisions;
    for(auto other: gameObjects){
        if(gameObject != other && other->isAlive()){
            if(gameObject->collide(other))
                collisions.push_back(other);
        }
    }
    return collisions;
}
