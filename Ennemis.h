#pragma once
#include "Entity.h"

class Ennemis : public Entity
{
public:
    Ennemis(float x, float y, float vitesse);
    ~Ennemis();
    sf::Texture textureEnnemis;
    
};
