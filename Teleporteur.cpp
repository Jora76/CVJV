#include "Teleporteur.h"

Teleporteur::Teleporteur(const Coordonnees& position_ptr) : Bouton{ position, "ressources/sprites/Mur_vert.png" }
{
	type = TypeElement::TP;
	position = position_ptr;
	sprite.setScale(sprite.getScale().x, sprite.getScale().x);
}

void Teleporteur::reagirClic(sf::Event& event)
{}

void Teleporteur::reagirCollision(TypeElement typeAutre, float angle)
{
	if (typeAutre == TypeElement::CURSEUR)
		sprite.setColor(sf::Color::Color(0, 255, 0, 255));
}
void Teleporteur::setCouleur(bool sourisDessus)
{
	if (sourisDessus)
		sprite.setColor(sf::Color::Color(0, 255, 0, 255));
	else
		sprite.setColor(sf::Color::Color(22, 49, 32, 0));
}