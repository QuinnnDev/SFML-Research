#include "Player.h"
#include <iostream>

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::RenderWindow& window) :
	animation(texture, imageCount, switchTime), window(window)
{
	playerLevel = 1;

	playerHP = 100 + playerLevel*10;
	playerMana = 75 + playerLevel*10;
	playerExp = 0;
	attackManaCost = 20 - int(playerLevel*5);


	this->speed = speed;
	attackCooldown = 1.0f;
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(5.0f, 7.5f));

	body.setPosition(sf::Vector2f(0.0f, 0.0f));
	body.setOrigin(body.getSize() / 2.0f);

	body.setTexture(texture);
}

void Player::Update(float deltaTime, sf::Vector2f mousePos)
{
	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		movement.x -= speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x += speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		movement.y -= speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		movement.y += speed * deltaTime;

	if(attackCooldown>0.0f)
		attackCooldown -= deltaTime;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&  attackCooldown <= 0.0f){

		if (playerMana >= attackManaCost) {
			playerMana -= attackManaCost;
			attackCooldown = 0.75f;
			newMagicAttack(mousePos);
			std::cout << "cantidad de magia: " << attacks.size() << std::endl;
		}
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		row = 5;
		movement = {};
		playerMana += 5 * deltaTime;
	}
	else
	{ 
		if (movement.x == 0.0f && movement.y == 0.0f)
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

	//level up

	int currentLevel = playerLevel;

	if (playerExp / 100 > currentLevel) {
		playerLevel++;

		playerHP = 100 + playerLevel * 10;
		playerMana = 75 + playerLevel * 10;
		playerExp = 0;
		attackManaCost = 20 - int(playerLevel * 5);
	}

	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);

	///eliminar los ataques expirados
	for (auto i = attacks.begin(); i < attacks.end(); )
	{
		if (i->isExpired()) {
			i = attacks.erase(i);
		}
		else {
			i++;
		}
	}

	for (MagicAttack& current : attacks)
	{
		if (!current.isExpired()) {
			current.Update(deltaTime);
		}
	}
}

void Player::Draw()
{
	window.draw(body);


	for(MagicAttack& attack : attacks)
	{
		attack.Draw(window);
		//std::cout << "ataque dibujado" << std::endl;
	}
}

sf::RectangleShape Player::getBody()
{
	return body;
}

Collider Player::getCollider()
{
	return Collider(body);
}

std::vector<MagicAttack> Player::getActiveAttacks()
{

	return std::vector<MagicAttack>(attacks);
}

void Player::newMagicAttack(sf::Vector2f mousePos)
{
	
	if (attacks.size() < 5)
	{
		
		if (!MagicTexture.loadFromFile("./Assets/sprites/magicAttackGrey.png")) {
			std::cout << "ERROR" << std::endl;
			exit(-1);
		}


		MagicAttack attack(&MagicTexture, sf::Vector2u(6, 24), 0.1f, mousePos);

		attacks.push_back(attack);

		std::cout << "ataque creado con exito" << std::endl;

	}
}
