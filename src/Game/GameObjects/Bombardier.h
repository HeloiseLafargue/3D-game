#ifndef Bombardier_h
#define Bombardier_h

#include "GameObject.h"
#include "Barrera.h"

class Pedestrian;

class Bombardier : public GameObject{
    float speed = -5;
    
public:
    Bombardier(Game *game, glm::vec3 pos, glm::vec3 dim);
    ~Bombardier();
    
    void draw() override;
    void update() override;
    
};

#endif
