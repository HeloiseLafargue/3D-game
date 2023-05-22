#include "Bomb.h"
#include "Player.h"
#include "Game.h"
#include "Bombardier.h"

Bomb::Bomb(Game *game, glm::vec3 pos, glm::vec3 dim): GameObject(game, pos, dim){
	model.loadModel("bomb.obj");
	model.setRotation(0, 180, 1, 0, 0);
	model.setScale(0.25, 0.25, 0.25);
    speed = 2;
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
    
	if (transform.getPosition().y <= -200) {
		
		transform.move(1250 + rand()%2000 - 1000, 1200, -2200 + rand()%2000 -1000);
	}
    
}

void  Bomb::receiveCarCollision(Player *car){
    car->fall();
	kill();
}

void Bomb::checkCollisions(){
    vector<GameObject*> collisions = game->getCollisions(this);
    for(auto c: collisions){
        c->receiveBombCollision(this);
    }
}
