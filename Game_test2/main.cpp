#include <iostream>
#include <SFML/Graphics.hpp>
#include "gameFunctions.h"
#include "Camera.h"
#include "Renderer.h"
#include "Resources.h"
#include "Player.h"


int main()
{
    ///precalculos


    ///ventana de juego

    sf::RenderWindow window(sf::VideoMode(1200, 900), "PORNO FURRY");


    ///inicializar sistemas
    sf::Event evento;


    sf::Clock GlobalClock;

    Camera camara(20.0f);

    Resources resources;

    Renderer renderer(window);

    window.setFramerateLimit(75);

    ///inicializar entidades

    Begin(window, resources);


    sf::RectangleShape cube1(sf::Vector2f(15.0f, 15.0f));
    sf::RectangleShape cube2(sf::Vector2f(10.0f, 12.0f));
    sf::RectangleShape cube3(sf::Vector2f(6.0f, 10.0f));

    cube1.setPosition(sf::Vector2f(15.0f, 0.0f));
    cube1.setFillColor(sf::Color::Yellow);
    cube2.setPosition(sf::Vector2f(10.0f, 0.0f));
    cube2.setFillColor(sf::Color::Yellow);
    cube3.setPosition(sf::Vector2f(6.0f, 0.0f));
    cube3.setFillColor(sf::Color::Yellow);



    sf::Texture playerTexture;
    playerTexture.loadFromFile("./Assets/sprites/Shujinko.png");


    Player akasan(&playerTexture,sf::Vector2u(4,6), 0.3f,  10.0f);


    float deltaTime = 0.0f;

    sf::Clock deltaClock;
    ///fondo


    ///BUCLE DE JUEGO

    int i = 70;
    
    while(window.isOpen())
    {
        deltaTime = deltaClock.restart().asSeconds();
        


        while(window.pollEvent(evento))
        {
            if(evento.type == evento.Closed)
                {
                window.close();
                }
            

        }

        window.setView(camara.getView(window.getSize(), akasan.getBody().getPosition()));

        Update(deltaTime);
        akasan.Update(deltaTime);


        window.clear(sf::Color::Color(i,i,i,255));

        ///draw

        window.draw(cube1);
        window.draw(cube2);
        window.draw(cube3);

        akasan.Draw(window);

        //Render(renderer, resources);


        window.display();

        std::cout<<deltaClock.getElapsedTime().asMilliseconds()<<std::endl;


    }

    return 0;
}
