#include "Arrivee.h"

Arrivee::Arrivee(Interface& interface_ptr, Coordonnees const& position_ptr) : ElementInterface{ "ressources/sprites/Arrivee.png" }, interface{interface_ptr}
{
	type = TypeElement::ARRIVEE;
	position = position_ptr;
	clear.setBuffer(GestionnaireRessources<sf::SoundBuffer>::getRessource("ressources/sons/arrivee.wav"));
	erreur.setBuffer(GestionnaireRessources<sf::SoundBuffer>::getRessource("ressources/sons/erreur.wav"));
}

void Arrivee::reagirCollision(TypeElement typeAutre, float angle)
{
	if (typeAutre == TypeElement::CURSEUR)
	{
		if (interface.verifierCheckPoints() == true)
		{
			clear.play();
			chrono.restart().asSeconds();
			while (chrono.getElapsedTime() < clear.getBuffer()->getDuration()) {
			}
			interface.vider();
		}
		else
		{
			erreur.play();
			chrono.restart().asSeconds();
			while (chrono.getElapsedTime() < erreur.getBuffer()->getDuration()) {
			}
			interface.reinitialiserGrille();
		}
		valider = false;
	}
}