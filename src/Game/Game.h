#ifndef Game_h
#define Game_h

#include "ofMain.h"
#include "StateMachine.h"
#include "GameObjectContainer.h"
#include "GameObjectGenerator.h"

#include <iostream>
#include <chrono>
#include <thread>

class Player;

class Game : public StateMachine{
    ofEasyCam cam;
    Player *player;
    GameObjectContainer *gameObjects = nullptr;
    GameObjectGenerator *generator  = nullptr;
    bool bDebug;
    bool bPlayerFinish;
    float initTime;
    float pauseTime;
    float endTime;
    
    ofSoundPlayer scream;
    ofTrueTypeFont verdana;

private : 
    bool pauseTimer;
    std::chrono::steady_clock::time_point startTime;
    double elapsedSeconds;
    
public:
    int ROAD_LENGTH;
    int ROAD_WIDTH;
    
    Game();
    ~Game();
    void init();
    void update();
    void draw();
    void finishGame(float time);
    void toggleDebug();
    bool isFinished();
    void setFinished(bool v);
    
    Player *getPlayer();
    vector<GameObject *> getCollisions(GameObject *gameObject);
    void addGameObject(GameObject *gameobject);
    
    double getEllapsedTime();
    void doScream();
    float getEndTime();
    void setTimerPaused(bool timePaused);
    void beginPlay();
    
};
#endif
