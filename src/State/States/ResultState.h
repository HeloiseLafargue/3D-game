#ifndef ResultState_h
#define ResultState_h

#include "State.h"
class Game;

class ResultState: public State{
public:
    ResultState(Game *game);
    
    ~ResultState();
    
    void update();
    void draw();
    void next();

    ofTrueTypeFont verdana;
        
};

#endif /* ResultState_h */
