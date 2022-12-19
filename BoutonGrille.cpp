#include "BoutonGrille.h"
#include "Bouton.h"
//#include "Obstacle.h"
#include "Teleporteur.h"

BoutonGrille::BoutonGrille(Interface& interface_ptr, Coordonnees const& position_ptr) : Bouton{position, "ressources/sprites/Bouton_grille.png" }, interface{interface_ptr}
{
	position = position_ptr;
	sprite.setScale(sprite.getScale().x * 2.4f, sprite.getScale().x * 2.4f);
}

void BoutonGrille::reagirClic(sf::Event& event)
{
	std::cout << selection << "avant" << std::endl;
	selection = true;
		while (selection == true)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				selection = false;
				supprimer = true;
				interface.ajouterBouton(std::make_unique<Panneau>(position, 270.f));
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				selection = false;
				supprimer = true;
				interface.ajouterBouton(std::make_unique<Panneau>(position, 180.f));
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				selection = false;
				supprimer = true;
				interface.ajouterBouton(std::make_unique<Panneau>(position, 90.f));
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				selection = false;
				supprimer = true;
				interface.ajouterBouton(std::make_unique<Panneau>(position, 0.f));
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				selection = false;
				supprimer = true;
				interface.ajouterBouton(std::make_unique<Teleporteur>(position));
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && dernierClic.getElapsedTime().asSeconds() > 0.2)
			{
				std::cout << selection << "test" << std::endl;
				selection = false;
				dernierClic.restart();
			}

			//if (event.type == sf::Event::MouseButtonPressed) //modif
			//{
			//	if (event.mouseButton.button == sf::Mouse::Left)
			//	{
			//		std::cout << selection << "TEST" << std::endl;
			//		selection = false;
			//	}
			//}
		}
	
}

void BoutonGrille::setCouleur(bool sourisDessus)
{
	if(sourisDessus)
		sprite.setColor(sf::Color::Color(0, 255, 0, 255));
	else
		sprite.setColor(sf::Color::Color(22, 49, 32, 255));
}