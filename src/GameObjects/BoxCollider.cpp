#include "BoxCollider.h"
#include "GameObject.h"
#include "ofxBullet.h"

BoxCollider::BoxCollider(GameObject *gameObject):gameObject(gameObject){
    bColliding = false;
    
}
BoxCollider::~BoxCollider(){}


bool BoxCollider::collide(BoxCollider *other){
    return false;
}

void BoxCollider::drawDebug(){
    ofPushStyle();
    drawWireframe();
    collisionObject->draw();
    ofPopStyle();
    
}
