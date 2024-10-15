#pragma once

#include <unordered_map>
#include <vector>
#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>

static class Resources
{
public:


	bool addElement(std::string path);
	int getPosition(std::string path);
	std::string getPath(int i);
	sf::Texture getTexture(std::string path);
	int getSize();

	std::string addPrefix(std::string filename);


	static std::vector<std::string> texturePath;
	static std::vector<sf::Texture> textureKey;

private:


	
};

