#include "Interrupteur.h"

Interrupteur::Interrupteur(Interface& interface_ptr, Coordonnees const& position_ptr) : ElementInterface{ "ressources/sprites/Interrupteur.png" }, interface{interface_ptr}
{
	position = position_ptr;
}

void Interrupteur::reagirCollision(TypeElement typeAutre, float angle)
{
	if (typeAutre == TypeElement::CURSEUR)
	{
		if (dernierPassage.getElapsedTime().asSeconds() > 2)
		{
			if (ouvert)
				ouvert = false;
			else if (!ouvert)
				ouvert = true;
		}
		dernierPassage.restart();
	}
}