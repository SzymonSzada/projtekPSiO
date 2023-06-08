#include "Gra.h"
#include <iostream>
#include <vector>
#include <cstdlib>
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

//konstruktor destruktor
Gra::Gra()
{
	this->initVariables();
	this->initWindow();
	this->stworzTlo();
	this->createPlayer();
	this->createRedCar();
	this->createRedCar();
	this->createGreenCar();
	this->createGreenCar();
	this->createBonusCoin();
}

Gra::~Gra()
{
	delete this->window;
	//zwalnianie pamieci
	for (auto pojazd : pojazdy)
	{
		delete pojazd;
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
		//std::cout << x << std::endl;
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
	float y2 = 600.0f; // dolny y
	
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

void Gra::createBonusCoin()
{
	// Zainicjalizuj generator liczb losowych
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	//zmienne opisujace pole generowania obiekow
	float x1 = 134.0f; // lewy x
	float y1 = 0.0f; // górny y
	float x2 = 504.0f; // prawy x
	float y2 = 537.0f; // dolny y
	for (int i = 0; i < 2; i++)
	{
		// Losuj pozycjê dla GreenCar w obszarze (x1, y1) - (x2, y2)
		float x = x1 + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (x2 - x1)));
		float y = y1 + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (y2 - y1)));

		bonusCoin* bonuscoin = new bonusCoin();
		bonuscoin->setPosition(x, y);
		this->pojazdy.push_back(bonuscoin); // Dodaj obiekt GreenCar do kontenera

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
	float dt = clock.restart().asSeconds(); // Pobierz czas od ostatniej aktualizacji
	this->pollEvents();
	//aktualizacja animacji obiektow z kontenera
	for (int j = 0; j < pojazdy.size();j++)
	{
		auto pojazd = pojazdy[j];
		pojazd->setAnimation();
		pojazd->setScale(2.0f, 2.0f); //zmiana rozmiaru textury
		//poruszanie obiektow redCar w dó³
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
		}
		
		//poruszanie obiekow greenCar w góre
		else if (GreenCar* greencar = dynamic_cast<GreenCar*>(pojazd))
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
	
	// Rysowanie obiektów z kontenera 
	for (auto pojazd : pojazdy)
	{
		window->draw(*pojazd);
	}

	this->window->display();

}
