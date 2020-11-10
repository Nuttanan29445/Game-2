#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
class Player
{
public:
	Player(sf::Vector2f size, sf::Texture *texture) {
		this->player.setSize(size);
		this->player.setTexture(texture);


		//Initialized Funcitons
		this->initVariables();
	}
	void drawTo(sf::RenderWindow& window)
	{
		window.draw(this->player);
	}
	void move(sf::Vector2f distance)
	{
		this->player.move(distance);
	}
	void setPosition(sf::Vector2f newPos)
	{
		this->player.setPosition(newPos);
	}
	sf::Vector2f getPosition()
	{
		return this->player.getPosition();
	}

	void jump()
	{
		this->speedValue -= this->gravityAcceleration;
		this->player.move(0, -speedValue);
	}

	void setJump(int buff)
	{
		int temp = buff;
		if (temp == 1) {
			this->isJumping = true;
		}
		else
		{
			this->isJumping = false;
		}
	}
	bool isJump()
	{
		return this->isJumping;
	}
	void initVariables()
	{
		this->mass = 20.f;
		this->isJumping = false;
		this->speedValue = 0.f;
		this->gravityAcceleration = 10.f;
		this->jumpForce = 2000.f;
	}
	void setSpeedValue()
	{
		this->speedValue = this->jumpForce / this->mass;
	}

	void update()
	{
		//*std::cout << this->speedValue << std::endl;
	}
private:
		sf::RectangleShape player;
		sf::Texture playerTexture;

		//Jump Mechanic
		float speedValue;
		float gravityAcceleration;
		float jumpForce;
		float mass;
		bool isJumping;
};