
#include "gameFunctions.h"


Map map;


void Begin(const sf::Window& window, Resources resources)
{

	///aca deberia precargar cosas como texturas etc.

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

	sf::Image image;
	image.loadFromFile("./Assets/maps/map1.png");
	map.createFromImage(image);

}

void Update(float deltaTime)
{
	///aca deberia cargar las interacciones y cambios de estado de elementos del juego

	

}

void Render(Renderer& renderer, Resources resources)
{
	//aca deberia cargar todo lo que se vea en pantalla



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
