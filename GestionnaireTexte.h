#pragma once

#include <SFML/Graphics.hpp>
#include <string_view>
#include <memory>
#include <array>
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
	//void ajouter(std::string& contenuTxt, sf::RenderWindow& window);
	//void actualiserCompteurs(std::array <unsigned short int, 4>& compteurs);
	void afficher(sf::Text& texte);
private:
	sf::Font police;
	sf::Clock chrono;/*
	Coordonnees& position;
	std::string& contenu;*/
	sf::RenderWindow& window;
	unsigned short int caractere = 0;
	//std::vector <sf::Text> textesDialogues;
	//std::array <std::string, 5> compteursPanneaux;
	//std::vector <sf::Text> textesInstance;
};
