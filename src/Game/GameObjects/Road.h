#ifndef Road_h
#define Road_h

#include "GameObject.h"
#include "Barrera.h"

class Road : public GameObject{
    
    ofLight light;
    ofPlanePrimitive plane;
public:
    Road(Game *game, glm::vec3 pos, glm::vec3 dim);
    ~Road();
    
    void draw() override;
    void drawDebug() override;
    void receiveBarreraCollision(Barrera* barrera) override;
    void setColor(ofColor color);
    
};

#endif /* Road_h */
