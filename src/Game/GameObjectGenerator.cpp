
#include "GameObjectGenerator.h"
#include "Game.h"
#include "Road.h"
#include "Wall.h"
#include "Goal.h"
#include "Coin.h"
#include "Obstacle.h"
#include "Barrera.h"
#include "Pedestrian.h"
#include "Dirt.h"

GameObjectGenerator::GameObjectGenerator(Game *game): game(game){}

void GameObjectGenerator::generateWorld(){
    int W = game->ROAD_WIDTH;
    int L = game->ROAD_LENGTH;
    
    // Camino
    glm::vec3 roadPos(0, -50.1, L/2 - 1000);
    auto road = new Road(game, roadPos, glm::vec3(W, 0, L));
    
    game->addGameObject(road);
//
    int wallSize = 100;

    ofImage circuito;
    circuito.load("circuito.png");

    int w = circuito.getWidth()/16;
    int h = circuito.getHeight()/16;
    circuito.resize(w, h);


//    for(int x = 0; x < w; x++){
//        for(int y = 0; y < h; y++){
//            if(circuito.getColor(x, y).a > 250){
//
//                auto wall = new Wall(game,
//                                glm::vec3(x*wallSize - 5000, roadPos.y, y*wallSize -2000),
//                                glm::vec3(wallSize*0.99));
//                game->addGameObject(wall);
//            }
//        }
//    }

    
//     WALL with parts
//    for(int l = 0; l < L; l += wallSize){
//        auto wall_r = new Wall(game,
//                        glm::vec3(-W/2, roadPos.y, l - 1000 + wallSize/2),
//                        glm::vec3(wallSize));
//
//        wall_r->isFixed = true;
//        game->addGameObject(wall_r);
//
//    }
    
    // Paredes
    auto wall_r = new Wall(game,
                    glm::vec3(-W/2, roadPos.y, roadPos.z),
                           glm::vec3(wallSize, wallSize, L));
    game->addGameObject(wall_r);

    wall_r = new Wall(game,
                    glm::vec3(-W/2, roadPos.y, roadPos.z - L * 0.8),
                           glm::vec3(wallSize, wallSize, L));
    game->addGameObject(wall_r);

    

    auto wall_l = new Wall(game,
                    glm::vec3(W/2, roadPos.y, roadPos.z),
                           glm::vec3(wallSize, wallSize, L));
    game->addGameObject(wall_l);

    wall_l = new Wall(game,
                    glm::vec3(W/2, roadPos.y, roadPos.z - L * 0.8),
                           glm::vec3(wallSize, wallSize, L));
    game->addGameObject(wall_l);
//
    auto goal = new Goal(game,
                    glm::vec3(0, roadPos.y, roadPos.z + L/2),
                           glm::vec3(W, 100, 100));
    goal->isFixed = true;
    game->addGameObject(goal);
    
    
    // Coins
    for (int i=0; i < 25; i++){
        auto coin = new Coin(game,
            glm::vec3(rand()%2000 - 1000, 0, rand()%7000), glm::vec3(50));
        
        game->addGameObject(coin);
    }
    
     // Obstaculos
    for (int i=0; i < 25; i++){
        auto obstacle = new Obstacle(game,
            glm::vec3(rand()%2000 - 1000, 0, rand()%7000), glm::vec3(100));
        
        game->addGameObject(obstacle);
    }
    
    
    // Barrera
    auto wall_c = new Wall(game,
                    glm::vec3(0, roadPos.y + 600, roadPos.z),
                           glm::vec3(W, wallSize, wallSize));
    wall_c -> setColor(ofColor::black);
    game->addGameObject(wall_c);
    
    auto barrera = new Barrera(game,
                    glm::vec3(0, roadPos.y + 500, roadPos.z),
                           glm::vec3(W - 200, wallSize, wallSize));
    game->addGameObject(barrera);
    
    // Paso de peatones
    auto Paso1 = new Obstacle(game, glm::vec3(W/2 - 200, -50, 500), glm::vec3(W/20, 0, 200));
    //Paso1 -> setColor(ofColor::white);
    game->addGameObject(Paso1);
    
    auto Paso2 = new Obstacle(game, glm::vec3(W/2 - 400, -50, 500), glm::vec3(W/20, 0, 200));
    //Paso2 -> setColor(ofColor::white);
    game->addGameObject(Paso2);
    
    auto Paso3 = new Obstacle(game, glm::vec3(W/2 - 600, -50, 500), glm::vec3(W/20, 0, 200));
    //Paso3 -> setColor(ofColor::white);
    game->addGameObject(Paso3);
    
    auto Paso4 = new Obstacle(game, glm::vec3(W/2 - 800, -50, 500), glm::vec3(W/20, 0, 200));
    //Paso4 -> setColor(ofColor::white);
    game->addGameObject(Paso4);
    
    auto Paso5 = new Obstacle(game, glm::vec3(W/2 - 1000, -50, 500), glm::vec3(W/20, 0, 200));
    //Paso5 -> setColor(ofColor::white);
    game->addGameObject(Paso5);
    
    auto Paso6 = new Obstacle(game, glm::vec3(W/2 - 1200, -50, 500), glm::vec3(W/20, 0, 200));
    //Paso6 -> setColor(ofColor::white);
    game->addGameObject(Paso6);
    
    auto Paso7 = new Obstacle(game, glm::vec3(W/2 - 1400, -50, 500), glm::vec3(W/20, 0, 200));
    //Paso7 -> setColor(ofColor::white);
    game->addGameObject(Paso7);
    
    auto Paso8 = new Obstacle(game, glm::vec3(W/2 - 1600, -50, 500), glm::vec3(W/20, 0, 200));
    //Paso8 -> setColor(ofColor::white);
    game->addGameObject(Paso8);
    
    auto Paso9 = new Obstacle(game, glm::vec3(W/2 - 1800, -50, 500), glm::vec3(W/20, 0, 200));
    //Paso9 -> setColor(ofColor::white);
    game->addGameObject(Paso9);
    
    //Peatón
    auto pedestrian = new Pedestrian(game,
        glm::vec3(W/2 - 100, -25, 500), glm::vec3(50, 150, 50));

    game->addGameObject(pedestrian);


	
	auto mancha1 = new Dirt(game, glm::vec3(100, -48, 100), glm::vec3(W / 20, 10, 200));
	game->addGameObject(mancha1);
}
