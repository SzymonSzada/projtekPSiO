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
    // Sprawd� kolizj� na podstawie granic obiekt�w
    if (boundary.left < other.boundary.left + other.boundary.width ||
        boundary.left + boundary.width > other.boundary.left ||
        boundary.top < other.boundary.top + other.boundary.height ||
        boundary.top + boundary.height > other.boundary.top) {
        // Kolizja wyst�puje
        return true;
    }
    // Brak kolizji
    return false;
}


//poruszanie obiektow w d�
void Pojazd::moveDown(float dt)
{
    float velocity = 100.0f; // Przyk�adowa warto�� pr�dko�ci poruszania si� w d�
    sf::Vector2f position = getPosition();
    float deltaY = velocity * dt;
    position.y += deltaY;
    setPosition(position);
}
//poruszanie obiektow w g�re
void Pojazd::moveUp(float dt)
{
    
    float velocity = -100.0f; // Przyk�adowa warto�� pr�dko�ci poruszania si� w g�r�
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
        currentFrame = (currentFrame + 1) % getNumFrames(); // Zmiana na nast�pn� klatk� (modulo liczba klatek)

        int frameWidth = getFrameWidth();
        int frameHeight = getFrameHeight();

        setTextureRect(sf::IntRect(currentFrame * frameWidth, 0, frameWidth, frameHeight));

        animationClock.restart();
    }
}
bool Pojazd::czyWychodziPozaEkran(const sf::RenderWindow& window) const
{
   // Sprawdzenie, czy obiekt wychodzi poza obrys ekranu
    if (boundary.left > window.getSize().x ||
        boundary.top > window.getSize().y ||
        boundary.left + boundary.width < 0 ||
        boundary.top + boundary.height < 0)
    {
        return true; // Obiekt wychodzi poza ekran
    }

    return false; // Obiekt znajduje si� w granicach ekranu
}



