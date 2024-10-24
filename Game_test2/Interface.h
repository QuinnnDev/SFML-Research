#pragma once

#include "SFML/Graphics.hpp"
#include "Player.h"
#include <string>


class Interface
{
public:

	Interface();

	void Update(Player player, sf::View view);

	void Draw(sf::RenderWindow& window);



private:

	/*
	int currentHP;
	int currentMana;
	int currentExp;
	*/


	///funcionalidades

	sf::Font font;

	sf::Text HpText;
	sf::Text ManaText;
	sf::Text ExpText;
	sf::Text LevelText;

};

