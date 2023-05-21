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
    void getScore(Game* game,Player* car);
    int score;
        
};

#endif /* ResultState_h */
