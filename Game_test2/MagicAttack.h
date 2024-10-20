#pragma once

#include "SFML/Graphics.hpp"
#include "Animation.h"

class MagicAttack
{
public:

	MagicAttack(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f mousePos);
	~MagicAttack();

	void Update(float deltaTime);

	void Draw(sf::RenderWindow& window);

	bool isExpired();


private:

	sf::RectangleShape body;
	Animation animation;

	unsigned int row;

	float duration;

	bool expired;

};

