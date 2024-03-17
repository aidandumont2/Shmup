#pragma once
    
#include "Entity.h"
#include <SFML/Audio.hpp>

class Missile :public Entity
{
public:
    //sf::Sound soundFire;
    
    sf::Texture textureMissile;
    sf::RenderStates renderMissile;

    
    Missile(float x, float y, float vitesse);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void Deplacement() override;
    void Tick() override;
};
