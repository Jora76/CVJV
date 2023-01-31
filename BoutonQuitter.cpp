#include "BoutonQuitter.h"

BoutonQuitter::BoutonQuitter(sf::RenderWindow& window_ptr, Coordonnees& position_ptr) : Bouton{ position, "ressources/sprites/Bouton_quitter.png" }, window { window_ptr }
{
	position = position_ptr;
	//sprite.setScale(sprite.getScale().x / 3.f, sprite.getScale().x / 3.f);
}

void BoutonQuitter::reagirSouris(bool sourisDessus)
{
}

void BoutonQuitter::reagirClic(sf::Event& event)
{
	window.close();
}