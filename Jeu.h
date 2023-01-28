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
	void gererTexte();

private:
	Interface& interface;
	Enigme &enigme;
	GestionnaireTexte& texte;
	bool enCours{ false };
	short unsigned int compteur{ 0 };
	std::string cheminFenetre;
	std::string cheminEnigme;

	void choisirEnigme();
	void initTexte();
	void continuer();

	Instance instanceActuelle;
	std::string texteConsigne{ "Objectif : Ramassez tous les checkpoints !" };
	std::string texteObjectif{ "Placez les panneaux de manière à emmener le curseur vers l'arrivée." };
	Coordonnees posTxtConsigne{ 172, 85 };
	Coordonnees posTxtObjectif{ 172, 140 };
};

