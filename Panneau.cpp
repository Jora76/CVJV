#include "Panneau.h"

Panneau::Panneau(const Coordonnees& position_ptr, const float angle_ptr) : Bouton{position, "ressources/sprites/Panneau_droite.png" }
{
	type = TypeElement::PANNEAU;
	position = position_ptr;
	sprite.setRotation(angle_ptr);
}

void Panneau::reagirClic(sf::Event& event)
{}