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
	//muzyczka .WAV
	sf::Music music;
	//tlo
	sf::Texture textureTlo;
	sf::Texture textureMenu;
	sf::Sprite spriteTlo;
	sf::Sprite menuTlo;
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
	float x1 = 134.0f; // lewy x
    float y1 = 0.0f;   // górny y
    float x2 = 504.0f; // prawy x
    float y2 = 537.0f; // dolny y
	//licznik
	int zycie;
	int wynik;
	int zwiekszaWynik;
	int licznikSerc;
	//zegary do zwiekszania poziomu trudnosci 
	sf::Clock obstacleClock; // Zegar do œledzenia czasu
	sf::Time obstacleTimer; // Licznik czasu
	sf::Time obstacleInterval = sf::seconds(5.0f); // Interwa; czasowy - tworzenie przeszkod co 5 sekund
	//zegar do serca
	sf::Clock obstacleClockSerce; // Zegar do œledzenia czasu
	sf::Time obstacleTimerSerce; // Licznik czasu
	sf::Time obstacleIntervalSerce = sf::seconds(5.0f); //co 15 sekund pojawia sie serce dodajace zycie
	//tworzenie obiektow
	void createPlayer();
	void stworzTlo();
	void createRedCar();
	void createGreenCar();
	void createBonusCoin();
	void createPrzeszkoda();
	void createSerce();
	void pollEvents();

	void initVariables();
	void initWindow();
	void renderStartScreen();
public:
	void run();

	void initMusic();

	void playMusic();

	void stopMusic();
	 
	Gra();
	virtual ~Gra();
	//Accessors`
	const bool running() const;
	

	//metody
	void update();
	void render();
};

