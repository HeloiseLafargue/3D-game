#pragma once

#include "ofMain.h"
#include "Game.h"
#include "State.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		
        Game *game;
};
