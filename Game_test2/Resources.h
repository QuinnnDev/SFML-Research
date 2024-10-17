#pragma once

#include <vector>
#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>

class Resources
{
public:


	static bool addElement(std::string path);
	static std::string getPath(int i);
	static sf::Texture getTexture(std::string path);
	static int getSize();

private:
	static int getPosition(std::string path);
	static std::string addPrefix(std::string filename);


	static std::vector<std::string> texturePath;
	static std::vector<sf::Texture> textureKey;

private:


	
};

