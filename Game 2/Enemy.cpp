#include "Enemy.h"
#include "Animation.h"
#include "bulletEnemy.h"
#include <iostream>
Enemy::Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f position) :
    animation(texture, imageCount, switchTime)
{

    this->initTexture();
    this->speed = speed;
    row = 0;
    faceRight = true;

    this->hp = 3;

    body.setSize(sf::Vector2f(80, 80));
    body.setOrigin(body.getSize() / 2.0f);
    body.setScale(1.0, 1.0);
    body.setTexture(texture);
    body.setPosition(position);
    //Sound
    soundJump.loadFromFile("JumpSOUND.wav");
    sJump.setBuffer(soundJump);
    sJump.setVolume(15.0);
    



}

Enemy::~Enemy()
{
   /* for (auto* bullet : bullets)
        delete bullet;*/
}

void Enemy::setHP(int x)
{
    this->hp -= x;
}

int Enemy::getHP()
{
    return this->hp;
}
       

void Enemy::Update(float deltaTime, Player* player)
{
    int r = rand() % 3;
    sf::Time cdShoot = clockShoot.getElapsedTime();

    velocity.x *= 0.0f;
    if (player->getPosition().x + 400 > body.getPosition().x)
    {
        if (r == 0)
        {
            velocity.x -= speed;

        }
        else if (r == 1)
        {
            velocity.x += speed;
        }
        else if (r == 2 && cdShoot.asSeconds() >= 0.2)
        {
            clockShoot.restart();
            if (faceRight == false)
                bullets.push_back(new bulletEnemy(&bulletTexture, 20.f, body.getPosition().x, body.getPosition().y, 1.0f, 0.0f));
            if (faceRight == true)
                bullets.push_back(new bulletEnemy(&bulletTexture, 20.f, body.getPosition().x, body.getPosition().y, -1.0f, 0.0f));
            row = 1;
        }
    }
    for (auto* bullet : bullets)
    {
        if (player->GetGlobalBounds().intersects(bullet->GetGlobalBounds()))
        {
            bullet->setPosition(-50.0f, -50.0f);
        }

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
    this->updateBullet();

    body.move(velocity * deltaTime);

}

void Enemy::Draw(sf::RenderWindow& window)
{
    window.draw(body);
    this->DrawBullet(window);
}

void Enemy::DrawBullet(sf::RenderWindow& window)
{
    for (auto* bullet : bullets)
        bullet->Render(window);
}

void Enemy::onCollision(sf::Vector2f direction)
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

void Enemy::setPosition(float x, float y)
{
    body.setPosition(x, y);
}

void Enemy::updateBullet()
{
    for (auto* bullet : bullets)
        bullet->Update();
}

void Enemy::initTexture()
{
    this->bulletTexture.loadFromFile("bullet.png");
}
