#pragma once

#include "SFML/Graphics.hpp"
#include "Collider.h"
#include "Animation.h"
#include <math.h>

class Enemy
{
public:

	Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::RenderWindow& window);

	void Update(float deltaTime, sf::Vector2f target);


	void Dies();

	void Draw();

	void setPosition(sf::Vector2f position);


	sf::RectangleShape getBody();

	int const getHP() { return hp; }

	void takeDmg(int dmgTaken) { hp -= dmgTaken; }

	Collider getCollider();

	bool const isAlive() { return alive; }


private:

	void moveTowardsTarget(float deltaTime);

	void enemyDying(float deltaTime);

private:

	//stats

	int hp;

	float speed;

	//funcionalidades

//	unsigned int		id;

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

