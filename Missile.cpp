#include "Missile.h"
#include <iostream>

Missile::Missile(float x, float y, float initialVitesse)
{
    setPosition(x,y);
    vitesse = initialVitesse;
    if (!textureMissile.loadFromFile("Texture/tiles.png"))
    {
        std::cout << "err" << std::endl;
    }
    sprite.setTexture(textureMissile);
    sprite.setTextureRect(sf::IntRect(16, 16, 16, 16));
    
    
}



void Missile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.texture = &textureMissile;
    states.transform = getTransform();
    target.draw(sprite, states);
}



void Missile::Tick()
{
    move(0.f,-vitesse);
    
}
