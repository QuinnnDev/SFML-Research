#include "EntityManager.h"

EntityManager::EntityManager(int maxCapacity, float spawnCooldown,  sf::RenderWindow& window):
	window(window)
{
	this->maxCapacity = maxCapacity;

	this->spawnCooldown = spawnCooldown;



}

void EntityManager::Update(float deltaTime, sf::Vector2f target)
{

	//updatear los enemigos
	for (auto& enemy : enemiesAlive)
	{
		enemy.Update(deltaTime, target);

	}

	//agregar enemigos al vector
	for (auto& enemy : enemiesAlive)
	{
		
		spawnCooldown -= deltaTime;

		if (spawnCooldown <= 0 && enemiesAlive.size() <= maxCapacity) {

			sf::Texture texture;

			enemyTexture.loadFromFile("./Assets/sprites/Enemy.png");


			Enemy enemy(&enemyTexture, sf::Vector2u(6, 8), 0.3f, 10.0f, window);

			enemiesAlive.push_back(enemy);

			std::cout << "enemigo creado con exito" << std::endl;
		}


	}

	int index = 0;
	//eliminar enemigos muertos del vector
	for (auto& enemy : enemiesAlive)
	{
		
		if (enemy.getHP() <= 0) {

		enemiesAlive.erase(enemiesAlive.begin() + index);
		index--;
		}
		index++;

	}




}

void EntityManager::Draw()
{
	for (auto& enemy : enemiesAlive)
	{

		enemy.Draw();

	}


}

void EntityManager::checkCollisions(Collider attack, int dmg)
{
	for (auto& enemy : enemiesAlive)
	{
		if (enemy.getCollider().checkCollision(attack)) {

			enemy.takeDmg(dmg);

		}

	}

}

void EntityManager::checkEnemyCollisions()
{
	int indexI = 0;

	for (auto& enemy : enemiesAlive)
	{

		int indexJ = 0;

		for (auto& otherEnemy :enemiesAlive)
		{
			if (indexI != indexJ) {

				enemy.getCollider().checkSolidCollision(otherEnemy.getCollider(), 0.25f);

			}
			indexJ++;

		}//for int
		indexI++;

	}//for ext



}



