#ifndef GameObject_h
#define GameObject_h

#include "ofMain.h"
#include "iCollide.h"

class Game;
class Player;

class GameObject: public iCollide{
    
protected:
    ofMaterial material;
    bool bAlive;
    Game *game;
    
public:
    ofNode transform;
    GameObject(Game *game, glm::vec3 pos);
    virtual ~GameObject();
    
    virtual void draw() = 0;
    virtual void drawDebug();
    virtual void update() {};
    virtual void checkCollisions(){};
    bool isAlive();
};

#endif 
