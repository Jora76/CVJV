#include "Teleporteur.h"

Teleporteur::Teleporteur(const Coordonnees& position_ptr, Interface& interface_ptr) : Panneau{ position, interface_ptr, "ressources/sprites/Mur_vert.png" }
{
	type = TypeElement::PANNEAU_BASE;
	posInit = position_ptr;
	position = position_ptr;
}

void Teleporteur::genererPanneau()
{
	interface.ajouterBouton(std::make_unique<Teleporteur>(posInit, interface));
	type = TypeElement::TP;
}

float Teleporteur::getTypePanneau()
{
	return -1.f;
}