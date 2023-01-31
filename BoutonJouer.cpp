#include "BoutonJouer.h"

BoutonJouer::BoutonJouer(Interface& interface_ptr, Jeu& jeu_ptr, Coordonnees& position_ptr) : Bouton{ position, "ressources/sprites/Bouton_jouer.png" }, interface { interface_ptr }, jeu{ jeu_ptr }
{
	position = position_ptr;
	//sprite.setScale(sprite.getScale().x / 3.f, sprite.getScale().x / 3.f);
}

void BoutonJouer::reagirClic(sf::Event& event)
{
	interface.vider();
	jeu.continuer();
}

void BoutonJouer::reagirSouris(bool sourisDessus)
{
}
