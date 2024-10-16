
#include "gameFunctions.h"

#include <filesystem>

Map map;


void Begin(const sf::Window& window, Resources resources)
{
	/*
	for (auto& file : std::filesystem::directory_iterator("./Assets/textures/"))
	{
		if (file.is_regular_file() && file.path().extension() == ".png")
		{

			resources.addElement(file.path().filename().string());
		}
	}
	*/

	manuallyAddTextures(resources);

	map.createCheckerboard(10, 10);


}

void Update(float deltaTime)
{


}

void Render(Renderer& renderer, Resources resources)
{
	

	//renderer.Draw(resources.getTexture("./Assets/textures/suspiciousBrick.png"), sf::Vector2f(), sf::Vector2f(2.0f, 2.0f));
	map.Draw(renderer);
}

void manuallyAddTextures(Resources resources)
{

	///addElement añade automaticamente el prefix "./Assets/textures/" por lo 
	//que solo se debe indicar el nombre del archivo y sue xtension


	std::string path = {};

	path = "suspiciousBrick.png";

	resources.addElement(path);


	return;

}
