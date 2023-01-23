#pragma once

#include <SFML/Graphics.hpp>
#include <string_view>
#include <memory>
#include <array>
#include <iostream>
#include "Coordonnees.h"
#include "VarelaRound-Regular.h" //police
//#inclu
class GestionnaireTexte
{
public:
	GestionnaireTexte(sf::RenderWindow& window_ptr);
	GestionnaireTexte(std::string& contenu, Coordonnees& position);
	void setStyle(sf::Text& texte);
	void defiler(sf::Text& texte);
	void positionner();
	void ajouter(std::string& contenuTxt, Coordonnees& position);
	void actualiserCompteurs(size_t i, std::string& contenu);
	void afficher(/*sf::Text& texte*/);
	void vider();
private:
	sf::Font police;
	sf::Clock chrono;/*
	Coordonnees& position;
	std::string& contenu;*/
	sf::RenderWindow& window;
	unsigned short int caractere = 0;
	//std::vector <sf::Text> textesDialogues;
	std::vector <sf::Text> textesCompteurs;
};
