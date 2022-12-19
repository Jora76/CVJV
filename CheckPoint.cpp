#include "CheckPoint.h"

CheckPoint::CheckPoint(Interface& interface_ptr, Coordonnees const& position_ptr) : ElementInterface{ "ressources/sprites/Checkpoint.png" }, interface {interface_ptr}
{
	type = TypeElement::CHECKPOINT;
	position = position_ptr;
}

void CheckPoint::reagirCollision(TypeElement typeAutre, float angle)
{
	if (typeAutre == TypeElement::CURSEUR)
	{
		type = TypeElement::CHECKPOINT_RECUPERE;
	}
}

void CheckPoint::actualiser()
{
	if (type == TypeElement::CHECKPOINT)
		sprite.setColor(sf::Color::White);
	else
		sprite.setColor(sf::Color::Color(0, 0, 0, 0));
}