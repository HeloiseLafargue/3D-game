#ifndef Bombardier_h
#define Bombardier_h

#include "GameObject.h"
#include "Bomb.h"
#include "ofxAssimpModelLoader.h"



class Bombardier : public GameObject{
    float speed = -5;
    glm::vec3 position;
<<<<<<< Updated upstream
=======
    float startTime;
    float FinishTime;
>>>>>>> Stashed changes
    
public:
    Bombardier(Game *game, glm::vec3 pos, glm::vec3 dim);
    ~Bombardier();
    
    void init();
    void draw() override;
    void update() override;
<<<<<<< Updated upstream
    void dropBomb();
=======
    glm::vec3 getPosition();
>>>>>>> Stashed changes

	ofxAssimpModelLoader model;
    
};

#endif

