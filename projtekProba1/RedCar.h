#pragma once
#include "Pojazd.h"
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class RedCar : public Pojazd
{
private:
public:
	
	RedCar() : Pojazd("redCar.png") { animationTimer = 0.6f; std::cout << "tworzenie obiektu redCar" << std::endl; 
	boundary.left = 0.0f;
	boundary.top = 0.0f;
	boundary.width = 100.0f;
	boundary.height = 100.0f;
	};
	~RedCar() { std::cout << "usuwanie obiektu redCar" << std::endl; }
	void setAnimation() override; //powtorzyc to co bylo w graczcpp/graczh
	int getNumFrames() override;
	int getFrameWidth() override;
	sf::FloatRect getBoundary() const;
	int getFrameHeight() override;
	bool opuszczenieMapy();

	sf::FloatRect getCollisionBox() const;

    
};

