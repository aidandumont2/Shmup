#pragma once
#include <SFML/Window/Event.hpp>
#include "Entity.h"
#include "Missile.h"

class Ship : public Entity
{
public:
    Ship(float x, float y, float vitesse);
    ~Ship();
    sf::Texture textureShip;
    //std::vector<Missile*> launchMissiles;
    std::vector<Missile*> missileTest;
    sf::RenderStates renderShip;
    
    void Deplacement() override;
    void Fire();
    void Tick() override;
    void OnPressKey(sf::Event event);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
