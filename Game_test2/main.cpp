#include <iostream>
#include <SFML/Graphics.hpp>
#include "gameFunctions.h"
#include "Camera.h"
#include "Renderer.h"
#include "Resources.h"
#include "Player.h"
#include "Enemy.h"
#include "Interface.h"


int main()
{
    ///precalculos


    ///ventana de juego

    sf::RenderWindow window(sf::VideoMode(1200, 900), "PORNO FURRY");


    ///inicializar sistemas
    sf::Event evento;


    sf::Clock GlobalClock;

    Camera camara(70.0f);

    Resources resources;

    Interface interface;

    window.setFramerateLimit(75);

    ///inicializar entidades

    Begin(window, resources);

    sf::Vector2f mousePos; ///saca la posicion relativa al mouse en al ventana respecto al mapa,
                           ///porque la funcion de sfml es una mrd


    sf::RectangleShape cube1(sf::Vector2f(15.0f, 15.0f));
    sf::RectangleShape cube2(sf::Vector2f(10.0f, 12.0f));
    sf::RectangleShape cube3(sf::Vector2f(6.0f, 6.0f));
    sf::CircleShape  circle1(3.0f);

    cube1.setPosition(sf::Vector2f(15.0f, 0.0f));
    cube1.setFillColor(sf::Color::Yellow);
    cube2.setPosition(sf::Vector2f(10.0f, 0.0f));
    cube2.setFillColor(sf::Color::Yellow);
    cube3.setPosition(sf::Vector2f(6.0f, 10.0f));
    cube3.setFillColor(sf::Color::Red);
    
    circle1.setPosition(sf::Vector2f(0.0f, 0.0f));
    circle1.setFillColor(sf::Color::Black);


    float temporizadorSpawn = 1.0f;



    sf::Texture playerTexture;
    playerTexture.loadFromFile("./Assets/sprites/Shujinko.png");

    sf::Texture enemyTexture;
    enemyTexture.loadFromFile("./Assets/sprites/Enemy.png");
    

    Player akasan(&playerTexture,sf::Vector2u(4,6), 0.3f,  15.0f, window);

    std::vector<Enemy> enemigos;

    

    

    sf::View currentView;


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

        currentView = camara.getView(window.getSize(), akasan.getBody().getPosition());

        window.setView(currentView);

        Update(deltaTime);

        mousePos = sf::Vector2f(sf::Mouse::getPosition(window));

        mousePos = (mousePos - sf::Vector2f(window.getSize() / 2u));
        mousePos = mousePos / 13.1f;    

        /*
        NI PUTA IDEA DE COMO SACAR ESTE VALOR POR EL QUE DIVIDO PERO SIGUE LA SIGUIENTE FORMULA (por algun motivo)
        x = zoomLevel iniciado en el constructor de camara
         f(x) = 275/0.3x          (recomendacion, usar desmos graph para sacar los valores)
        */

        mousePos = mousePos + akasan.getBody().getPosition();

        ///UPDATES  
        
        akasan.Update(deltaTime, mousePos);
        


        ///si ataque colisiona
        for (auto& attack : akasan.getActiveAttacks())
        {
            for (auto& enemy : enemigos)
            {

                if (enemy.getCollider().checkCollision(attack.getCollider())) {
                    bool temp = enemy.isAlive();
                    enemy.Dies();
                    if (temp != enemy.isAlive())
                        akasan.expGain(enemy.expGiven);
                }
            }

        }
        
        temporizadorSpawn -= deltaTime;

        //el constructor daria problemas con el id si los mato. 
        //TODO: investigar ECS (entity component system). manejaba un sistema de id similar creo

        if (temporizadorSpawn <=0)
        {
            Enemy enemy(&enemyTexture, sf::Vector2u(6, 8), 0.3f, 10.0f, enemigos.size(), window);
            temporizadorSpawn = 5.0f;
            enemigos.push_back(enemy);
            enemigos.back().setPosition(sf::Vector2f(6.0f, 10.0f));

        }
        
        for (auto& enemy : enemigos)
        {

            enemy.Update(deltaTime, akasan.getBody().getPosition());

            for (auto& otherEnemy : enemigos)
            {
                if(enemy.getID() != otherEnemy.getID())
                {
                    if (enemy.getCollider().checkSolidCollision(otherEnemy.getCollider(), 0.25f)) {
                    
                    }
                }
                
            }
        }

        for (auto& enemy : enemigos)
        {
            enemy.Update(deltaTime, akasan.getBody().getPosition());

            if (enemy.getCollider().checkSolidCollision(akasan.getCollider(),0.25f)) {
                akasan.dmgReceived(10);
            }

        }

        interface.Update(akasan, currentView);





        window.clear(sf::Color::Color(i,i,i,255));

        ///draw entities

        window.draw(cube1);
        window.draw(cube2);
        window.draw(cube3);
        window.draw(circle1);

        for (auto& enemy : enemigos)
        {
            enemy.Draw();
        }
        akasan.Draw();

        //draw interface (HUD)

        interface.Draw(window);

        //Render(renderer, resources);


        window.display();

        //std::cout<<deltaClock.getElapsedTime().asMilliseconds()<<std::endl;


    }

    return 0;
}
