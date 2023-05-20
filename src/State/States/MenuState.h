#ifndef MenuState_h
#define MenuState_h

#include "State.h"
#include "Game.h"
#include "ofxGui.h"

class MenuState: public State{
public:
    MenuState(Game* game);
    
    ~MenuState(){};
    
    void setup();
    void update();
    void draw();
    void next();

    ofxPanel gui;
    ofParameter<int>  dif;
    ofParameter<int>  totalGames;
        
};
#endif 
