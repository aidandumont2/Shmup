#include "Map.h"

#include <iostream>

Map::Map() : ship(310.f, 500.f, 10.f), ennemis(100.f,100.f,2.f)
{
    if (!textureMap.loadFromFile("Texture/tiles_packed.png"))
    {
        std::cout << "err" << std::endl;
    }
    int height = 0;
    for (int l = 0; l < 44; ++l)
    {
        std::vector<sf::Sprite*> ligne;

        int width = -1;
        for (int i = 0; i < 21; ++i)
        {
            sf::Sprite* spriteCase = new sf::Sprite();
            spriteCase->setTexture(textureMap);
            spriteCase->setTextureRect(RandomTexture(rand() % 2));
            spriteCase->setPosition(16 * width, 16*l);
            ligne.push_back(spriteCase);
            width += 1;
        }
        tilemap.push_back(ligne);
    }
}

sf::IntRect Map::RandomTexture(int index)
{
    if (index == 0)
    {
        return sf::IntRect(32, 160, 16, 16);
    }
    else if (index == 1)
    {
        return sf::IntRect(128, 64, 16, 16);
    }
}


void Map::Scroll()
{
    for (auto ligne : tilemap)
    {
        for (auto tile : ligne)
        {
            tile->move(0.f, 1.f);
            if (tile->getPosition().y >= 336)
            {
                
                tile->setPosition(tile->getPosition().x, -15.f);
            }
        }
    }
}


void Map::Tick()
{
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.texture = &textureMap;
    states.transform = getTransform();
    states.transform.scale(2.f, 2.f);
    for (auto element : tilemap)
    {
        for (auto tile : element)
        {
            target.draw(*tile, states);
            
        }
        
    }
}
