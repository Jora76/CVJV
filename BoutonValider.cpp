#include "BoutonValider.h"
#include <iostream>

BoutonValider::BoutonValider(Interface& interface_ptr) : Bouton(position, "ressources/sprites/Bouton_valider.png"), interface{interface_ptr}
{
	position = { 1110.f, 600.f };
	sprite.setScale(1, 1);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
}

void BoutonValider::reagirClic(sf::Event& event)
{
	valider = true;
}

void BoutonValider::setCouleur(bool sourisDessus)
{
	if (sourisDessus)
		sprite.setColor(sf::Color::Color(0, 255, 0, 255));
	else
		sprite.setColor(sf::Color::Color(22, 49, 32, 255));
}