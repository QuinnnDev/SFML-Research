#pragma once

#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H

#include "SFML/Graphics.hpp"


void Begin(const sf::Window& window);

void Update(float deltaTime);

void Render(sf::RenderWindow& window);




#endif // GAMEFUNCTIONS_H