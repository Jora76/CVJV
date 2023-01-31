#include "Titre.h"

Titre::Titre(Coordonnees& position_ptr) : ElementInterface{"ressources/sprites/Titre2.png"}
{
	position = position_ptr;
	sprite.setScale(sprite.getScale().x * 3.f, sprite.getScale().x * 3.f);
}
