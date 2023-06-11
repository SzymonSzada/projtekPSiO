#pragma once
#include "Pojazd.h"
#include <iostream>
class GreenCar : public Pojazd
{
public:
	GreenCar() : Pojazd("greenCar.png") { animationTimer = 0.6f; std::cout << "tworzenie greencar"<<std::endl; };
	void setAnimation() override; //powtorzyc to co bylo w graczcpp/graczh
	int getNumFrames() override;
	int getFrameWidth() override;
	int getFrameHeight() override;
	bool opuszczenieMapy();
	sf::FloatRect getBoundary() const override;
	void setVelocity();
};

