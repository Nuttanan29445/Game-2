#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class enemy
{
public:
    sf::RectangleShape rect;
    sf::Sprite sprite;
    sf::Text text;
    float movementspeed = 1;
    int attackDamage = 2;
    int counterWallking = 0;
    int direction;
    int hp = 100;
    bool alive = true;
    int generateRandom(int max)
    {
        int randomNumber = rand();
        int random = (randomNumber % max) + 1;
        int myRandom = random;
        return myRandom;
    }



    enemy();
    void update();
    void updateMovement();
};