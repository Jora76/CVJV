#include "BoutonJouer.h"
#include "GestionnaireRessources.h"
BoutonJouer::BoutonJouer(sf::RenderWindow& window_ptr, Interface& interface_ptr, Jeu& jeu_ptr, Coordonnees& position_ptr) : Bouton{ position, "ressources/sprites/Bouton_jouer.png" }, window{ window_ptr }, interface { interface_ptr }, jeu{ jeu_ptr }
{
	position = position_ptr;
	//sprite.setScale(sprite.getScale().x / 3.f, sprite.getScale().x / 3.f);
	son.setBuffer(GestionnaireRessources<sf::SoundBuffer>::getRessource("ressources/sons/jouer.wav"));
}

void BoutonJouer::reagirClic(sf::Event& event)
{
	interface.colorer(sf::Color::Black);
	son.play();
	chrono.restart().asSeconds();
	window.clear();
	window.display();
	while (chrono.getElapsedTime() < son.getBuffer()->getDuration()) {
	}
	jeu.continuer();
}
