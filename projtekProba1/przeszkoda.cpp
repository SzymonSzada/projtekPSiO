#include "przeszkoda.h"
#include "bonusCoin.h"


int przeszkoda::getNumFrames()
{
    return 8;
}

int przeszkoda::getFrameWidth()
{
    return 22;
}

int przeszkoda::getFrameHeight()
{
    return 15;
}

void przeszkoda::setAnimation()
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
sf::FloatRect przeszkoda::getBoundary() const
{
    return sf::FloatRect();
}
