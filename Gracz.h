#pragma once
#include "Pojazd.h"
class Gracz : public Pojazd
{
protected:
public:
	
	float dt;
	void move(float dt);
	
	Gracz() : Pojazd("graczAnimacja.png") { animationTimer = 0.6f; };
	void setAnimation() override;
	sf::FloatRect getBoundary() const;
	int getNumFrames() override;
	int getFrameWidth() override;
	int getFrameHeight() override;
	
    
};

