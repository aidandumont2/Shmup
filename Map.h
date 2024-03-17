#pragma once
#include "Ennemis.h"
#include "Ship.h"

class Map : public sf::Drawable, public sf::Transformable
{
public:
    sf::View view;
    Ship ship;
    Ennemis ennemis;
    sf::Texture textureMap;
    
    sf::Sprite spriteHerbe;
    sf::Sprite spriteRoche;
    sf::Sprite spriteMap;
    
    std::vector<std::vector<sf::Sprite*>> tilemap;
    
    
    sf::RenderStates renderMap;
    Map();

    void generation_map();
    void Scroll();
    void Tick();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::IntRect RandomTexture(int);
};
