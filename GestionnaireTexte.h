#pragma once

#include <SFML/Graphics.hpp>
#include <string_view>
#include <memory>
#include <array>
#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
#include "Coordonnees.h"
#include "VarelaRound-Regular.h" //police

class GestionnaireTexte
{
public:
	GestionnaireTexte(sf::RenderWindow& window_ptr);
	GestionnaireTexte(std::string& contenu, Coordonnees& position);
	void setStyle(sf::Text& texte, int taille);
	//void defiler(sf::Text& texte);
	void ajouter(std::string& contenuTxt, const Coordonnees& position, int typeTexte, int taille = 20);
	void actualiserCompteurs(size_t i, std::string& contenu);
	void afficher();
	void afficher(sf::Text& texte);
	void vider();
private:
	sf::Font police;
	sf::RenderWindow& window;
	sf::Clock chrono;
	sf::Time test = sf::milliseconds(20.f);
	unsigned short int caractere = 0;
	//std::vector <sf::Text> textesDialogues;
	std::vector <sf::Text> textesCompteurs;
	std::vector <sf::Text> textesInstruction;
	std::vector <sf::Text> textesAutres;
	sf::Text dialogueActuel;
	enum TypeTexte
	{
		COMPTEUR,
		INSTRUCTION,
		DIALOGUE,
		AUTRE
	};
};
