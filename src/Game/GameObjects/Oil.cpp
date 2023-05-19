#include "Oil.h"
#include "Player.h"
#include "Game.h"


Oil::Oil(Game *game, glm::vec3 pos, glm::vec3 dim) :
	GameObject(game, pos, dim) {
	
	plano.set(500, 500);
	plano.rotateDeg(-90, 1, 0, 0);
	plano.move(-600, -49, 1000);

	ofEnableNormalizedTexCoords();
	ofDisableArbTex();
	ofImage img;
	img.load("oil.jpg");

	texture = img.getTexture();



}
Oil::~Oil() {

}


void Oil::update() {
	model.update();
}

void Oil::draw() {

	texture.bind();
	plano.draw();
	texture.unbind();

}

void Oil::receiveCarCollision(Player *car) {
	car->drift();
}

