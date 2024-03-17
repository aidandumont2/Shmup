#pragma once

#include <SFML/Graphics.hpp>

class Entity : public sf::Transformable, public sf::Drawable
{
public:
    float vitesse;
    sf::Sprite sprite;
    
    Entity();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
    virtual void Tick() = 0;
};
