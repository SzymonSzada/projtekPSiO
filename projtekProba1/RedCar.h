#pragma once
#include "Pojazd.h"
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class RedCar : public Pojazd
{
private:
public:
	
	RedCar() : Pojazd("redCar.png") { animationTimer = 0.6f; };
	void setAnimation() override; //powtorzyc to co bylo w graczcpp/graczh
	int getNumFrames() override;
	int getFrameWidth() override;
	int getFrameHeight() override;
    
};

