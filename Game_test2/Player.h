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


	///getters stats

	int getLevel() { return playerLevel; }

	void expGain(int enemyExp) { playerExp += enemyExp;}

	int getHP() { return playerHP; }
	int getMana() { return playerMana; }
	int getExp() { return playerExp; }


private:

	void newMagicAttack(sf::Vector2f mousePos);

private:

	///stats

	int				playerLevel;

	int				playerHP;
	float			playerMana;
	int				playerExp;
	float			speed;

	float			attackCooldown;
	float			attackManaCost;

	///funcionalidades
	sf::RectangleShape	body;
	Animation			animation;
	unsigned int		row;
	bool				faceRight;

	std::vector<MagicAttack> attacks;
	sf::Texture MagicTexture;

	sf::RenderWindow& window;


};

