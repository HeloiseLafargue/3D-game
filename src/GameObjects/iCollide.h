

#ifndef iColllide_h
#define iColllide_h

#include "ofMain.h"
#include "BoxCollider.h"

class Player;


class iCollide{
    
    protected:
        BoxCollider *collider;

    public:
    
    virtual void receiveCarCollision(Player *car) {};
        
    BoxCollider* getCollider(){
        return collider;
    }
        
    bool collide(iCollide *other){
        return collider->collide(other->getCollider());
    }
};

#endif /* iColllide_h */
