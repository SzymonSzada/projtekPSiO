#pragma once
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
class Pojazd : public sf::Sprite
{
protected:
	sf::Texture texture;
	sf::Clock animationClock; // zegar do "zmiany animacji"
	float animationTimer;	  // czas trwania jednej klatki
	int currentFrame;
	//int licznik = 0;
	float ms;
	int animationCounter = 0;
public:
	Pojazd();
	Pojazd(const std::string file);
	 ~Pojazd() {};
	 virtual void setAnimation() = 0;
	 void updateAnimation();
	 virtual int getNumFrames() = 0;
	 virtual int getFrameWidth() = 0;
	 virtual int getFrameHeight() = 0;
	

};

