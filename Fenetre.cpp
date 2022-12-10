#include "Fenetre.h"

Fenetre::Fenetre(std::string_view const& chemin) : ElementInterface{ chemin }
{
	sprite.setScale(1, 1);
	sprite.setOrigin(1, 1);
}