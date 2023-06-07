#include "RedCar.h"
#include "Pojazd.h"
#include <SFML/Graphics/Rect.hpp>

int RedCar::getNumFrames()
{
	return 4;
}

int RedCar::getFrameWidth()
{
	return 29;
}

int RedCar::getFrameHeight()
{
	return 48;
}



void RedCar::setAnimation()
{
    int frameWidth = getFrameWidth();   // Pobranie szerokoœci klatki
    int numFrames = getNumFrames();     // Pobranie liczby klatek

    // Obliczanie czasu od ostatniej zmiany klatki
    float elapsedTime = animationClock.getElapsedTime().asSeconds();

    // Obliczanie indeksu aktualnej klatki na podstawie czasu
    int currentFrameIndex = static_cast<int>(elapsedTime / animationTimer) % numFrames;

    // Ustawianie odpowiedniej tekstury reprezentuj¹cej aktualn¹ klatkê
    setTextureRect(sf::IntRect(frameWidth * currentFrameIndex, 0, frameWidth, getFrameHeight()));
}
bool RedCar::czyWychodziPozaEkran(const sf::RenderWindow& window) const
{
    // Sprawdzenie, czy obiekt wychodzi poza obrys ekranu (tylko dolna granica)
    if (boundary.top + boundary.height < 0)
    {
        return true; // Obiekt wychodzi poza doln¹ granicê ekranu
    }
   
    return false; // Obiekt znajduje siê w granicach ekranu
}