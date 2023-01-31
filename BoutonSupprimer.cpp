#include "BoutonSupprimer.h"
#include <iostream>

BoutonSupprimer::BoutonSupprimer(Interface& interface_ptr) : Bouton(position, "ressources/sprites/Bouton_supprimer.png"), interface { interface_ptr }
{
	position = { 1110.f, 500.f };
	sprite.setScale(1, 1);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
}

void BoutonSupprimer::reagirClic(sf::Event& event)
{
	if(!valider)
		interface.viderGrille();
}

void BoutonSupprimer::reagirSouris(bool sourisDessus)
{
	if (sourisDessus)
		sprite.setColor(sf::Color::Color(0, 255, 0, 255));
	else
		sprite.setColor(sf::Color::Color(22, 49, 32, 255));
}