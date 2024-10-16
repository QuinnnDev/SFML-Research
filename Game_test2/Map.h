#pragma once

#include <vector>
#include "Renderer.h"
#include "Resources.h"
class Map
{
public:

	Map(float cellSize = 5.0f);

	void createCheckerboard(size_t width, size_t height);

	void Draw(Renderer& renderer);


	std::vector<std::vector<int>> grid;
	float _cellSize;

private:


};

