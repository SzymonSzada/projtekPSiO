#include "Serce.h"

sf::FloatRect Serce::getBoundary() const
{
    return boundary;
}

void Serce::setAnimation()
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

int Serce::getNumFrames()
{
    return 1;
}

int Serce::getFrameWidth()
{
    return 1230;
}

int Serce::getFrameHeight()
{
    return 1642;
}
