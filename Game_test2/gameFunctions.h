#pragma once

#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H

#include "SFML/Graphics.hpp"
#include "Renderer.h"
#include "Resources.h"


void Begin(const sf::Window& window, Resources resources);

void Update(float deltaTime);

void Render(Renderer& renderer, Resources resources);




#endif // GAMEFUNCTIONS_H