#include "PanneauDirection.h"

PanneauDirection::PanneauDirection(const Coordonnees& position_ptr, const float angle_ptr, Interface& interface_ptr) : Panneau{ position, interface_ptr,  "ressources/sprites/Panneau_droite.png" }
{
	type = TypeElement::PANNEAU_BASE;
	position = position_ptr;
	posInit = position_ptr;
	angle = angle_ptr;
	sprite.setRotation(angle);
}

void PanneauDirection::genererPanneau()
{
	interface.ajouterBouton(std::make_unique<PanneauDirection>(posInit, angle, interface));
	type = TypeElement::PANNEAU;
}

float PanneauDirection::getTypePanneau()
{
	return angle;
}

//voir valeur angle lors du test de drag du panneau bas. Quand je teste si il reste des panneaux bas