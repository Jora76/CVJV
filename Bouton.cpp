#include "Bouton.h"

bool Bouton::valider = false;

Bouton::Bouton(Coordonnees const& position_ptr, std::string_view chemin) : ElementInterface {chemin}
{
	type = TypeElement::AUTRE;
}

bool Bouton::sourisEstDessus(sf::Event& event, sf::RenderWindow& window)
{
	float sourisX = static_cast <float>(sf::Mouse::getPosition(window).x);
	float sourisY = static_cast <float>(sf::Mouse::getPosition(window).y);

	float btnxPosWidht = sprite.getPosition().x + sprite.getGlobalBounds().width / 2;
	float btnyPosHeight = sprite.getPosition().y + sprite.getGlobalBounds().height / 2;

	float btnxPosReelle = sprite.getPosition().x - sprite.getGlobalBounds().width / 2;
	float btnyPosReelle = sprite.getPosition().y - sprite.getGlobalBounds().height / 2;

	if ((sourisX < btnxPosWidht && sourisX > btnxPosReelle && sourisY < btnyPosHeight && sourisY > btnyPosReelle) || type == TypeElement::PANNEAU_DRAG)
	{
		setCouleur(true);
		testerClic(event, window);
		return true;
	}
	else
	{
		setCouleur(false);
		return false;
	}
}

void Bouton::testerClic(sf::Event& event, sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		reagirClic(event);
}	

void Bouton::supprimerPanneau()
{
	supprimer = true;
}

/*
-------------------------
----------------------------------------------------------------------------------------			
			*/
/*
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		reagirClic();*/
		
/*
	 � corriger : (r�gl�)
		- faire toutes les r�actions au clic

		- voir pour les couleurs de bouton (pour boutons incluant des dessins � l'int�rieur
		pourquoi pas mettre la texture du bouton juste en fond et charger une autre texture incluant
		le dessin � l'int�rieur)
		Exemple : pour BoutonValider, 
		juste mettre le fond du bouton et include la petite virgule dans un autre sprite)

		- D�s qu'il y a une s�lection, elle ne s'annule plus 
		Le fait de recliquer pour d�selectionner ne fonctionne pas 
		(r�gl� � moiti� : Oblig� de cliquer sur une surface qui ne contient pas de bonton.)
*/