#include "Ennemis.h"

#include  <iostream>

Ennemis::Ennemis(float x, float y, float initialvitesse)
{
    setPosition(x,y);
    vitesse = initialvitesse;
        
    if (!textureEnnemis.loadFromFile("Texture/ships.png"))
    {
        std::cout << "err" << std::endl;
    }
    sprite.setTexture(textureEnnemis);
    sprite.rotate(90.f),
    sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
}


void Ennemis::Tick()
{

}

void Ennemis::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.texture = &textureEnnemis;
    states.transform = getTransform();
    target.draw(sprite, states);
}
