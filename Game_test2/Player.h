#pragma once

#include "SFML/Graphics.hpp"
#include "Animation.h"

class Player
{
public:

	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);

	void Update(float deltaTime);

	void Draw(sf::RenderWindow& window);


	sf::RectangleShape getBody();

private:

	sf::RectangleShape	body;
	Animation			animation;
	unsigned int		row;
	float				speed;
	bool				faceRight;

	float _accel;
	float _speedX;
	float _speedY;
	float _speedCap;

};

