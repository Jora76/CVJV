#include "ElementInterface.h"
#include "GestionnaireRessources.h"

using namespace std;


ElementInterface::ElementInterface(string_view const& chemin)
{
	sprite.setTexture(GestionnaireRessources::getRessource(chemin)); //application de la texture du sprite
	sprite.setScale(sprite.getScale().x / 2.6f, sprite.getScale().x / 2.6f);  //determination de la taille du sprite. De base 100px / 100px, résultat 40px / 40px
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2); //détermination du centre de rotation du sprite
}

void ElementInterface::afficher(sf::RenderWindow& window) const
{
	window.draw(sprite); //dessin du sprite dans la fenetre
}

void ElementInterface::positionner()
{
	sprite.setPosition(position.getX(), position.getY());
}

void ElementInterface::testerCollision(ElementInterface& autre)
{
	auto distance = position.calculerDistance(autre.position);
	
	if (distance <= getRayon() + autre.getRayon())
	{
		autre.reagirCollision(TypeElement::CURSEUR);

		if (autre.type == TypeElement::PANNEAU
			&& reactionDejaAppelee == false
			&& (distance <= getRayon() + autre.getRayon() - 31.f)/* || (distance <= getRayon() + autre.getRayon() - 30.5f)*/)
		{
			reagirCollision(autre.type, autre.getAngle());
			reactionDejaAppelee = true;
			autre.type = TypeElement::PANNEAU_TOUCHE;
		}
		else if (autre.type != TypeElement::PANNEAU && autre.type != TypeElement::TP)
		{
			reagirCollision(autre.type);
		}
		else if (autre.type == TypeElement::TP
			&& distance <= getRayon() + autre.getRayon() - 31.f)
		{
			reagirCollision(autre.type);
		}
	}
	else if (distance > getRayon() + autre.getRayon() && autre.type == TypeElement::PANNEAU_TOUCHE)
	{
		reactionDejaAppelee = false;
		autre.type = TypeElement::PANNEAU;
	}
	
	
	/*
	else if (distance > getRayon() + autre.getRayon() && autre.type == TypeElement::TP_TOUCHE)
	{
		reactionDejaAppelee = false;
		autre.type = TypeElement::TP;
	}*/
		
}
void ElementInterface::reagirCollision(TypeElement typeAutre, float angle)
{}

void ElementInterface::actualiser()
{
/*
	Fonctionnalités communes:
		- Positionner
	Fonctionnalités virtual :
		- Tester collisions (Curseur, panneau)
			- Gerer collisions (Curseur, panneau, Checkpoint, Arrivee)
		- Etat (Checkpoint, Interrupteur(bientot), faille(bientot))
		- Gerer souris (Boutons, CaseGrille)
*/
}

float ElementInterface::getRayon() const
{
	return sprite.getGlobalBounds().height / 2.2f;
}

float ElementInterface::getAngle() const
{
	return sprite.getRotation();
}

TypeElement ElementInterface::getType() const
{
	return type;
}

void ElementInterface::setType(TypeElement changementType)
{
	type = changementType;
}

