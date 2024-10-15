
#include "gameFunctions.h"

#include <filesystem>



void Begin(const sf::Window& window, Resources resources)
{
	for (auto& file : std::filesystem::directory_iterator("./Assets/textures/"))
	{
		if (file.is_regular_file() && file.path().extension() == ".png")
		{

			resources.addElement(file.path().filename().string());
		}
	}

}

void Update(float deltaTime)
{


}

void Render(Renderer& renderer, Resources resources)
{
	renderer.Draw(resources.getTexture("./Assets/textures/suspiciousBrick.png"), sf::Vector2f(), sf::Vector2f(2.0f, 2.0f));

}