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
	
	RedCar() : Pojazd("redCar.png") { animationTimer = 0.6f; std::cout << "tworzenie obiektu redCar" << std::endl; };
	~RedCar() { std::cout << "usuwanie obiektu redCar" << std::endl; }
	void setAnimation() override; //powtorzyc to co bylo w graczcpp/graczh
	int getNumFrames() override;
	int getFrameWidth() override;
	int getFrameHeight() override;
	bool czyWychodziPozaEkran(const sf::RenderWindow& window) const override;

    
};

