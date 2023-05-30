#pragma once

//klasa silnik/ klasa nadzorcza 

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "RedCar.h"
#include "Gracz.h"
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
	//czerwone auta
	RedCar* redcar;
	std::vector<RedCar*> redcars;
	//gracz
	Gracz* gracz;
	
	//metody prywatne
	void cratePlayer();
	void stworzTlo();
	void crateRedCar();
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

