#include "Enemyfly.h"
#include "Animation.h"
#include <iostream>
Enemyfly::Enemyfly(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f position) :
    animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    row = 0;
    faceRight = true;

    body.setSize(sf::Vector2f(60, 60));
    body.setOrigin(body.getSize() / 2.0f);
    body.setScale(1.0, 1.0);
    body.setTexture(texture);
    body.setPosition(position);
    //Sound
    soundJump.loadFromFile("JumpSOUND.wav");
    sJump.setBuffer(soundJump);
    sJump.setVolume(15.0);
    //Jump



}

Enemyfly::~Enemyfly()
{

}

void Enemyfly::Update(float deltaTime)
{
    int r = rand() % 4;
   

    velocity.y *= 0.0f;
   

    if (r == 0 || r == 2)
    {
        velocity.y -= speed;

    }
    else if (r == 1 || r == 3)
    {
        velocity.y += speed;
    }
    
    /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
    {
        sJump.play();
        velocity.y = -sqrt(2.0f * 981.0f * jumpHeight);
        canJump = false;

    }*/

    /* velocity.y += 981.0f * deltaTime;*/


     /*if (velocity.x == 0.0f)
     {
         row = 0;
     }*/
    
    if (velocity.y != 0.0f)
    {
        row = 0;
        if (velocity.y > 0.0f)
            faceRight = false;
        else
            faceRight = true;
    }
    if (velocity.x != 0.0f)
    {
        row = 0;
        if (velocity.x > 0.0f)
            faceRight = false;
        else
            faceRight = true;
    }

    animation.Update(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);
    
     body.move(velocity * deltaTime);
    
}

void Enemyfly::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}



void Enemyfly::onCollision(sf::Vector2f direction)
{
    if (direction.x < 0.0f)
    {
        velocity.x = 0.0f;
    }
    else if (direction.x > 0.0f)
    {
        velocity.x = 0.0f;
    }
    if (direction.y < 0.0f)
    {
        velocity.y = 0.0f;
        canJump = true;
    }
    else if (direction.y > 0.0f)
    {
        velocity.y = 0.0f;
    }
}

void Enemyfly::setPosition(float x, float y)
{
    body.setPosition(x, y);
}
void Enemyfly::getPosition(float x, float y)
{
    body.getPosition();
}


