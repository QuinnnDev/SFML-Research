#pragma once

#include "SFML/Graphics.hpp"

class Collider
{
public:
    Collider(sf::RectangleShape& body);


    void move(float dx, float dy);

    bool checkSolidCollision(Collider other, float push);

    bool checkCollision(Collider other);



    sf::Vector2f getPosition();
    sf::Vector2f getHalfSize();


private:

    sf::RectangleShape& _body;
};
