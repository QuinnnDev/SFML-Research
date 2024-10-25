#pragma once

#include "SFML/Graphics.hpp"
#include "Collider.h"
#include "Animation.h"
#include <math.h>

class Enemy
{
public:

	Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, int id, sf::RenderWindow& window);

	void Update(float deltaTime, sf::Vector2f target);


	void Dies();

	void Draw();

	void setPosition(sf::Vector2f position);


	sf::RectangleShape getBody();

	unsigned int getID() { return id; }

	Collider getCollider();

	bool isAlive() { return alive; }

private:

	void moveTowardsTarget();

	void enemyDying(float deltaTime);

private:

	//stats

	float speed;

	//funcionalidades

	unsigned int		id;

	sf::Vector2f		target;

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

