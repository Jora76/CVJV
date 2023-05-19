#pragma once

#include "Interface.h"
#include "GestionnaireRessources.h"

class Arrivee :
	public ElementInterface
{
public:
	explicit Arrivee(Interface& interface_ptr, Coordonnees const& position_ptr);
private:
	Interface& interface;
	sf::Sound clear;
	sf::Sound erreur;
	sf::Clock chrono;

	virtual void reagirCollision(TypeElement typeAutre, float angle = 0) override;
};

