#include "CheckPoint.h"

CheckPoint::CheckPoint(Interface& interface_ptr, Coordonnees const& position_ptr) : ElementInterface{ "ressources/sprites/Checkpoint.png" }, interface {interface_ptr}
{
	position = position_ptr;
}