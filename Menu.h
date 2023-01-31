#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "Interface.h"
#include "Jeu.h"
#include "BoutonJouer.h"
#include "BoutonQuitter.h"
#include "Coordonnees.h"
#include "Titre.h"

class Menu
{
public:
	Menu(sf::Event& event_ptr, sf::RenderWindow& window_ptr, Interface& interface_ptr, Jeu& jeu_ptr);
	void demarrer();
private:
	Jeu& jeu;
	Interface& interface;
	Coordonnees position{ 750, 200 };
	sf::Event& event;
	sf::RenderWindow& window;
};

