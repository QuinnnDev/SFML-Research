#pragma once

#include <vector>

#include "SFML/Graphics.hpp"

class Map
{
public:

	Map(float cellSize = 5.0f);

	void createCheckerboard(size_t width, size_t height);

	//void Draw(Renderer& renderer);
	void createFromImage(const sf::Image image);

public:
	std::vector<std::vector<int>> grid;
	float _cellSize;

private:


};

