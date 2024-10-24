#pragma once

#include "SFML/Graphics.hpp"
#include "Collider.h"
#include "Animation.h"

class Enemy
{
public:

	Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::RenderWindow& window);

	void Update(float deltaTime);


	void Dies();

	void Draw();

	void setPosition(sf::Vector2f position);


	sf::RectangleShape getBody();

	Collider getCollider();

	bool isAlive() { return alive; }

private:

	void enemyDying(float deltaTime);

private:

	//stats


	//funcionalidades
	sf::RectangleShape	body;
	Animation			animation;
	unsigned int		row;
	bool				faceRight;

	bool				alive;
	float				dyingTime;
	float				dyingTimeDef;

	bool				paused;

	sf::RenderWindow& window;

public:

	int expGiven;
};

