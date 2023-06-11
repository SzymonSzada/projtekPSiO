#include "Gra.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include "RedCar.h"
#include "GreenCar.h"
#include "bonusCoin.h"
#include "przeszkoda.h"
#include "Serce.h"

//metody prywatne
void Gra::initVariables()
{
	this->window = nullptr;
}

void Gra::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "My window",sf::Style::Titlebar | sf::Style::Close);
}
void Gra::renderStartScreen()
{	//renderowanie menu i wszystkich wystepujacych tam teksow
	this->window->clear(sf::Color::Black);

	// T³o start screen
	
	if (!textureMenu.loadFromFile("MENUPOLONEZ.jpg"))
	{
		std::cout << "Error: Failed to load texture" << std::endl;
	}

	
	menuTlo.setTexture(textureMenu);
	menuTlo.scale(3.3f, 3.3f);

	// Tworzenie obiektu sf::Text
	sf::Font font;
	if (!font.loadFromFile("Ourland.ttf"))
	{
		std::cout << "Error: Failed to load font" << std::endl;
	}

	sf::Text startText;
	startText.setFont(font);
	startText.setCharacterSize(28);
	startText.setFillColor(sf::Color::Red);
	startText.setPosition(200.f, 250.f);
	startText.setString("Nacisnij SPACJE, aby zagrac");

	sf::Text exitText;
	exitText.setFont(font);
	exitText.setCharacterSize(24);
	exitText.setFillColor(sf::Color::Red);
	exitText.setPosition(220.f, 300.f);
	exitText.setString("Nacisnij Q, aby wyjsc");

	sf::Text muteText;
	muteText.setFont(font);
	muteText.setCharacterSize(24);
	muteText.setFillColor(sf::Color::Red);
	muteText.setPosition(240.f, 350.f);
	muteText.setString("Nacisnij M, aby wylaczyc muzyke");

	// Rysowanie obiektu sf::Text
	window->draw(menuTlo);
	window->draw(startText);
	window->draw(exitText);
	window->draw(muteText);
	this->window->display();
}
void Gra::run()
{	//obluga m. in. menu 
	renderStartScreen();

	// Czekaj na naciœniêcie SPACJI, aby rozpocz¹æ
	while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		pollEvents();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			window->close();
			return;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
			music.pause();
		}
	}

	while (running())
	{
		update();
		render();
	}
}
void Gra::initMusic()
{
	if (!this->music.openFromFile("OHV.wav"))
	{
		std::cout << "Error: Failed to load music" << std::endl;
	}
}

void Gra::playMusic()
{
	this->initMusic();
	this->music.play();
}

void Gra::stopMusic()
{
	this->music.stop();
}

//pauzowanie gry
bool isPaused = false;


//konstruktor destruktor
Gra::Gra()
{
	this->initVariables();
	this->initWindow();
	this->stworzTlo();
	//muzyczka
	this->playMusic();
	//tworznie obiektow na planszy
	this->createPlayer();
	this->createRedCar();
	this->createRedCar();
	this->createGreenCar();
	this->createGreenCar();
	this->createBonusCoin();
	this->createBonusCoin();
	this->createPrzeszkoda();
	this->createSerce();
	
	//zainicjowanie generatora liczb losowych
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	//dodanie licznika
	zycie = 3;
	wynik = 0;
	zwiekszaWynik = 1; //stala wartosc do zwiekszania wyniku
}

Gra::~Gra()
{
	delete this->window;
	//zwalnianie pamieci
	for (auto pojazd : pojazdy)
	{
		//delete pojazd;
	}
}
//Accessors

const bool Gra::running() const
{
	return this->window->isOpen();
}



//metody publiczne


void Gra::createPlayer()
{
	std::cout << "Tworzenie nowego obiektu RedCar" << std::endl;
	this->gracz = new Gracz();
	this->pojazdy.push_back(this->gracz); // Dodaj obiekt Gracz do kontenera
	//ustawiam granice?
	this->gracz->setBounds(134.0f, 0.0f, 504.0f, 537.0f);
	//ustawiam pozycje
	this->gracz->setPosition(368.0f, 450.0f);
	this->pojazdy.push_back(gracz);
}

void Gra::stworzTlo()
{
	//Zaladuj teksture
	if (this->textureTlo.loadFromFile("tlo.png") == false)
	{
		std::cout << "Error Player: Textures couldnt load file" << std::endl;
	}

	//Zaladuj teksture do typu sprite
	this->spriteTlo.setTexture(this->textureTlo);
	//Rozmiar Tla
	this->spriteTlo.scale(0.95f, 0.95f);
}

void Gra::createRedCar()
{
	// Zainicjalizuj generator liczb losowych
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	//zmienne opisujace pole generowania obiekow
	float x1 = 163.4f; // lewy x 
	float y1 = -700.0f; // górny y //-700 by³o 
	float x2 = 340.85f; // prawy x
	float y2 = 30.0f; // dolny y //30 by³o
		bool f = true;
		RedCar* redcar = new RedCar();
		redcar->setBounds(0.0f, 650.0f, 840.0f, 0.0f);
		float x, y;
		while (f) {
		// Losuj pozycjê dla RedCar w obszarze (x1, y1) - (x2, y2)
		x = x1 + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (x2 - x1)));
		y = y1 + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (y2 - y1)));
		redcar->setPosition(x, y);
		//granice do kolizji z obiektem redCar
			int i = 0;
			for ( ; i < pojazdy.size(); i++) {
			
			if (!redcar->stykaSieZ(pojazdy[i]))
			{
				continue;
			}
			else
			{
				break;
			}
		}
			if (i == pojazdy.size())
			{
				f = false;
			}
		}
		
		this->pojazdy.push_back(redcar); // Dodaj obiekt RedCar do kontenera
	
}

void Gra::createGreenCar()
{
	// Zainicjalizuj generator liczb losowych
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	//zmienne opisujace pole generowania obiekow
	float x1 = 424.0f; // lewy x
	float y1 = 580.0f; // górny y
	float x2 = 620.85f; // prawy x
	float y2 = 866.0f; // dolny y
	
	bool f = true;
	GreenCar* greencar = new GreenCar();
	greencar->setBounds(0.0f, 650.0f, 840.0f, 0.0f);
	float x, y;
	while (f) {
		// Losuj pozycjê dla RedCar w obszarze (x1, y1) - (x2, y2)
		x = x1 + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (x2 - x1)));
		y = y1 + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (y2 - y1)));
		greencar->setPosition(x, y);
		//granice do kolizji z obiektem redCar
		//std::cout << x << std::endl;
		int i = 0;
		for (; i < pojazdy.size(); i++) {

			if (!greencar->stykaSieZ(pojazdy[i]))
			{
				continue;
			}
			else
			{
				break;
			}
		}
		if (i == pojazdy.size())
		{
			f = false;
		}
	}

	this->pojazdy.push_back(greencar); // Dodaj obiekt RedCar do kontenera
}
//losowanie pozycji coin i przeszkoda

void Gra::createBonusCoin()
{
	// Losuj pozycjê dla GreenCar w obszarze (x1, y1) - (x2, y2)
	float x = x1 + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (x2 - x1)));
	float y = y1 + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (y2 - y1)));

	bonusCoin* bonuscoin = new bonusCoin();
	bonuscoin->setPosition(x, y);
	if (bonuscoin != nullptr) 
	{
		this->pojazdy.push_back(bonuscoin); // Dodaj obiekt GreenCar do kontenera
	}
}

void Gra::createPrzeszkoda()
{
	// Losuj pozycje dla GreenCar w obszarze (x1, y1) - (x2, y2)
	float x = x1 + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (x2 - x1)));
	float y = y1 + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (y2 - y1)));

	przeszkoda* przeszkoda1 = new przeszkoda();
	przeszkoda1->setPosition(x, y);
	if (przeszkoda1 != nullptr) 
	{
		this->pojazdy.push_back(przeszkoda1); // Dodaj obiekt GreenCar do kontenera
	}
}

void Gra::createSerce()
{
	float x1 = 134.0f; // lewy x
	float y1 = 0.0f;   // górny y
	float x2 = 504.0f; // prawy x
	float y2 = 537.0f; // dolny y
	// Losuj pozycje dla GreenCar w obszarze (x1, y1) - (x2, y2)
	float x = x1 + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (x2 - x1)));
	float y = y1 + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (y2 - y1)));

	Serce* serce = new Serce();
	serce->setPosition(x, y);
	
	if (serce != nullptr)
	{
		this->pojazdy.push_back(serce); // Dodaj obiekt GreenCar do kontenera
	}
	
}




void Gra::pollEvents()
{
	//event polling
	while(this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;

		}
	}
}

void Gra::update()
{
	if (isPaused) {
		return; // Jesli gra jest spauzowana, opuœæ metode update()
	}
	float dt = clock.restart().asSeconds(); // Pobierz czas od ostatniej aktualizacji
	this->pollEvents();
	//aktualizacja animacji obiektow z kontenera
	for (int j = 0; j < pojazdy.size();j++)
	{
		auto pojazd = pojazdy[j];
		pojazd->setAnimation();
		pojazd->setScale(2.0f, 2.0f); //zmiana rozmiaru textury
		//aktualizowanie licznika
		
		//poruszanie obiektow redCar w dol
		// Aktualizuj granice kolizji
		if (RedCar* redcar = dynamic_cast<RedCar*>(pojazd))
		{
			
			redcar->moveDown(dt);
			if (redcar->opuszczenieMapy())
			{
				
					if (pojazd == redcar) 
					{
					pojazdy.erase(pojazdy.begin()+j);
					delete redcar;
					this->createRedCar();
					break;
					}
			}
			//obluga kolizji  gracz - redcar
			if (redcar->getGlobalBounds().intersects(gracz->getGlobalBounds()))
			{
				std::cout << "kolizja z redcar" << std::endl;
				pojazdy.erase(pojazdy.begin() + j);
				delete redcar;
				this->createRedCar();
				zycie--;
				this->gracz->setPosition(368.0f, 450.0f);
				break;
			}
		}
		//poruszanie obiekow greenCar w gore
		if (GreenCar* greencar = dynamic_cast<GreenCar*>(pojazd))
		{
			greencar->moveUp(dt);
			if (greencar->opuszczenieMapy())
			{
				
					if (pojazd == greencar)
					{
						pojazdy.erase(pojazdy.begin() + j);
						delete greencar;
						this->createGreenCar();
						break;
					}
				
			}
			// obluga kolizji gracz - greencar
			if (greencar->getGlobalBounds().intersects(gracz->getGlobalBounds()))
			{
				std::cout << "kolizja z greencar" << std::endl;
				pojazdy.erase(pojazdy.begin() + j);
				delete greencar;
				this->createGreenCar();
				zycie--;
				this->gracz->setPosition(368.0f, 450.0f);
				break;
			}
		}	
		//obsluga kolizji gracz - coin
		if (bonusCoin* bonuscoin = dynamic_cast<bonusCoin*>(pojazd))
		{
			if (bonuscoin->getGlobalBounds().intersects(gracz->getGlobalBounds()))
			{
				std::cout << "kolizja z coin" << std::endl;
				pojazdy.erase(pojazdy.begin() + j);
				delete bonuscoin;
				this->createBonusCoin();
				//kolizja z coin +100 pkt do wyniku
				wynik += 1000;
				break;
			}
		}
		
		//obluga kolizji gracz-przeszkoda
		if (przeszkoda* przeszkoda1 = dynamic_cast<przeszkoda*>(pojazd))
		{
			if (przeszkoda1->getGlobalBounds().intersects(gracz->getGlobalBounds()))
			{
				std::cout << "kolizja z przeszka" << std::endl;
				pojazdy.erase(pojazdy.begin() + j);
				delete przeszkoda1;
				this->createPrzeszkoda();
				this->createGreenCar();  // w przypadku kolizji dodowane sa nowe obiekt redCar i greenCar 
				this->createRedCar();
				licznikSerc++;
				break;
			}
		
        
		}
		//obluga kolizji gracz-serce
		if (Serce* serce = dynamic_cast<Serce*>(pojazd))
		{
			if (serce->getGlobalBounds().intersects(gracz->getGlobalBounds()))
			{
				std::cout << "kolizja z przeszka" << std::endl;
				pojazdy.erase(pojazdy.begin() + j);
				delete serce;
				zycie++;
				
				break;
			}
		}
		if (licznikSerc == 3)
		{
			createSerce();
			licznikSerc = 0;
		}
			if (zycie == 0)
			{
			std::cout << "koniec zycie, umierasz" << std::endl;
			isPaused = true;
			this->stopMusic();
			}
			// zwiekszanie poziomu trudnosci - dodanie obiektu przeszkoda co 5 sekund
			obstacleTimer += obstacleClock.restart(); // Dodaj czas od ostatniej aktualizacji do licznika

			if (obstacleTimer >= obstacleInterval)
			{
				// Tworzenie nowej przeszkody
				createPrzeszkoda();
				obstacleTimer = obstacleTimer % obstacleInterval; // Ustaw reszte z dzielenia jako nowa wartosc czasu
			}
			//dodawanie serc zwieszkajacych zycie co 15 sekund
			obstacleTimerSerce += obstacleClockSerce.restart(); // Dodaj czas od ostatniej aktualizacji do licznika

			if (obstacleTimerSerce >= obstacleIntervalSerce)
			{
				// tworzenie serca
				createPrzeszkoda();
				obstacleTimerSerce = obstacleTimerSerce % obstacleIntervalSerce; // Ustaw resztê z dzielenia jako nowa wartosc czasu
			}
			
		


	}
	
	//poruszanie gracza
	this->gracz->move(dt);
	this->gracz->setScale(1.5f, 1.5f); // Zmiana skali gracza
	
	 
	wynik += zwiekszaWynik;
	
}





void Gra::render()
{
	this->window->clear(sf::Color::Black);
	//draw game objects 
	//narysowanie t³a
	this->window->draw(this->spriteTlo);
	// Tworzenie obiektu sf::Text
	sf::Font font;
	if (!font.loadFromFile("Ourland.ttf"))
	{
		std::cout << "Error: Failed to load font" << std::endl;
	}
	if (isPaused)
	{
		// Tworzenie obiektu sf::Text
		sf::Font font;
		if (!font.loadFromFile("Ourland.ttf"))
		{
			std::cout << "Error: Failed to load font" << std::endl;
		}

		sf::Text koniecGryText;
		koniecGryText.setFont(font);
		koniecGryText.setCharacterSize(78);
		koniecGryText.setFillColor(sf::Color::Red);
		koniecGryText.setPosition(180.f, 220.f);
		koniecGryText.setString("Koniec Gry");

		sf::Text koniecGryScore;
		koniecGryScore.setFont(font);
		koniecGryScore.setCharacterSize(78);
		koniecGryScore.setFillColor(sf::Color::Red);
		koniecGryScore.setPosition(180.f, 270.f);
		koniecGryScore.setString("WYNIK:" + std::to_string(wynik));

		// Rysowanie obiektu sf::Text
		window->draw(koniecGryScore);
	}
	else
	{
	sf::Text zycieText;
	zycieText.setFont(font);
	zycieText.setCharacterSize(24);
	zycieText.setFillColor(sf::Color::Black);
	zycieText.setPosition(10.f, 10.f);

	// Ustawianie tekstu na podstawie wartoœci zmiennej "zycie"
	zycieText.setString("Zycie: " + std::to_string(zycie));

	// Rysowanie obiektu sf::Text
	window->draw(zycieText);

	//// ustawianie scorText
	sf::Text scoreText;
	scoreText.setFont(font);
	scoreText.setCharacterSize(24);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(500.f, 10.f);

	// Ustawianie tekstu na podstawie wartosci zmiennej "zycie"
	scoreText.setString("Wynik: " + std::to_string(wynik));
	// Rysowanie obiektu sf::scoreText
	window->draw(scoreText);
	// Rysowanie obiektów z kontenera 
	for (auto pojazd : pojazdy)
	{
		window->draw(*pojazd);
	}
	}

	this->window->display();
	
}
