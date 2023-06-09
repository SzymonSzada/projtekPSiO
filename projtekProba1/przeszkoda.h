#pragma once
#include "Pojazd.h"
#include <iostream>
class przeszkoda : public Pojazd
{
public:
	przeszkoda() : Pojazd("bonusBlue.png") { animationTimer = 0.15f; std::cout << "tworzenie obiektu przeszkoda" << std::endl; };
	~przeszkoda() { std::cout << "usuwanie obiektu przeszkoda" << std::endl; }
	void setAnimation() override; //powtorzyc to co bylo w graczcpp/graczh
	int getNumFrames() override;
	int getFrameWidth() override;
	int getFrameHeight() override;
	sf::FloatRect getBoundary() const override;
};

