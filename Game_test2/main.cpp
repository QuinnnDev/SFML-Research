#include <iostream>
#include <SFML/Graphics.hpp>
#include "gameFunctions.h"
#include "Camera.h"


int main()
{
    ///precalculos


    ///ventana de juego

    sf::RenderWindow window(sf::VideoMode(1200, 900), "SFML TAB");


    ///inicializar sistemas
    sf::Event evento;

    sf::Clock deltaClock;

    Camera camara(0.05);

    window.setFramerateLimit(75);

    ///inicializar entidades

    Begin(window);

    ///fondo


    ///BUCLE DE JUEGO

    int i = 0;
    
    while(window.isOpen())
    {
        float deltaTime = deltaClock.restart().asSeconds();
        


        while(window.pollEvent(evento))
        {
            if(evento.type == evento.Closed)
                {
                window.close();
                }

        }

        window.setView(camara.getView(window.getSize()));

        Update(deltaTime);

        window.clear(sf::Color::Color(i,i,i,255));

        ///draw

        Render(window);


        window.display();

        std::cout<<deltaClock.getElapsedTime().asMilliseconds()<<std::endl;


    }

    return 0;
}
