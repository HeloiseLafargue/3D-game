#ifndef Wall_h
#define Wall_h

#include "GameObject.h"

class Wall : public GameObject{
    
    
public:
    Wall(Game *game, glm::vec3 pos, glm::vec3 dim);
    ~Wall();
    
    void draw() override;
    void receiveCarCollision(Player *car) override;
    
};

#endif

