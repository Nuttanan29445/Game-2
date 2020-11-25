#include "Player.h"
#include "Animation.h"
#include <iostream>
Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
    animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    this->jumpHeight = jumpHeight;
    row = 0;
    faceRight = true;

    body.setSize(sf::Vector2f(60, 60));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(0.f, 0.f);
    body.setScale(1.0, 1.0);
    body.setTexture(texture);
    //Sound
    soundJump.loadFromFile("JumpSOUND.wav");
    sJump.setBuffer(soundJump);
    sJump.setVolume(15.0);
    //Jump
    
    
    
}

Player::~Player()
{

}

bool Player::getFaceRight()
{
    return this->faceRight;
}

void Player::Update(float deltaTime)
{
    

    velocity.x *= 0.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        velocity.x -= speed;

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        velocity.x += speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
    {

        sJump.play();
        velocity.y = -sqrt(2.0f * 981.0f * jumpHeight);
        canJump = false;

    }
    velocity.y += 981.0f * deltaTime;


    if (velocity.x == 0.0f )
    {
        row = 0;
    }
    if (velocity.x != 0.0f)
    {
        row = 1;
        if (velocity.x > 0.0f)
            faceRight = true;
        else
            faceRight = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        row = 2;
    }
    

   

    animation.Update(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);

    body.move(velocity * deltaTime);
    
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}

void Player::onCollision(sf::Vector2f direction)
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

void Player::setPosition(float x, float y)
{
    body.setPosition(x, y);
}
