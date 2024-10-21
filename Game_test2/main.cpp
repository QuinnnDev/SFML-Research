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

    Camera camara(40.0f);

    Resources resources;

    Renderer renderer(window);

    window.setFramerateLimit(75);

    ///inicializar entidades

    Begin(window, resources);

    sf::Vector2f mousePos; ///saca la posicion relativa al mouse en al ventana respecto al mapa,
                           ///porque la funcion de sfml es una mrd


    sf::RectangleShape cube1(sf::Vector2f(15.0f, 15.0f));
    sf::RectangleShape cube2(sf::Vector2f(10.0f, 12.0f));
    sf::RectangleShape cube3(sf::Vector2f(6.0f, 10.0f));
    sf::CircleShape  circle1(3.0f);

    cube1.setPosition(sf::Vector2f(15.0f, 0.0f));
    cube1.setFillColor(sf::Color::Yellow);
    cube2.setPosition(sf::Vector2f(10.0f, 0.0f));
    cube2.setFillColor(sf::Color::Yellow);
    cube3.setPosition(sf::Vector2f(6.0f, 0.0f));
    cube3.setFillColor(sf::Color::Yellow);
    
    circle1.setPosition(sf::Vector2f(0.0f, 0.0f));
    circle1.setFillColor(sf::Color::Black);



    sf::Texture playerTexture;
    playerTexture.loadFromFile("./Assets/sprites/Shujinko.png");
    

    Player akasan(&playerTexture,sf::Vector2u(4,6), 0.3f,  10.0f, window);


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

        mousePos = sf::Vector2f(sf::Mouse::getPosition(window));

        mousePos = (mousePos - sf::Vector2f(window.getSize() / 2u));
        mousePos = mousePos / 23.0f;    
        /*
        /// NI PUTA IDEA DE COMO SACAR ESTE VALOR POR EL QUE DIVIDO PERO SIGUE LA SIGUIENTE FORMULA
         f(x) = 90/0.1x          (recomendacion, usar desmos para sacar los valores)
        */
        mousePos = mousePos + akasan.getBody().getPosition();

           
        
        akasan.Update(deltaTime, mousePos);


        window.clear(sf::Color::Color(i,i,i,255));

        ///draw

        window.draw(cube1);
        window.draw(cube2);
        window.draw(cube3);
        window.draw(circle1);

        akasan.Draw();

        //Render(renderer, resources);


        window.display();

        //std::cout<<deltaClock.getElapsedTime().asMilliseconds()<<std::endl;


    }

    return 0;
}
