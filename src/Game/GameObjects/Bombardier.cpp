#include "Bombardier.h"
#include "Game.h"

Bombardier::Bombardier(Game *game, glm::vec3 pos, glm::vec3 dim): GameObject(game, pos, dim){
    collider -> move(800, 0, 0);
	model.loadModel("plane.obj");
	model.setRotation(0, 180, 1, 0, 0);
	model.setRotation(0, 180, 0, 1, 0);
	model.setRotation(0, 180, 0, 0, 1);
	model.setPosition(800, -200, -500);
	model.setScale(1, 1, 1);
    speed = 0.5;
}
Bombardier::~Bombardier(){}

void Bombardier::draw(){
	transform.transformGL();
	model.drawFaces();
	transform.restoreTransformGL();
    
}

void Bombardier::update(){
	model.update();
    transform.rotateDeg(0 - speed, glm::vec3(0,1,0));
    //transform.rotateAroundDeg(0 - speed, glm::vec3(0,1,0), glm::vec3(0, 500, -500));
    transform.rotateDeg(0 + speed, glm::vec3(0,1,0));
}





