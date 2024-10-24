#include "Interface.h"

Interface::Interface()
{
	/*
	currentHP = -1;
	currentMana = -1;
	currentExp = -1;
	*/

	font.loadFromFile("./Assets/fonts/Typewriter.ttf");
	HpText.setFont(font);
	HpText.setFillColor(sf::Color::Red);
	HpText.setCharacterSize(32);
	HpText.setScale(sf::Vector2f(0.25f, 0.25f));

	ManaText.setFont(font);
	ManaText.setFillColor(sf::Color::Blue);
	ManaText.setCharacterSize(32);
	ManaText.setScale(sf::Vector2f(0.25f, 0.25f));

	ExpText.setFont(font);
	ExpText.setFillColor(sf::Color::White);
	ExpText.setCharacterSize(32);
	ExpText.setScale(sf::Vector2f(0.25f, 0.25f));
	
	LevelText.setFont(font);
	LevelText.setFillColor(sf::Color::Yellow);
	LevelText.setCharacterSize(32);
	LevelText.setScale(sf::Vector2f(0.25f, 0.25f));



}

void Interface::Update(Player player, sf::View view)
{
	sf::Vector2f viewPos  = view.getCenter();
	sf::Vector2f viewSize = view.getSize();



	HpText.setString(std::string("HP:   ") + std::to_string(player.getHP()));
	HpText.setPosition(viewPos.x - viewSize.x / 2 + 1, viewPos.y - viewSize.y / 2 );

	ManaText.setString(std::string("MANA: ") + std::to_string(player.getMana()));
	ManaText.setPosition(viewPos.x - viewSize.x / 2 + 1, viewPos.y - viewSize.y / 2 + 8);

	ExpText.setString(std::string("EXP:  ") + std::to_string(player.getExp()));
	ExpText.setPosition(viewPos.x - viewSize.x / 2 + 1, viewPos.y - viewSize.y / 2 + 16);

	LevelText.setString(std::string("LEVEL:  ") + std::to_string(player.getLevel()));
	LevelText.setPosition(viewPos.x - viewSize.x / 2 + 1, viewPos.y - viewSize.y / 2 + 24);
	

}

void Interface::Draw(sf::RenderWindow& window)
{
	window.draw(HpText);
	window.draw(ManaText);
	window.draw(ExpText);
	window.draw(LevelText);
//	window.draw(HpText);


}
