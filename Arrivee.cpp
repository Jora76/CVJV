#include "Arrivee.h"

Arrivee::Arrivee(Interface& interface_ptr, Coordonnees const& position_ptr) : ElementInterface{ "ressources/sprites/Arrivee.png" }, interface{interface_ptr}
{
	position = position_ptr;
}

//void Arrivee::reagirCollision(TypeElement typeAutre)
//{
//	sprite.setColor(sf::Color::Red);
//}