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
	texte.setFont(police);
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

void GestionnaireTexte::actualiserCompteurs(size_t i, std::string& contenu)
{
	textesCompteurs[i].setString(contenu);
}

void GestionnaireTexte::ajouter(std::string& contenuTxt, Coordonnees& position)
{
	sf::Text texte;
	texte.setString(contenuTxt);
	setStyle(texte);
	texte.setPosition(position.getX(), position.getY());
	textesCompteurs.push_back(texte);
	
	/*
	for (auto& texte : textesInstance)
	{
		afficher(texte);
	}*/
}

void GestionnaireTexte::afficher(/*sf::Text& texte*/)
{
	for (auto& texte : textesCompteurs)
	{
		window.draw(texte);
	}
}

void GestionnaireTexte::vider()
{
	textesCompteurs.clear();
}

//finir transfert police ou remettre comme avant.
//actualiserCompteurs finalement ce serait peut être mieux dans jeu comme ça
//gestionnaire texte s'occupe réellement que des textes et ça peut peut etre débloquer le truc avec ajouter
