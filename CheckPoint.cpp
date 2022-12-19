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

		supprimer = true;
	}
}