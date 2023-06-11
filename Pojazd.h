#pragma once
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
class Pojazd : public sf::Sprite
{
	
protected:
	sf::Texture texture;
	sf::Clock animationClock; // zegar do "zmiany animacji"
	float animationTimer;	  // czas trwania jednej klatki
	sf::FloatRect boundary;	  // zmienna do ustawiania granic
	int currentFrame;
	float ms;
	int animationCounter = 0;
	float velocity; 
	
	float timeCounter;
	
public:
	void setBounds(float left, float top, float width, float height);//ustawianie granic
	bool checkCollision(const Pojazd& other) const; //kolizje z innymi pojazdami 
	void moveDown(float dt); // Metoda do poruszania siê w dó³
	void moveUp(float dt);	// Metoda do poruszania siê w góre
	Pojazd();
	Pojazd(const std::string file);
	 ~Pojazd() {};
	 virtual void setAnimation() = 0;
	 void updateAnimation();
	 virtual int getNumFrames() = 0;
	 virtual int getFrameWidth() = 0;
	 virtual int getFrameHeight() = 0;
	 bool stykaSieZ(Pojazd* pojazd);
	 sf::Vector2f getLewyDolny();
	 sf::Vector2f getPrawyGorny();
	 bool zderzenie();
	 virtual sf::FloatRect getBoundary() const = 0;
	 

};

