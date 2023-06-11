#include "RedCar.h"
#include "Pojazd.h"
#include <SFML/Graphics/Rect.hpp>
#include <chrono>
#include <thread>
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

bool RedCar::opuszczenieMapy()
{
    if(getLewyDolny().y >= 650)
    {
        return true;
    }
    return false;
}



sf::FloatRect RedCar::getBoundary() const
{
    sf::FloatRect bounds;
    bounds.left = getPosition().x;
    std::cout << bounds.left << std::endl;
    bounds.top = getPosition().y;
    bounds.width = getGlobalBounds().width;
    bounds.height = getGlobalBounds().height;
    return bounds;
}

void RedCar::setAnimation()
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
