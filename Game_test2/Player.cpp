#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed):
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(5.0f, 7.5f));

	body.setPosition(sf::Vector2f(0.0f, 0.0f));
	body.setOrigin(body.getSize() / 2.0f);

	body.setTexture(texture);
}

void Player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		movement.x -= speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x += speed * deltaTime;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		row = 5;
		movement = {};
	}
	else
	{ 
		if (movement.x == 0.0f)
			row = 0;
		else
			row = 1;

		if (movement.x > 0.0f)
			faceRight = true;
		else if (movement.x == 0)
			;
		else
			faceRight = false;
	}



	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

sf::RectangleShape Player::getBody()
{
	return body;
}
