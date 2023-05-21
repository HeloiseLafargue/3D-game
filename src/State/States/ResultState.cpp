#include "Game.h"
#include "Player.h"
#include "ResultState.h"
#include "MenuState.h"

 
ResultState::ResultState(Game *game): State(game, "Result State"){
};

ResultState::~ResultState(){};

void ResultState::update(){
	if (ofGetKeyPressed('r')) {
		next();
	}
};

void ResultState::draw(){
	ofBackground(ofColor::lightGoldenRodYellow);

	ofSetColor(ofColor::darkBlue);
	ofDrawRectangle(ofGetWidth() / 2 - 250, 250, 525, 190);
	ofSetColor(ofColor::white);
	ofDrawBitmapString(name, ofGetWidth() / 2 - 40, 270);
	ofDrawBitmapString("End of the game", ofGetWidth() / 2 - 50, 300);
	ofDrawBitmapString("Score", ofGetWidth() / 2 - 5, 330);
	//verdana.drawString("Score", ofGetWidth() / 2 - 200, 330);
	ofDrawBitmapString(score, ofGetWidth() / 2 - 10, 350);
	ofDrawBitmapString("Press 'r' to try again Drift Fury", ofGetWidth() / 2 - 110, 390);

};

void ResultState::next(){
    game->setState(new MenuState(game));
};

void ResultState::getScore(Game* game, Player* car) {
	score = car->getCoins() - (game->getEllapsedTime() * 0.00001);
}
