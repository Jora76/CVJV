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
{}

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

