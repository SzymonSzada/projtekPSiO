#include "Gracz.h"
#include "Pojazd.h"



int Gracz::getNumFrames()
{
	return 4;
}

int Gracz::getFrameWidth()
{
	return 29;
}

int Gracz::getFrameHeight()
{
	return 62;
}


void Gracz::move(float dt)
{
    float speed = 100.0f; // Prêdkoœæ poruszania gracza (mo¿esz dostosowaæ wartoœæ)

    sf::Vector2f movement(0.0f, 0.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        movement.x -= speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        movement.y -= speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        movement.y += speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        movement.x += speed;
    }
    
    // SprawdŸ, czy nowa pozycja gracza wychodzi poza granice
    sf::Vector2f newPosition = getPosition() + movement * dt;

    if (newPosition.x < boundary.left)
    {
        newPosition.x = boundary.left;
    }
    else if (newPosition.x + getFrameWidth() > boundary.left + boundary.width)
    {
        newPosition.x = boundary.left + boundary.width - getFrameWidth();
    }

    if (newPosition.y < boundary.top)
    {
        newPosition.y = boundary.top;
    }
    else if (newPosition.y + getFrameHeight() > boundary.top + boundary.height)
    {
        newPosition.y = boundary.top + boundary.height - getFrameHeight();
    }

    setPosition(newPosition);
}
    




void Gracz::setAnimation()
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
sf::FloatRect Gracz::getBoundary() const
{
    sf::FloatRect bounds;
    bounds.left = getPosition().x;
    bounds.top = getPosition().y;
    bounds.width = getGlobalBounds().width;
    bounds.height = getGlobalBounds().height;
    return bounds;
}


