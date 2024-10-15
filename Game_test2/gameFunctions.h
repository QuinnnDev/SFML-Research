#pragma once

#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H

#include "SFML/Graphics.hpp"
#include "Renderer.h"


void Begin(const sf::Window& window);

void Update(float deltaTime);

void Render(Renderer& renderer);




#endif // GAMEFUNCTIONS_H