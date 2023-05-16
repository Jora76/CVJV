#include "Arrivee.h"

Arrivee::Arrivee(Interface& interface_ptr, Coordonnees const& position_ptr) : ElementInterface{ "ressources/sprites/Arrivee.png" }, interface{interface_ptr}
{
	type = TypeElement::ARRIVEE;
	position = position_ptr;
	son.setBuffer(GestionnaireRessources<sf::SoundBuffer>::getRessource("ressources/sons/arrivee.wav"));
}

void Arrivee::reagirCollision(TypeElement typeAutre, float angle)
{
	if (typeAutre == TypeElement::CURSEUR)
	{
		if (interface.verifierCheckPoints() == true)
		{
			son.play();
			chrono.restart().asSeconds();
			while (chrono.getElapsedTime() < son.getBuffer()->getDuration()) {
			}
			interface.vider();
		}
		else
		{
			interface.reinitialiserGrille();
		}
		valider = false;
	}
}