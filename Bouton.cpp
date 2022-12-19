#include "Bouton.h"

bool Bouton::valider = false;

Bouton::Bouton(Coordonnees const& position_ptr, std::string_view chemin) : ElementInterface {chemin}
{
	type = TypeElement::AUTRE;
}

void Bouton::sourisEstDessus(sf::Event& event, sf::RenderWindow& window)
{
	float sourisX = static_cast <float>(sf::Mouse::getPosition(window).x);
	float sourisY = static_cast <float>(sf::Mouse::getPosition(window).y);
	Coordonnees positionSouris{ sourisX, sourisY };

	auto distance = position.calculerDistance(positionSouris);
	if (distance < sprite.getGlobalBounds().height / 2.4)
	{
		setCouleur(true);
		testerClic(event);
	}
	else
	{
		setCouleur(false);
	}
}

void Bouton::testerClic(sf::Event& event)
{
	if (event.type == sf::Event::MouseButtonReleased)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			reagirClic(event);
		}
	}

}	

Coordonnees Bouton::supprimerSiPanneau()
{
	if (type == TypeElement::PANNEAU || type == TypeElement::TP)
	{
		supprimer = true;
		return position;
	}
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