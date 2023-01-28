#include "Bouton.h"

bool Bouton::valider = false;

Bouton::Bouton(Coordonnees const& position_ptr, std::string_view chemin) : ElementInterface {chemin}
{
	type = TypeElement::AUTRE;
}

bool Bouton::sourisEstDessus(sf::Event& event, sf::RenderWindow& window, sf::View& view)
{
	//sf::Vector2f ratioFenetreView = { window.getSize().x / view.getSize().x, window.getSize().y / view.getSize().y };
	//float ratioFenetre = window.getSize().x / window.getSize().y;
	//sf::Vector2f ratioView = { float(sf::VideoMode::getDesktopMode().width / (sf::VideoMode::getDesktopMode().width / window.getSize().x)), float(sf::VideoMode::getDesktopMode().height / (sf::VideoMode::getDesktopMode().height / window.getSize().y)) };
	////sf::Vector2f test = { window.getSize().x / (window.getSize().x / 1.5f), window.getSize().y / (window.getSize().y / 1.5f) };
	//sf::Vector2f ratio = { float(window.getSize().x / (sf::VideoMode::getDesktopMode().width * 1.5f)), float(window.getSize().y / (sf::VideoMode::getDesktopMode().height * 1.5f))};
	////sf::Vector2f ratio = { float(window.getSize().x / (window.getSize().x / ratioFenetreView.x ) / ratioFenetre * ratioView.x), float(window.getSize().y / (window.getSize().y / ratioFenetreView.y) / ratioFenetre * ratioView.y) };

	//float sourisX = static_cast <float>(sf::Mouse::getPosition(window).x) / ratio.x;
	//float sourisY = static_cast <float>(sf::Mouse::getPosition(window).y) / ratio.y;

	sf::Vector2i posSouris = sf::Mouse::getPosition(window);
	sf::Vector2f sourisGlobalPos = window.mapPixelToCoords(posSouris, view);

	float btnxPosWidht = sprite.getPosition().x + sprite.getGlobalBounds().width / 2;
	float btnyPosHeight = sprite.getPosition().y + sprite.getGlobalBounds().height / 2;

	float btnxPosReelle = sprite.getPosition().x - sprite.getGlobalBounds().width / 2;
	float btnyPosReelle = sprite.getPosition().y - sprite.getGlobalBounds().height / 2;

	//std::cout << "Pos reelle : " << sf::Mouse::getPosition(window).x << ", " << sf::Mouse::getPosition(window).y << std::endl;
	std::cout << "Fenetre : " << window.getSize().x << ", " << window.getSize().y << std::endl;

	if ((sourisGlobalPos.x < btnxPosWidht && sourisGlobalPos.x > btnxPosReelle && sourisGlobalPos.y < btnyPosHeight && sourisGlobalPos.y > btnyPosReelle) || type == TypeElement::PANNEAU_DRAG)
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
	{
		reagirClic(event);
	}
}	

void Bouton::supprimerPanneau()
{
	supprimer = true;
}


/*----------------------------------------------------------------------------------------

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		reagirClic();
		

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