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
