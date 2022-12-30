#include "BoutonGrille.h"
#include "Bouton.h"
//#include "Obstacle.h"
#include "Panneau.h"

BoutonGrille::BoutonGrille(Interface& interface_ptr, Coordonnees const& position_ptr) : Bouton{position, "ressources/sprites/Bouton_grille.png" }, interface{interface_ptr}
{
	type = TypeElement::BOUTON_GRILLE;
	position = position_ptr;
	sprite.setScale(sprite.getScale().x * 2.4f, sprite.getScale().x * 2.4f);
}

void BoutonGrille::reagirClic(sf::Event& event)
{
}

void BoutonGrille::setCouleur(bool sourisDessus)
{
	if(sourisDessus)
		sprite.setColor(sf::Color::Color(0, 255, 0, 255));
	else
		sprite.setColor(sf::Color::Color(22, 49, 32, 255));
}