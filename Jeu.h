#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

//#include "Interface.h"
#include "Fenetre.h"
#include "BoutonValider.h"
#include "BoutonSupprimer.h"
#include "Enigme.h"
#include "GestionnaireRessources.h"
#include "Curseur.h"

class Jeu
{
public :
	Jeu(Interface& interface_ptr, Enigme& enigme_ptr);
	void demarrer();
	void afficherTexte(sf::RenderWindow& fenetre);
	void actualiser();
	void terminer();

private:
	Interface& interface;
	Enigme &enigme;
	bool enCours{ false };
	short unsigned int compteur{ 0 };
	std::string cheminFenetre;
	std::string cheminEnigme;
	sf::Font police{};
	//std::unique_ptr<sf::Text> texteObjectif{ nullptr };

	void choisirEnigme();
	void definirTexte(sf::Text& texte);
	void retirerTexte();
	void continuer();
};

