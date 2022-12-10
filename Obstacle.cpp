#include "Obstacle.h"

Obstacle::Obstacle(Interface& interface_ptr, Coordonnees const& position_ptr) : ElementInterface{ "ressources/sprites/Obstacle.png" }, interface{interface_ptr}
{
	type = TypeElement::OBSTACLE;
	position = position_ptr;
}