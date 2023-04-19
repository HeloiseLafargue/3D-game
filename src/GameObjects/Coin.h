//
//  Coin.h
//  P2_template
//
//  Created by Miguel Valero Espada on 19/4/23.
//

#ifndef Coin_h
#define Coin_h
#include "GameObject.h"

class Coin : public GameObject{
    
public:
    Coin(Game *game, glm::vec3 pos, glm::vec3 dim);
    ~Coin();
    
    void update() override;
    void draw() override;
    void drawDebug() override;
    void receiveCarCollision(Player *car) override;
    
};

#endif /* Coin_h */
