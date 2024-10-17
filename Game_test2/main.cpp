#include <iostream>
#include <SFML/Graphics.hpp>
#include "gameFunctions.h"
#include "Camera.h"
#include "Renderer.h"
#include "Resources.h"


int main()
{
    ///precalculos


    ///ventana de juego

    sf::RenderWindow window(sf::VideoMode(1200, 900), "PORNO FURRY");


    ///inicializar sistemas
    sf::Event evento;

    sf::Clock deltaClock;

    sf::Clock GlobalClock;

    Camera camara(75.0f);

    Resources resources;

    Renderer renderer(window);

    window.setFramerateLimit(75);

    ///inicializar entidades

    Begin(window, resources);

    ///fondo


    ///BUCLE DE JUEGO

    int i = 70;
    
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

        window.setView(camara.getView(window.getSize(), sf::Vector2f(30.0f, 30.0f)) );

        Update(deltaTime);

        window.clear(sf::Color::Color(i,i,i,255));

        ///draw

        Render(renderer, resources);


        window.display();

        std::cout<<deltaClock.getElapsedTime().asMilliseconds()<<std::endl;


    }

    return 0;
}
