#pragma once
#include "Entity.h"

class Ennemis : public Entity
{
public:
    Ennemis(float x, float y, float vitesse);
    
    sf::Texture textureEnnemis;
    sf::RenderStates renderEnnemis;
    
    void Tick() override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
