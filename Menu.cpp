#include "Menu.h"

Menu::Menu(sf::Event& event_ptr, sf::RenderWindow& window_ptr, Interface& interface_ptr, Jeu& jeu_ptr) : event{ event_ptr }, window{ window_ptr }, interface { interface_ptr }, jeu{ jeu_ptr }
{

}

void Menu::demarrer()
{
	interface.ajouter(std::make_unique<Titre>(position));
	position.setY(40);
	interface.ajouterBouton(std::make_unique<BoutonJouer>(jeu, position));
	position.setY(40);
	interface.ajouterBouton(std::make_unique<BoutonQuitter>(window, position));
	jeu.initTexte();
}
