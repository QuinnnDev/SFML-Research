#include "Enemy.h"

Enemy::Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::RenderWindow& window) :

	animation(texture, imageCount, switchTime), window(window)
{
	expGiven = 15;


	dyingTimeDef = switchTime * (6.0f);
	dyingTime = dyingTimeDef;
	row = 0;
	faceRight = true;
	alive = true;
	paused = false;

	body.setSize(sf::Vector2f(5.0f, 7.5f));

	body.setPosition(sf::Vector2f(0.0f, 0.0f));
	body.setOrigin(body.getSize() / 2.0f);

	body.setTexture(texture);

}

void Enemy::Update(float deltaTime)
{


	if (alive) {
		dyingTime = dyingTimeDef;
		row = 0;
		animation.Update(row, deltaTime, faceRight);
		body.setTextureRect(animation.uvRect);
	}
	else
	{
		enemyDying(deltaTime);
	}

}

void Enemy::Dies()
{
	alive = false;
}

void Enemy::Draw()
{

	window.draw(body);

}

void Enemy::setPosition(sf::Vector2f position)
{

	body.setPosition(position);

}

sf::RectangleShape Enemy::getBody()
{
	return sf::RectangleShape();
}

Collider Enemy::getCollider()
{
	return Collider(body);
}



void Enemy::enemyDying(float deltaTime)
{

	dyingTime -= deltaTime;

	row = 5;

	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);

	if (dyingTime <= 0) {
		alive = true;

	}


}
