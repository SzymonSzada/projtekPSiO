#include "Gra.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include "RedCar.h"
#include "GreenCar.h"
#include "bonusCoin.h"
#include "przeszkoda.h"

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
{
	this->window->clear(sf::Color::Black);

	// Tworzenie obiektu sf::Text
	sf::Font font;
	if (!font.loadFromFile("Ourland.ttf"))
	{
		std::cout << "Error: Failed to load font" << std::endl;
	}

	sf::Text startText;
	startText.setFont(font);
	startText.setCharacterSize(28);
	startText.setFillColor(sf::Color::White);
	startText.setPosition(200.f, 250.f);
	startText.setString("Nacisnij SPACJE, aby zagrac");

	sf::Text exitText;
	exitText.setFont(font);
	exitText.setCharacterSize(24);
	exitText.setFillColor(sf::Color::White);
	exitText.setPosition(220.f, 300.f);
	exitText.setString("Nacisnij Q, aby wyjsc");

	// Rysowanie obiektu sf::Text
	window->draw(startText);
	window->draw(exitText);
	this->window->display();
}
void Gra::run()
{
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
	}

	while (running())
	{
		update();
		render();
	}
}

//pauzowanie gry
bool isPaused = false;


//konstruktor destruktor
Gra::Gra()
{
	this->initVariables();
	this->initWindow();
	this->stworzTlo();
	//tworznie obiektow na planszy
	this->createPlayer();
	this->createRedCar();
	this->createRedCar();
	this->createGreenCar();
	this->createGreenCar();
	this->createBonusCoin();
	this->createBonusCoin();
	this->createPrzeszkoda();
	//zainicjowanie generatora liczb losowych
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	//dodanie licznika
	zycie = 4;
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
	this->pojazdy.push_back(bonuscoin); // Dodaj obiekt GreenCar do kontenera
}

void Gra::createPrzeszkoda()
{
	// Losuj pozycjê dla GreenCar w obszarze (x1, y1) - (x2, y2)
	float x = x1 + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (x2 - x1)));
	float y = y1 + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (y2 - y1)));

	przeszkoda* przeszkoda1 = new przeszkoda();
	przeszkoda1->setPosition(x, y);
	if (przeszkoda1 != nullptr) 
	{
		this->pojazdy.push_back(przeszkoda1); // Dodaj obiekt GreenCar do kontenera
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
		return; // Jeœli gra jest spauzowana, opuœæ metodê update()
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
		
		//poruszanie obiektow redCar w dó³
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
				break;
			}
		}
		//poruszanie obiekow greenCar w góre
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
				break;
			}
		}
		
			if (zycie == 0)
			{
			std::cout << "koniec zycie, umierasz" << std::endl;
			isPaused = true;
			
			}
			
		


	}
	
	//poruszanie gracza
	this->gracz->move(dt);
	this->gracz->setScale(1.5f, 1.5f); // Zmiana skali gracza

	
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
		koniecGryText.setCharacterSize(48);
		koniecGryText.setFillColor(sf::Color::Red);
		koniecGryText.setPosition(300.f, 250.f);
		koniecGryText.setString("Koniec Gry");

		// Rysowanie obiektu sf::Text
		window->draw(koniecGryText);
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


	// Rysowanie obiektów z kontenera 
	for (auto pojazd : pojazdy)
	{
		window->draw(*pojazd);
	}
	}

	this->window->display();

}
