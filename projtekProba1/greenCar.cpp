
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

void GreenCar::setAnimation()
{
    int frameWidth = getFrameWidth();   // Pobranie szeroko�ci klatki
    int numFrames = getNumFrames();     // Pobranie liczby klatek

    // Obliczanie czasu od ostatniej zmiany klatki
    float elapsedTime = animationClock.getElapsedTime().asSeconds();

    // Obliczanie indeksu aktualnej klatki na podstawie czasu
    int currentFrameIndex = static_cast<int>(elapsedTime / animationTimer) % numFrames;

    // Ustawianie odpowiedniej tekstury reprezentuj�cej aktualn� klatk�
    setTextureRect(sf::IntRect(frameWidth * currentFrameIndex, 0, frameWidth, getFrameHeight()));
}