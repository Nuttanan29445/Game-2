#pragma once
#include <SFML/Graphics.hpp>
class bulletEnemy
{
public:
    bulletEnemy(sf::Texture* texture, float speed, float posx, float posy, float dirx, float diry);
  
    ~bulletEnemy();

    sf::FloatRect GetGlobalBounds() { return body.getGlobalBounds(); }\
       void setPosition(float x, float y);

    void Update();
    void Render(sf::RenderWindow& window);
    
private:

   
    float speed;
    sf::RectangleShape body;
    sf::Vector2f direction;
    sf::Vector2f velocity;
   
};

