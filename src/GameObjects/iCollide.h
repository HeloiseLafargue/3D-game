

#ifndef iColllide_h
#define iColllide_h

#include "ofMain.h"
class Player;

class iCollide{
    
    protected:
        ofBoxPrimitive collider;

    public:
    
        virtual void receiveCarCollision(Player *car) {};
        
        ofBoxPrimitive& getCollider(){
            return collider;
        }
        
    bool  collide(iCollide *other){
            ofBoxPrimitive otherCollider = other->getCollider();
            glm::vec3 p0 = collider.getGlobalPosition();
            glm::vec3 d0 = collider.getSize();
            glm::vec3 p1 = otherCollider.getGlobalPosition();
            glm::vec3 d1 = otherCollider.getSize();
            if(p0.x + d0.x/2 > p1.x - d1.x/2 && p0.x - d0.x/2 < p1.x + d1.x/2){
                if(p0.y + d0.y/2 > p1.y - d1.y/2 && p0.y - d0.y/2 < p1.y + d1.y/2){
                    if(p0.z + d0.z/2 > p1.z - d1.z/2 && p0.z - d0.z/2 < p1.z + d1.z/2){
                        return true;
                    }
                }
            }
            return false;
        }
};

#endif /* iColllide_h */
