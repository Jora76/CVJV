#include "Menu.h"

Menu::Menu(sf::Event& event_ptr, sf::RenderWindow& window_ptr, Interface& interface_ptr, Jeu& jeu_ptr) : event{ event_ptr }, window{ window_ptr }, interface { interface_ptr }, jeu{ jeu_ptr }
{

}

void Menu::demarrer()
{
	interface.ajouter(std::make_unique<Titre>(position));
	position.setX(620);
	position.setY(400);
	interface.ajouterBouton(std::make_unique<BoutonJouer>(window, interface, jeu, position));
	position.setY(550);
	interface.ajouterBouton(std::make_unique<BoutonQuitter>(window, position));
	jeu.initTexte();
	position.setX(780);
	position.setY(200);
}
