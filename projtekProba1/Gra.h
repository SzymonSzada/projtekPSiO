#pragma once

//klasa silnik/ klasa nadzorcza 

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "RedCar.h"
#include "Gracz.h"
#include "GreenCar.h"
#include <vector>

class Gra
{
private:
	//zmienne
	//tlo
	sf::Texture textureTlo;
	sf::Sprite spriteTlo;
	//zegary 
	sf::Clock clock; //zegar do poruszania obiektem klasy gracz
	//window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	//kontener obiektow
	std::vector<Pojazd*> pojazdy; // Kontener przechowuj¹cy obiekty Pojazd
	//czerwone auta
	RedCar* redcar;
	//zieleone auta
	GreenCar* greencar;
	//gracz
	Gracz* gracz;
	
	//metody prywatne
	void cratePlayer();
	void stworzTlo();
	void crateRedCar();
	void crateGreenCar();
	void pollEvents();
	void initVariables();
	void initWindow();
public:
	Gra();
	virtual ~Gra();
	//Accessors
	const bool running() const;

	//metody
	void update();
	void render();
};

