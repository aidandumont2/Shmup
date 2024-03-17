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
    
    int score;
    int lifePoint;
    sf::Text txtScore;
    sf::Text txtLife;
    
    sf::Font font;
    
    std::vector<Missile*> missileTest;
    sf::RenderStates renderShip;

    sf::FloatRect float_rectShip;
    
    void Fire();
    void Tick() override;
    void OnPressKey(sf::Event event);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void SetUI();

    void CheckColisionWindow();
};
