#include "Resources.h"

std::vector<std::string> Resources::texturePath{};
std::vector<sf::Texture> Resources::textureKey{};


bool Resources::addElement(std::string path)
{
	sf::Texture temp;

	path = addPrefix(path);
	
	if (!temp.loadFromFile(path)) {

		std::cout <<"a "<< path << std::endl;
		std::cout << "Texture couldn't be loaded" << std::endl;
		return false;
	}

	texturePath.push_back(path);
	textureKey.push_back(temp);

	std::cout << " path vect size " << texturePath.size() << std::endl;

	return true;
}

int Resources::getPosition(std::string path)
{
	int size = texturePath.size();
	std::cout <<" b " << path << std::endl;

	for (int i = 0; i < size; i++) 
	{
		std::cout << getPath(i) << " y " << path<<std::endl;

		if (getPath(i) == path) {

			return i;

		}



	}

	std::cout << "Error: texture not found" << std::endl;
	return -1;

}

std::string Resources::getPath(int i)
{
	return texturePath[i];
}

sf::Texture Resources::getTexture(std::string path)
{
	int pos = getPosition(path);

	return textureKey[pos];
}

int Resources::getSize()
{
	return texturePath.size();
}

std::string Resources::addPrefix(std::string filename)
{
	std::string prefix = "./Assets/textures/";

	std::string fullPath = prefix + filename;


	return fullPath;
}
