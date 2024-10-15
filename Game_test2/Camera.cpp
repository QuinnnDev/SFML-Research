#include "Camera.h"
#include <iostream>

Camera::Camera(float zoomLevel)
	:zoomLevel(zoomLevel)
{
}

sf::View Camera::getView(sf::Vector2u windowSize, sf::Vector2f target)
{
	std::cout << target.x << " and " << target.y << std::endl;
	float aspect = (float)windowSize.x / (float)windowSize.y;
	sf::Vector2f size;

	if (aspect < 1.0f) {
		size = sf::Vector2f(zoomLevel, zoomLevel / aspect);
	}
	else {
		size = sf::Vector2f(zoomLevel * aspect, zoomLevel);
	}


	return sf::View(target, size);
}

