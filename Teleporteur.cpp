#include "Teleporteur.h"

Teleporteur::Teleporteur(const Coordonnees& position_ptr, Interface& interface_ptr) : Panneau{ position, interface_ptr, "ressources/sprites/Mur_vert.png" }/*, interface{interface_ptr}*/
{
	type = TypeElement::PANNEAU_BASE;
	posInit = position_ptr;
	position = position_ptr;
}


//void Teleporteur::reagirCollision(TypeElement typeAutre, float angle)
//{
//	if (typeAutre == TypeElement::CURSEUR)
//		sprite.setColor(sf::Color::Color(0, 255, 0, 0));
//}/*
/*void Teleporteur::setCouleur(bool sourisDessus)
{
	sprite.setColor(sf::Color::Color(0, 255, 0, 255));
}*/

void Teleporteur::genererPanneau()
{
	interface.ajouterBouton(std::make_unique<Teleporteur>(posInit, interface));
	type = TypeElement::TP;
}