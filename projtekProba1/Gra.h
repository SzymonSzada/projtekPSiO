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
#include "bonusCoin.h"
#include <vector>
class RedCar;
class GreenCar;
class bonusCoin;

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
	//bonusCoin
	bonusCoin* bonuscoin;
	
	//metody prywatne
	
	void createPlayer();
	void stworzTlo();
	void createRedCar();
	void createGreenCar();
	void createBonusCoin();
	void createPrzeszkoda();
	void pollEvents();
	//void sprawdzKolizje();
	void initVariables();
	void initWindow();
public:
	 
	Gra();
	virtual ~Gra();
	//Accessors`
	const bool running() const;
	

	//metody
	void update();
	void render();
};

