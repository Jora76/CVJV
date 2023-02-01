#include "Bouton.h"

bool ElementInterface::valider = false;

Bouton::Bouton(Coordonnees const& position_ptr, std::string_view chemin) : ElementInterface {chemin}
{
	type = TypeElement::AUTRE;
}

bool Bouton::sourisEstDessus(sf::Event& event, sf::RenderWindow& window, sf::View& view)
{
	sf::Vector2i posSouris = sf::Mouse::getPosition(window);
	sf::Vector2f sourisGlobalPos = window.mapPixelToCoords(posSouris, view);

	float btnxPosWidht = sprite.getPosition().x + sprite.getGlobalBounds().width / 2;
	float btnyPosHeight = sprite.getPosition().y + sprite.getGlobalBounds().height / 2;

	float btnxPosReelle = sprite.getPosition().x - sprite.getGlobalBounds().width / 2;
	float btnyPosReelle = sprite.getPosition().y - sprite.getGlobalBounds().height / 2;


	if ((sourisGlobalPos.x < btnxPosWidht && sourisGlobalPos.x > btnxPosReelle && sourisGlobalPos.y < btnyPosHeight && sourisGlobalPos.y > btnyPosReelle) || type == TypeElement::PANNEAU_DRAG)
	{
		reagirSouris(true);
		testerClic(event, window, view);
		return true;
	}
	else
	{
		reagirSouris(false);
		return false;
	}
}

void Bouton::testerClic(sf::Event& event, sf::RenderWindow& window, sf::View& view)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		reagirClic(event);
	}
}	

void Bouton::supprimerPanneau()
{
	supprimer = true;
}

void Bouton::reagirSouris(bool sourisDessus)
{
	sf::Vector2f tailleBtn = sprite.getScale();
	if (sourisDessus == true)
	{
		if (!tailleMax)
		{
			tailleMax = true;
			sprite.setScale(tailleBtn.x / COEF_TAILLE, tailleBtn.y / COEF_TAILLE);
		}
	}
	else
	{
		if (tailleMax)
		{
			tailleMax = false;
			sprite.setScale(tailleBtn.x * COEF_TAILLE, tailleBtn.y * COEF_TAILLE);
		}
	}
}

/*----------------------------------------------------------------------------------------

	 à corriger : (réglé)
		- faire toutes les réactions au clic

		- voir pour les couleurs de bouton (pour boutons incluant des dessins à l'intérieur
		pourquoi pas mettre la texture du bouton juste en fond et charger une autre texture incluant
		le dessin à l'intérieur)
		Exemple : pour BoutonValider, 
		juste mettre le fond du bouton et include la petite virgule dans un autre sprite)

		- Dès qu'il y a une sélection, elle ne s'annule plus 
		Le fait de recliquer pour déselectionner ne fonctionne pas 
		(réglé à moitié : Obligé de cliquer sur une surface qui ne contient pas de bonton.)
*/