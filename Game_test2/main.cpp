#include <iostream>
#include <SFML/Graphics.hpp>


int main()
{
    ///precalculos



    ///ventana de juego

    sf::RenderWindow window(sf::VideoMode(1080, 720), "SFML TAB", sf::Style::Close | sf::Style::Titlebar);


    ///inicializar sistemas
    sf::Event evento;

    sf::Clock reloj;

    window.setFramerateLimit(75);

    ///inicializar entidades

    sf::RectangleShape rectangle(sf::Vector2f(128.0f, 128.0f));
    rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);
    rectangle.setFillColor(sf::Color::White);
    rectangle.setPosition(window.getSize().x/2, window.getSize().y/2);

    ///fondo


    ///BUCLE DE JUEGO

    int i = 0;
    
    while(window.isOpen())
    {
        i++;


        while(window.pollEvent(evento))
        {
            if(evento.type == evento.Closed)
                {
                window.close();
                }


        }


        window.clear(sf::Color::Color(i,i,i,255));

        window.draw(rectangle); // Render our shape.


        window.display();

        std::cout<<reloj.getElapsedTime().asMilliseconds()<<std::endl;


    }

    return 0;
}
