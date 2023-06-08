#include "Pojazd.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
Pojazd::Pojazd()
{
    animationTimer = 0.0f;
    currentFrame = 0;
}
Pojazd::Pojazd(const std::string file)
{
	texture.loadFromFile(file);
	setTexture(texture); //jak bede chcial uzyc to dodac dziedziczenie ze sprite w pojazd.h
}
//ustawianie granic
void Pojazd::setBounds(float left, float top, float width, float height)
{
    boundary.left = left;
    boundary.top = top;
    boundary.width = width;
    boundary.height = height;
}

bool Pojazd::checkCollision(const Pojazd& other) const
{
    // SprawdŸ kolizjê na podstawie granic obiektów
    if (boundary.left < other.boundary.left + other.boundary.width ||
        boundary.left + boundary.width > other.boundary.left ||
        boundary.top < other.boundary.top + other.boundary.height ||
        boundary.top + boundary.height > other.boundary.top) {
        // Kolizja wystêpuje
        return true;
    }
    // Brak kolizji
    return false;
}


//poruszanie obiektow w dó³
void Pojazd::moveDown(float dt)
{
    float velocity = 100.0f; // Przyk³adowa wartoœæ prêdkoœci poruszania siê w dó³
    sf::Vector2f position = getPosition();
    float deltaY = velocity * dt;
    position.y += deltaY;
    setPosition(position);
}
//poruszanie obiektow w góre
void Pojazd::moveUp(float dt)
{
    
    float velocity = -100.0f; // Przyk³adowa wartoœæ prêdkoœci poruszania siê w górê
    sf::Vector2f position = getPosition();
    float deltaY = velocity * dt;
    position.y += deltaY;
    setPosition(position);
    
}
//zmiana animacji co okreslony czas
void Pojazd::updateAnimation()
{
    float elapsedTime = animationClock.getElapsedTime().asSeconds();

    if (elapsedTime >= animationTimer)
    {
        currentFrame = (currentFrame + 1) % getNumFrames(); // Zmiana na nastêpn¹ klatkê (modulo liczba klatek)

        int frameWidth = getFrameWidth();
        int frameHeight = getFrameHeight();

        setTextureRect(sf::IntRect(currentFrame * frameWidth, 0, frameWidth, frameHeight));

        animationClock.restart();
    }
}



sf::Vector2f Pojazd::getLewyDolny()
{
    return getPosition() + sf::Vector2f(0,48);
}

bool Pojazd::stykaSieZ(Pojazd* pojazd)
{   
    //std::cout << pojazd->getPrawyGorny().x << " - " << getLewyDolny().x << std::endl;;
    
    if (!(getLewyDolny().x > pojazd->getPrawyGorny().x || getLewyDolny().y < pojazd->getPrawyGorny().y || getPrawyGorny().x < pojazd->getLewyDolny().x || getPrawyGorny().y > pojazd->getLewyDolny().y))
    {
        return true;

    }
    return false;
}

sf::Vector2f Pojazd::getPrawyGorny()
{
    return getPosition() + sf::Vector2f(28,0);
}





