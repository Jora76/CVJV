#pragma once

#include <string_view>
#include <iostream>
#include <fstream>
#include <string>
#include <memory>

#include "Interface.h"
#include "ElementInterface.h"
#include "Curseur.h"
#include "Coordonnees.h"
#include "Arrivee.h"
#include "BoutonGrille.h"
#include "CheckPoint.h"
#include "Faille.h"
#include "Interrupteur.h"
#include "Obstacle.h"
#include "Teleporteur.h"

class Enigme
{
public:
	Enigme(Interface& interface_ptr);
	void lireFichier(std::string_view const& chemin);
	void generer(std::string_view const& caseGrille);

private:
	Coordonnees position{};
	Interface& interface;
	std::vector <int> grille{};
	enum LigneTxt {coordonneesPremiereCase = 4, qtePanneaux = 10, comp = 20, boutonGrille = 21, checkPoint = 22, arrivee = 23, obstacle = 24, depart = 25, faille = 26, interrupteur = 27, ligneSuivante = 28, fin = 29};
	static constexpr int OFFSET{ 40 };
};

