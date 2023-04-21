#include "Fenetre.h"

Fenetre::Fenetre(std::string_view const& chemin) : ElementInterface{ chemin }
{
	sprite.setScale(1, 1);
	sprite.setOrigin(1, 1);
	position = { 0, 0 };
}

Fenetre::Fenetre(std::string_view const& chemin, const Coordonnees& position_ptr) : ElementInterface{chemin}/*, position{position_ptr}*/
{
	sprite.setScale(1, 1);
	sprite.setOrigin(0.1, 0.1);
	position = position_ptr;
}
