#include "Map.h"

Map::Map(float cellSize):
	_cellSize(cellSize), grid()
{

}

void Map::createCheckerboard(size_t width, size_t height)
{
	//dificil de explicar pero en c++14 hay que castear todos los tipos de dato manualmente
	//en c++17 es mucho mas legible, el 0 indica que se deben inicializar en 0 al no dar valor
	// 
	//	grid = std::vector(width, std::vector(height, 0));

	grid = std::vector<std::vector<int>>(width, std::vector<int>(height, 0));

	bool last = 0;

	for (auto& column : grid)
	{

		for (auto& cell : column)
		{
			cell = !last;
			last = cell;
		}
		if (width % 2 == 0) {
			last = !last;
		}


	}
	
}

void Map::createFromImage(const sf::Image image)
{
	grid.clear();

	grid = std::vector<std::vector<int>>(image.getSize().x, std::vector<int>(image.getSize().y, 0));

	for (size_t x = 0; x < grid.size(); x++)
	{

		for (size_t y = 0; y < grid[x].size(); y++)
		{

			sf::Color color = image.getPixel(x, y);
			if (color.r == sf::Color::Black.r)
				grid[x][y] = 1;


		}

	}

}

void Map::Draw(Renderer& renderer)
{
	int x = 0;
	for (const auto& column : grid)
	{
		int y = 0;
		for (const auto& cell : column)
		{
			if (cell)
			{
				renderer.Draw(Resources::getTexture("suspiciousBrick.png"), 
					sf::Vector2f(_cellSize * x + _cellSize / 2.0f, _cellSize * y + _cellSize / 2.0f),
					sf::Vector2f(_cellSize,_cellSize));
			}
			y++;

		}
		x++;


	}

}

