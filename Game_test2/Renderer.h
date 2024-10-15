#pragma once
#include "SFML/Graphics.hpp"
class Renderer
{
public:

	Renderer(sf::RenderTarget& target);

	void Draw(const sf::Texture& texture, const sf::Vector2f& position, const sf::Vector2f& size);

private:
	sf::Sprite _sprite{};
	sf::RenderTarget& _target;

};

