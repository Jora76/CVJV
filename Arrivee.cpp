#include "Arrivee.h"

Arrivee::Arrivee(Interface& interface_ptr, Coordonnees const& position_ptr) : ElementInterface{ "ressources/sprites/Arrivee.png" }, interface{interface_ptr}
{
	position = position_ptr;
}

void Arrivee::reagirCollision(TypeElement typeAutre, float angle)
{
	if (typeAutre == TypeElement::CURSEUR)
	{
		if (interface.verifierCheckPoints() == true)
		{
			interface.vider();
		}
		else
		{
			interface.reinitialiserGrille();
		}
		valider = false;
	}
}

/*
void Arrivee::compterCheckpoint()
{
	++ checkPointsRecuperes;
}

/*
	Objectif : lier comptage de checkpoints entre Arrivee, Jeu et CheckPoint.
*/