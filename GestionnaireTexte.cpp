#include "GestionnaireTexte.h"

//GestionnaireTexte::GestionnaireTexte(std::string& contenu_ptr, Coordonnees& position_ptr) : contenu{ contenu_ptr }, position { position_ptr }
//{
//	police.loadFromMemory(data, data_length);
//}

GestionnaireTexte::GestionnaireTexte(sf::RenderWindow& window_ptr) : window{window_ptr}
{
	police.loadFromMemory(data, data_length);
}

void GestionnaireTexte::setStyle(sf::Text& texte)
{
	texte.setFillColor(sf::Color::Green);
	texte.setCharacterSize(20);
	//defiler(texte);
}

void GestionnaireTexte::defiler(sf::Text& texte)
{
	sf::String string = texte.getString();
	while (caractere < string.getSize())
	{
		if (chrono.getElapsedTime().asMilliseconds() > 50)
		{
			chrono.restart();
			++caractere;
			texte.setString(string.substring(0, caractere));
		}
	}
}
//
//void GestionnaireTexte::actualiserCompteurs(std::array <unsigned short int, 4>& compteurs)
//{
//	float x = 192.f;
//	float y = 376.f;
//	for (auto i = 0; i < compteurs.size(); ++i)
//	{
//		sf::Text compteur(("x0" + std::to_string(compteurs[i])), police);
//		compteur.setString("x0" + std::to_string(compteurs[i]));
//		compteur.setPosition(x, y);
//		setStyle(compteur);
//		afficher(compteur);
//		y += 77.f;
//	}
//}
//
//void GestionnaireTexte::ajouter(std::string& contenuTxt, sf::RenderWindow& window)
//{
//	sf::Text texte;
//	texte.setString(contenuTxt);
//	textesInstance.push_back(texte);
//}

void GestionnaireTexte::afficher(sf::Text& texte)
{
	window.draw(texte);
}

//finir transfert police ou remettre comme avant.
//actualiserCompteurs finalement ce serait peut être mieux dans jeu comme ça
//gestionnaire texte s'occupe réellement que des textes et ça peut peut etre débloquer le truc avec ajouter
