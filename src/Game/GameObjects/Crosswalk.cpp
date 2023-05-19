#include "Crosswalk.h"
#include "Player.h"
#include "Pedestrian.h"
#include "Barrera.h"

Crosswalk::Crosswalk(Game *game, glm::vec3 pos, glm::vec3 dim): GameObject(game, pos, dim){
    material.setEmissiveColor(ofColor::whiteSmoke);
}
Crosswalk::~Crosswalk(){}

void Crosswalk::draw(){
    
    material.begin();
    {
        collider->draw();
    }
    material.end();
}


