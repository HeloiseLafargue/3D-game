#ifndef Obstacle_h
#define Obstacle_h
#include "GameObject.h"
#include "ofxAssimpModelLoader.h"

class Obstacle : public GameObject{
    
public:
    Obstacle(Game *game, glm::vec3 pos, glm::vec3 dim);
    ~Obstacle();
    
    void update() override;
    void draw() override;
    void receiveCarCollision(Player *car) override;
    void receiveBulletCollision(GameObject *bullet) override;
    ofxAssimpModelLoader model;

};

#endif /* Obstacle_h */
