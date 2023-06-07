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
	this->cratePlayer();
	this->crateRedCar();
	this->crateGreenCar();
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

void Gra::cratePlayer()
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

void Gra::crateRedCar()
{
	// Zainicjalizuj generator liczb losowych
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	//zmienne opisujace pole generowania obiekow
	float x1 = 163.4f; // lewy x
	float y1 = 100.0f; // górny y //-700 by³o 
	float x2 = 340.85f; // prawy x
	float y2 = 130.0f; // dolny y //30 by³o
	for (int i = 0; i < 2; i++)
	{
		// Losuj pozycjê dla RedCar w obszarze (x1, y1) - (x2, y2)
		float x = x1 + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (x2 - x1)));
		float y = y1 + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (y2 - y1)));

		RedCar* redcar = new RedCar();
		redcar->setPosition(x, y);
		//granice do kolizji z obiektem redCar
		redcar->setBounds(0.0f, 650.0f, 840.0f, 0.0f);
		this->pojazdy.push_back(redcar); // Dodaj obiekt RedCar do kontenera
	}
}

void Gra::crateGreenCar()
{
	// Zainicjalizuj generator liczb losowych
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	//zmienne opisujace pole generowania obiekow
	float x1 = 424.0f; // lewy x
	float y1 = 580.0f; // górny y
	float x2 = 620.85f; // prawy x
	float y2 = 600.0f; // dolny y
	for (int i = 0; i < 2; i++)
	{
		// Losuj pozycjê dla RedCar w obszarze (x1, y1) - (x2, y2)
		float x = x1 + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (x2 - x1)));
		float y = y1 + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (y2 - y1)));

		GreenCar* greencar = new GreenCar();
		greencar->setPosition(x, y);
		this->pojazdy.push_back(greencar); // Dodaj obiekt GreenCar do kontenera
		
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

	// Aktualizacja animacji obiektów z kontenera
	for (auto it = pojazdy.begin(); it != pojazdy.end();)
	{
		auto pojazd = *it;
		pojazd->setAnimation();
		pojazd->setScale(2.0f, 2.0f); // Zmiana rozmiaru textury

		// Poruszanie obiektów RedCar w dó³
		if (RedCar* redcar = dynamic_cast<RedCar*>(pojazd))
		{
			redcar->moveDown(dt);
			float granicaGora = 600.0f; // Górna granica
			float granicaDol = 700.0f; // Dolna granica


			if (redcar->getPosition().y > granicaDol)
			{
				delete redcar;
				it = pojazdy.erase(it);
				this->crateRedCar(); // Tworzenie nowego obiektu RedCar
				continue; // PrzejdŸ do kolejnej iteracji pêtli
			}
		}

		// Poruszanie obiektów GreenCar w górê
		else if (GreenCar* greencar = dynamic_cast<GreenCar*>(pojazd))
		{
			greencar->moveUp(dt);
		}

		++it;
	}

	// Poruszanie gracza
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
