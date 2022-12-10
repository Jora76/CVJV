#include "Interrupteur.h"


Interrupteur::Interrupteur(Interface& interface_ptr, Coordonnees const& position_ptr) : ElementInterface{ "ressources/sprites/Interrupteur.png" }, interface{interface_ptr}
{
	position = position_ptr;
}

//void Interrupteur::reagirCollision(TypeElement typeAutre)
//{
//	if (typeAutre == TypeElement::CURSEUR)
//	{
//		if (ouvert)
//			!ouvert;
//		else
//			ouvert;
//	}
//}