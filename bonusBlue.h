#pragma once
#include "Pojazd.h"
#include <iostream>
class bonusBlue :  public Pojazd
{
public:
	bonusBlue() : Pojazd("bonusBlue.png") { animationTimer = 0.6f; std::cout << "tworzenie obiektu bonusCoin" << std::endl; };
	~bonusBlue() { std::cout << "usuwanie obiektu bonusCoin" << std::endl; }
	void setAnimation() override; //powtorzyc to co bylo w graczcpp/graczh
	int getNumFrames() override;
	int getFrameWidth() override;
	int getFrameHeight() override;
};

