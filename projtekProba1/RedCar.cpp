#include "RedCar.h"
#include "Pojazd.h"
#include <SFML/Graphics/Rect.hpp>

void RedCar::setAnimation()
{
    int frameWidth = getFrameWidth();   // Pobranie szerokoœci klatki
    int numFrames = getNumFrames();     // Pobranie liczby klatek

    // Obliczanie indeksu aktualnej klatki na podstawie czasu
    int currentFrameIndex = static_cast<int>(animationClock.getElapsedTime().asSeconds() / animationTimer) % numFrames;

    // Ustawianie odpowiedniej tekstury reprezentuj¹cej aktualn¹ klatkê
    setTextureRect(sf::IntRect(frameWidth * currentFrameIndex, 0, frameWidth, getFrameHeight()));
}

int RedCar::getNumFrames()
{
	return 4;
}

int RedCar::getFrameWidth()
{
	return 28;
}

int RedCar::getFrameHeight()
{
	return 48;
}
