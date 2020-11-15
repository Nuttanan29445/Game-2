#include "enemy.h"
enemy::enemy()
{
    rect.setSize(sf::Vector2f(90, 100));
    rect.setPosition(200, 200);
    rect.setFillColor(sf::Color::White);
    sprite.setTextureRect(sf::IntRect(0, 5, 100, 100));
}
void enemy::update()
{
    sprite.setPosition(rect.getPosition().x, rect.getPosition().y);
}
void enemy::updateMovement()
{


    if (direction == 1)
    {
        rect.move(-movementspeed, 0);
        //sprite.setTextureRect(sf::IntRect(movementspeed * 116, 116 * 1, 116, 116));

    }
    else if (direction == 2)
    {
        rect.move(movementspeed, 0);
        //sprite.setTextureRect(sf::IntRect(movementspeed * 116, 116 * 2, 116, 116));

    }
    else if (direction == 3)
    {
        rect.move(0, -movementspeed);
        //sprite.setTextureRect(sf::IntRect(movementspeed * 116, 116 * 3, 116, 116));

    }
    else if (direction == 4)
    {
        rect.move(0, movementspeed);
        //sprite.setTextureRect(sf::IntRect(movementspeed * 116, 116 * 0, 116, 116));

    }
    else
    {

    }
    counterWallking++;
    if (counterWallking >= 50)
    {
        direction = generateRandom(15);
        counterWallking = 0;
    }
}
