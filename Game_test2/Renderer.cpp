#include "Renderer.h"

Renderer::Renderer(sf::RenderTarget& target):
	_target(target)
{
}

void Renderer::Draw(const sf::Texture& texture, const sf::Vector2f& position, const sf::Vector2f& size)
{
	
	_sprite.setTexture(texture);
	_sprite.setOrigin((sf::Vector2f)texture.getSize() / 2.0f);
	_sprite.setPosition(position);
	_sprite.setScale(sf::Vector2f(size.x/ texture.getSize().x, size.y / texture.getSize().y));
	//_sprite.setOrigin();
	_target.draw(_sprite);

}

