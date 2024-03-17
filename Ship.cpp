#include "Ship.h"
#include  <iostream>

#include "Missile.h"

Ship::Ship(float x, float y, float InitialVitesse) 
{
    setPosition(x,y);
    vitesse = InitialVitesse;

    Score();
    
    if (!textureShip.loadFromFile("Texture/ships.png"))
    {
        std::cout << "err" << std::endl;
    }
    sprite.setTexture(textureShip);
    sprite.setTextureRect(sf::IntRect(32, 0, 32, 32));
}

Ship::~Ship()
{
    for (auto element : missileTest)
    {
        delete element;
    }
}



void Ship::Tick()
{
    /*for (auto element : missileTest)
    {
        if (element->getPosition().y <= 0)
        {
            delete element;
        }
    }*/
}

void Ship::OnPressKey(sf::Event event) //bool        juste la pression
{
    if (event.key.code == sf::Keyboard::Key::Right)
    {
        move(vitesse,0.f);
    }if (event.key.code == sf::Keyboard::Key::Left)
    {
        move(-vitesse,0.f);
    }if (event.key.code == sf::Keyboard::Key::Up)
    {
        move(0.f ,-vitesse);
    }if (event.key.code == sf::Keyboard::Key::Down)
    {
        move(0.f,vitesse);
    }if (event.key.code == sf::Keyboard::Key::Space)
    {
        Fire();
    }
}
void Ship::Fire()
{
    //std::cout << "missile" << std::endl;
    Missile* missile = new Missile(getPosition().x + 8.f,getPosition().y + 8.f,10.f);
    //missile->setPosition(100.f,100.f);
    missileTest.push_back(missile);
}

void Ship::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.texture = &textureShip;
    states.transform = getTransform();
    target.draw(sprite, states);
}
void Ship::Score()
{
    if (!font.loadFromFile("Texture/Cybergame.ttf"))
    {
        std::cout << "err" << std::endl;
    }
    score = 0;
    txtScore.setFont(font);
    txtScore.setString("Score : " + std::to_string(score));
    txtScore.setPosition(10.f,10.f);
    txtScore.setFillColor(sf::Color::Black);
    txtScore.setCharacterSize(26);
}
