
#include "gameFunctions.h"

sf::CircleShape circle(2.0f, 360);

void Begin(const sf::Window& window)
{
	circle.setOrigin(sf::Vector2f(circle.getRadius(), circle.getRadius() ));
	//circle.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
	circle.setFillColor(sf::Color::Yellow);
	//circle.setPointCount(60);

}

void Update(float deltaTime)
{


}

void Render(sf::RenderWindow& window)
{
	window.draw(circle);

}