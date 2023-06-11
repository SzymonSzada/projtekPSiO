#pragma once
#include "Pojazd.h"
#include <iostream>
class Serce :  public Pojazd
{
public:
	Serce() : Pojazd("Serce.png") { animationTimer = 0.6f;  std::cout << "tworzenie obiektu Serce" << std::endl; };
	~Serce() { std::cout << "usuwanie obiektu Serce" << std::endl; }
	sf::FloatRect getBoundary() const override;
	void setAnimation() override; //powtorzyc to co bylo w graczcpp/graczh
	int getNumFrames() override;
	int getFrameWidth() override;
	int getFrameHeight() override;
};

