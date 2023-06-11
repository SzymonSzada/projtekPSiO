#include "bonusBlue.h"
int bonusBlue::getNumFrames()
{
    return 6;
}

int bonusBlue::getFrameWidth()
{
    return 38;
}

int bonusBlue::getFrameHeight()
{
    return 37;
}



void bonusBlue::setAnimation()
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