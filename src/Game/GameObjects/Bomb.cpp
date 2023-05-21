#include "Bomb.h"
#include "Player.h"
#include "Game.h"

Bomb::Bomb(Game *game, glm::vec3 pos, glm::vec3 dim): GameObject(game, pos, dim){
	model.loadModel("bomb.obj");
    collider -> move(800, 0, 0);
	model.setRotation(0, 180, 1, 0, 0);
	model.setScale(0.25, 0.25, 0.25);
    speed = 1;
}
Bomb::~Bomb(){}

void Bomb::draw(){
    
	transform.transformGL();
	model.drawFaces();
	transform.restoreTransformGL();
    
}

void Bomb::update(){
	model.update();
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
