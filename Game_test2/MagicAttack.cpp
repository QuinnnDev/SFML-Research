#include "MagicAttack.h"
#include <iostream>

MagicAttack::MagicAttack(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f mousePos):
		animation(texture, imageCount, switchTime)
{

	expired = false;
	duration = switchTime * imageCount.x - 0.1f;

	row = 0;
	std::cout << "mouse x,y en MA.cpp: " << mousePos.x<< " " << mousePos.y << std::endl;


	sf::Vector2f newMousePos = mousePos;
	body.setSize(sf::Vector2f(10.5f, 10.5f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(newMousePos);

	body.setTexture(texture);

	//std::cout << "Constructor realizado con exito" << std::endl;
	//std::cout << "switchTime: " << switchTime << ", imageCount.x: " << imageCount.x << std::endl;
}

MagicAttack::~MagicAttack()
{

}

void MagicAttack::Update(float deltaTime)
{
	//std::cout << "deltaTime: " << deltaTime << std::endl;

	if (!expired) {
		duration -= deltaTime;
		if (duration < 0.0f) {
			duration = -1.0f;
			expired = true;
		}
	}

	row = 6;

	//std::cout << "updateado con exito duration: " << duration << std::endl << "expired: " << expired << std::endl;

	animation.Update(row, deltaTime, true);
	body.setTextureRect(animation.uvRect);

	//std::cout << "uv width: " << animation.uvRect.width << std::endl;
	//std::cout<<"uv height " << animation.uvRect.height << std::endl;
	//std::cout<<"current image x: " << animation.currentImage.x << std::endl;
}

void MagicAttack::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

bool MagicAttack::isExpired()
{
	return expired;
}

sf::RectangleShape MagicAttack::getBody()
{
	return body;
}

Collider MagicAttack::getCollider()
{
	return Collider(body);
}
