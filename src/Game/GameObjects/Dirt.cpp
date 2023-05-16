#include "Dirt.h"
#include "Player.h"
#include "Game.h"


Dirt::Dirt(Game *game, glm::vec3 pos, glm::vec3 dim) :
	GameObject(game, pos, dim) {
	material.setDiffuseColor(ofColor::red);



}
Dirt::~Dirt() {

}


void Dirt::update() {
	model.update();
}

void Dirt::draw() {


	material.begin();
	{
		collider->draw();
	}
	material.end();
}

void Dirt::receiveCarCollision(Player *car) {
	car->slow();
}

