#pragma once

#include "SFML/Graphics.hpp"
#include "Animation.h"
#include "MagicAttack.h"
#include "Collider.h"
#include <vector>

class Player
{
public:

	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::RenderWindow& window);

	void Update(float deltaTime, sf::Vector2f mousePos);

	void Draw();


	sf::RectangleShape getBody();

	Collider getCollider();

	std::vector<MagicAttack> getActiveAttacks();


private:

	void newMagicAttack(sf::Vector2f mousePos);

private:

	sf::RectangleShape	body;
	Animation			animation;
	unsigned int		row;
	float				speed;
	bool				faceRight;

	std::vector<MagicAttack> attacks;
	sf::Texture MagicTexture;
	float attackCooldown;

	sf::RenderWindow& window;


};

