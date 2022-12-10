#include "Curseur.h"

#include<iostream>

Curseur::Curseur(Interface& interface_ptr, Coordonnees const& position_ptr) : Bouton{position, "ressources/sprites/Curseur.png" }, interface {interface_ptr}
{
	type = TypeElement::CURSEUR;
	position = position_ptr; //initialisation de la position du sprite
	posInit = position_ptr;
}

void Curseur::mettreAJour(float temps) //methode qui calcule les déplacements du curseur en fonction du panneau rencontré et de l'état du bonton valider
{
	if(valider)
	{
		vitesse += Vecteur::creerDepuisAngle(ACCELERATION * temps, sprite.getRotation());
	}
	else
	{
		vitesse -= vitesse;
	}
}

void Curseur::actualiser()
{
	auto tempsBoucle = chrono.restart().asSeconds();
	mettreAJour(tempsBoucle);
	auto deplacement = vitesse * tempsBoucle;
	position += deplacement;
	sprite.setPosition(position.getX(), position.getY());
	interface.gererCollisions(this);
}

void Curseur::reagirCollision(TypeElement typeAutre, float angle)
{
	if (typeAutre != type && typeAutre != TypeElement::AUTRE)
	{
		/*if (typeAutre == TypeElement::OBSTACLE)
		{
			position = posInit;
			valider = false;
		}
		else if (typeAutre == TypeElement::PANNEAU)
		{
			sprite.setRotation(angle - sprite.getRotation());
		}*/
		switch (typeAutre)
		{
		case TypeElement::OBSTACLE :
			position = posInit;
			valider = false;
			break;

		case TypeElement::PANNEAU :
			if (test != sprite.getRotation())
			{
				sprite.setRotation(abs(angle - sprite.getRotation()));
				test = sprite.getRotation();
			}
			break;
		default:
			break;
		}
	}
}

void Curseur::reagirClic(sf::Event& event)
{
	if (dernierClic.getElapsedTime().asSeconds() > 0.2)
	{
		if (!valider)
		{
			sprite.setRotation(sprite.getRotation() + 90);
			std::cout << sprite.getRotation() << std::endl;
			dernierClic.restart();
		}
	}
}
	
/*
Pour rotation curseur lorsqu'il rencontre panneau. Tu prends l'attribut angle de Panneau et
tu le soustrais à l'angle de rotation du Curseur

Problème : La condition test != sprite.getRotation() permet de changer la rotation du curseur
mais qu'une seule et meme fois. Donc faut changer de strat. Tout en corrigeant le bug du chacarron macarron.
Voir bug du curseur qui fait un chacarron macarron quand tu cliques dessus. Origine du bug 
Bouton::testerClic() -> if(event.type == sf::Event::MouseButtonReleased) qui tourne en boucle 
tant que la souris garde les memes coordonnees que celles relevées lors du clic release.
*/