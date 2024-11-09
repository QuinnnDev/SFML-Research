#pragma once

#include "SFML/Graphics.hpp"
#include "Enemy.h"
#include "Collider.h"
#include <vector>
#include <iostream>


class EntityManager
{

public:

	EntityManager(int maxCapacity, float spawnCooldown, sf::RenderWindow& window);

	void Update(float deltaTime, sf::Vector2f target);

	void Draw();


	void checkCollisions(Collider attack, int dmg);

	void checkEnemyCollisions();

//	sf::Vector2f getNearestPosition(sf::Vector2f );

private:




private:

	float spawnCooldown;

	int maxCapacity;

	sf::Texture enemyTexture;

	std::vector<Enemy> enemiesAlive;
	
	sf::RenderWindow& window;
};

