#include "Bombardier.h"
#include "Game.h"

Bombardier::Bombardier(Game *game, glm::vec3 pos, glm::vec3 dim): GameObject(game, pos, dim){
	model.loadModel("plane.obj");
	model.setRotation(0, 180, 1, 0, 0);
	model.setRotation(0, 180, 0, 1, 0);
	model.setRotation(0, 180, 0, 0, 1);
	model.setPosition(0, -200, -500);
	model.setScale(2, 2, 2);
    speed = 2;
}
Bombardier::~Bombardier(){}

void Bombardier::draw(){
    
	transform.transformGL();
	model.drawFaces();
	transform.restoreTransformGL();
    
}

void Bombardier::update(){
	model.update();
    transform.move(transform.getZAxis() * speed);
}





