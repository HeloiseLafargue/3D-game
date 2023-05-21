#include "PlayState.h"
#include "MenuState.h"

MenuState::MenuState(Game* game) : State(game, "Menu State") {
    game->init();
};

void MenuState::setup() {
    gui.setup();
    gui.add(dif.set("Difficulty", 1, 1, 6));
    gui.add(totalGames.set("Number of Games", 1, 1, 10));

    verdana.load("Arial Unicode.ttf", 25, true, true);
}
void MenuState::update(){
    if (ofGetKeyPressed()) {
        next();
    }
};
    
void MenuState::draw(){
    ofBackground(ofColor::lightGoldenRodYellow);

    ofSetColor(ofColor::darkBlue);
    ofDrawRectangle(ofGetWidth() / 2 - 250, 250, 525, 190);
    ofDrawBitmapString("DRIFT FURY", ofGetWidth() / 2 - 20, 200);

    ofSetColor(ofColor::white);
    ofDrawBitmapString(name, ofGetWidth() / 2 - 40, 300);
    ofDrawBitmapString("Press any key to Start", ofGetWidth() / 2 - 80, 370);
    ofDrawBitmapString("Press 'p' to pause", ofGetWidth() / 2 - 70, 390);
    verdana.drawString("test", ofGetWidth() / 2 - 200, 330);

    gui.draw();
};

void MenuState::next(){
    game->setState(new PlayState(game));
};
