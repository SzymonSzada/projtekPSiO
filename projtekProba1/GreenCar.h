#pragma once
#include "Pojazd.h"
class GreenCar : public Pojazd
{
public:
	GreenCar() : Pojazd("greenCar.png") { animationTimer = 0.6f; };
	void setAnimation() override; //powtorzyc to co bylo w graczcpp/graczh
	int getNumFrames() override;
	int getFrameWidth() override;
	int getFrameHeight() override;
};

