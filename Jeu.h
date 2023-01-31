#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

#include "Fenetre.h"
#include "BoutonValider.h"
#include "BoutonSupprimer.h"
#include "Enigme.h"
#include "GestionnaireRessources.h"
#include "Curseur.h"
#include "GestionnaireTexte.h"

enum class Instance
{
	MENU,
	DIALOGUE,
	ENIGME,
};

class Jeu
{
public :
	Jeu(Interface& interface_ptr, Enigme& enigme_ptr, GestionnaireTexte& texte_ptr);
	void demarrer();
	void actualiser();
	void terminer();
	void initTexte();
	void continuer();

private:
	Interface& interface;
	Enigme &enigme;
	GestionnaireTexte& texte;
	short unsigned int compteur{ 0 };
	std::string cheminFenetre;
	std::string cheminEnigme;

	void choisirEnigme();
	void actualiserTexte();

	Instance instanceActuelle = Instance::MENU;
	std::string texteConsigne{ "Objectif : Ramassez tous les checkpoints !" };
	std::string texteObjectif{ "Placez les panneaux de manière à emmener le curseur vers l'arrivée." };
	std::string texteMenu{ "Proposé par Joris BORGES." };
	std::string texteEchap{ "Appuyez sur <Echap> à tout moment pour quitter le mode plein écran." };

	Coordonnees posTxtConsigne{ 172, 85 };
	Coordonnees posTxtObjectif{ 172, 140 };
	Coordonnees posTxtMenu{ 1000, 650 };
	Coordonnees posTxtEchap{ 10, 20 };
};

