
#include "gameFunctions.h"

sf::Texture textu;



void Begin(const sf::Window& window)
{
	if (!textu.loadFromFile("Assets/suspiciousBrick.png")) {
		exit(-1);
	}

}

void Update(float deltaTime)
{


}

void Render(Renderer& renderer)
{
	renderer.Draw(textu, sf::Vector2f(0.0f, 0.0f), sf::Vector2f(2.0f, 2.0f));

}