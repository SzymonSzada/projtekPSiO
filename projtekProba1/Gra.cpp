#include "Gra.h"
#include <iostream>
#include <vector>
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
}

Gra::~Gra()
{
	delete this->window;
}
//Accessors

const bool Gra::running() const
{
	return this->window->isOpen();
}

//metody publiczne

void Gra::cratePlayer()
{
	this->gracz = new Gracz();
	//ustawiam pozycje
	this->gracz->setPosition(368.0f, 450.0f);
	this->gracz->setScale(2.0f, 2.0f);
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
	this->redcar = new RedCar();
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
	this->pollEvents();
	//proba aktualizacji animacji klasy gracz
	this->gracz->setAnimation();
	//poruszanie gracza
	float dt = clock.restart().asSeconds(); // Pobierz czas od ostatniej aktualizacji
	this->gracz->move(dt);
}
void Gra::render()
{
	this->window->clear(sf::Color::Black);
	//draw game objects 
	//narysowanie t³a
	this->window->draw(this->spriteTlo);
	//rysowanie gracza
	this->window->draw(*this->gracz);

	this->window->display();

}
