#include "Curseur.h"

#include <iostream>

Curseur::Curseur(Interface& interface_ptr, Coordonnees const& position_ptr) : Bouton{position, "ressources/sprites/Curseur.png" }, interface {interface_ptr}
{
	type = TypeElement::CURSEUR;
	position = position_ptr; //initialisation de la position du sprite
	posInit = position_ptr;
}

void Curseur::mettreAJour(float temps) //methode qui calcule les déplacements du curseur en fonction du panneau rencontré et de l'état du bonton valider
{
	if (position.limiteGrille() == true)
	{
		resetPosition();
	}
	if(valider)
	{
		vitesse = Vecteur::creerDepuisAngle(sprite.getRotation());
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
	if(valider)
		interface.gererCollisions(this);
}

void Curseur::testerCollision(ElementInterface& autre)
{
	auto distance = position.calculerDistance(autre.getPos());

	if (distance <= getRayon() + autre.getRayon())
	{
		autre.reagirCollision(TypeElement::CURSEUR);

		if (autre.getType() == TypeElement::PANNEAU
			&& (distance <= getRayon() + autre.getRayon() - 31.f))
		{
			reagirCollision(autre.getType(), autre.getAngle());
			autre.setType(TypeElement::PANNEAU_TOUCHE);
		}
		else if (autre.getType() != TypeElement::PANNEAU && autre.getType() != TypeElement::TP)
		{
			reagirCollision(autre.getType());
		}
		else if (autre.getType() == TypeElement::TP
			&& distance <= getRayon() + autre.getRayon() - 31.f)
		{
			reagirCollision(autre.getType());
		}
	}
	else if (distance > getRayon() + autre.getRayon() && autre.getType() == TypeElement::PANNEAU_TOUCHE)
	{
		autre.setType(TypeElement::PANNEAU);
	}
}

void Curseur::reagirCollision(TypeElement typeAutre, float angle)
{
	int testAngle = sprite.getRotation();
	if (typeAutre != type && typeAutre != TypeElement::AUTRE)
	{
		switch (typeAutre)
		{
		case TypeElement::OBSTACLE:
			Interrupteur::setOuvert();
			resetPosition();
			break;

		case TypeElement::PANNEAU :
			valider = false;
				sprite.setRotation(angle);
				vitesse -= vitesse;
				valider = true;
			break;
		case TypeElement::TP :
			valider = false;
			vitesse -= vitesse;
			switch (testAngle)
			{
				case 0:
					position.setX(80);
					break;
				case 90:
					position.setY(80);
					break;
				case 180:
					position.setX(-80);
					break;
				case 270:
					position.setY(-80);
					break;
			}
			valider = true;
			break;
		case TypeElement::ARRIVEE:
			resetPosition();
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
			dernierClic.restart();
		}
	}
}

void Curseur::setCouleur(bool sourisDessus)
{
	if (sourisDessus)
		sprite.setColor(sf::Color::Color(0, 255, 0, 255));
	else
		sprite.setColor(sf::Color::Color(0, 150, 0, 255));
}

void Curseur::resetPosition()
{
	position = posInit;
	valider = false;
}