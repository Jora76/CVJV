#include "Faille.h"

Faille::Faille(Interface& interface_ptr, Coordonnees const& position_ptr) : ElementInterface{ "ressources/sprites/Faille_ouverte.png" }, interface{interface_ptr}
{
	type = TypeElement::AUTRE;
	position = position_ptr;
}

//void Faille::reagirCollision(TypeElement typeAutre)
//{
//	if (typeAutre == TypeElement::CURSEUR)
//	{
//		if (!Interrupteur::ouvert)
//			type = TypeElement::OBSTACLE;
//		else
//			type = TypeElement::AUTRE;
//	}
//}