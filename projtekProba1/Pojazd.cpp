#include "Pojazd.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
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

void Pojazd::moveDown(float dt)
{
    float velocity = 100.0f; // Przyk�adowa warto�� pr�dko�ci poruszania si� w d�
    sf::Vector2f position = getPosition();
    float deltaY = velocity * dt;
    position.y += deltaY;
    setPosition(position);
}
void Pojazd::moveUp(float dt)
{
    
    float velocity = -100.0f; // Przyk�adowa warto�� pr�dko�ci poruszania si� w g�r�
    sf::Vector2f position = getPosition();
    float deltaY = velocity * dt;
    position.y += deltaY;
    setPosition(position);
    
}
void Pojazd::updateAnimation()
{
    float elapsedTime = animationClock.getElapsedTime().asSeconds();

    if (elapsedTime >= animationTimer)
    {
        currentFrame = (currentFrame + 1) % getNumFrames(); // Zmiana na nast�pn� klatk� (modulo liczba klatek)

        int frameWidth = getFrameWidth();
        int frameHeight = getFrameHeight();

        setTextureRect(sf::IntRect(currentFrame * frameWidth, 0, frameWidth, frameHeight));

        animationClock.restart();
    }
}


