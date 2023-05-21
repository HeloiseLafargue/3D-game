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
    logo.load("driftFury.jpg");
}
void MenuState::update(){
    if (ofGetKeyPressed()) {
        next();
    }
};
    
void MenuState::draw(){
    logo.draw(0, 0, ofGetWidth(), ofGetHeight());
    gui.draw();

    ofBackground(ofColor::lightGoldenRodYellow);

    ofSetColor(ofColor::darkBlue);
    ofDrawRectangle(ofGetWidth() / 2 - 250, 250, 525, 190);
    ofDrawBitmapString("DRIFT FURY", ofGetWidth() / 2 - 30, 200);

    ofSetColor(ofColor::white);
    ofDrawBitmapString(name, ofGetWidth() / 2 - 40, 280);
    ofDrawBitmapString("Press any key to Start", ofGetWidth() / 2 - 90, 310);
    ofDrawBitmapString("Press 'p' to pause", ofGetWidth() / 2 - 70, 360);
    ofDrawBitmapString("Press 'l' to light", ofGetWidth() / 2 - 70, 380);
    ofDrawBitmapString("Press 'space' to shot", ofGetWidth() / 2 - 80, 400);
    verdana.drawString("test", ofGetWidth() / 2 - 200, 330);

    
};

void MenuState::next(){
    game->setState(new PlayState(game));
};
