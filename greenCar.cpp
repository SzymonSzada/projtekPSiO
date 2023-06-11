
#include "GreenCar.h"


int GreenCar::getNumFrames()
{
    return 4;
}

int GreenCar::getFrameWidth()
{
    return 29;
}

int GreenCar::getFrameHeight()
{
    return 48;
}

bool GreenCar::opuszczenieMapy()
{
    if (getPrawyGorny().y <= -48)
    {
        return true;
    }
    return false;
}
sf::FloatRect GreenCar::getBoundary() const
{
    sf::FloatRect bounds;
    bounds.left = getPosition().x;
    bounds.top = getPosition().y;
    bounds.width = getGlobalBounds().width;
    bounds.height = getGlobalBounds().height;
    return bounds;
}

void GreenCar::setAnimation()
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
