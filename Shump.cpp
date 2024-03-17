#include <SFML/Graphics.hpp>
#include <iostream>

#include "Map.h"


int main()
{

    sf::RenderWindow window(sf::VideoMode(640, 640), "Shmup");
    sf::Clock clock;
    sf::Font font;
    Map map;
    sf::View view(sf::Vector2f(320, 320), sf::Vector2f(1000, 1000));
    
    while (window.isOpen())
    {
        //sf::Time elapsed = clock.restart();
        sf::Time elapsed1 = clock.getElapsedTime();
        //std::cout << elapsed1.asSeconds() << std::endl;

        //map.Tick();
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            map.ship.OnPressKey(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear(sf::Color::Black);
        

        map.ship.Tick();
        
        window.draw(map);
        map.Scroll();
        
        window.draw(map.ship,map.ship.renderShip);
        window.draw(map.ship.txtScore);
        window.draw(map.ennemis,map.ennemis.renderEnnemis);

        map.ship.CheckColisionWindow();
        //map.ship->Tick();
        for (auto element : map.ship.missileTest)
        {
            
            window.draw(*element);
            element->Tick();
            // if (element->getPosition().y <= 0)
            // {
            //     map.ship.missileTest.pop_back();    // destruction missile
            //     std::cout << "missile détruit" << std::endl;
            // }
        }

        
        window.display();
    }

    return 0;
}
