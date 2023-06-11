#pragma once
#include "Pojazd.h"
#include <iostream>
class bonusCoin :  public Pojazd
{public:
	bonusCoin() : Pojazd("bonusCoin.png") { animationTimer = 0.15f; std::cout << "tworzenie obiektu bonusCoin" << std::endl; };
	~bonusCoin() { std::cout << "usuwanie obiektu bonusCoin" << std::endl; }
	void setAnimation() override; //powtorzyc to co bylo w graczcpp/graczh
	int getNumFrames() override;
	int getFrameWidth() override;
	int getFrameHeight() override;
	sf::FloatRect getBoundary() const override;
};

