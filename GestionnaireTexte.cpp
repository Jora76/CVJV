#include "GestionnaireTexte.h"

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

void GestionnaireTexte::ajouter(std::string& contenuTxt, Coordonnees& position, int typeTexte)
{
	sf::Text texte;
	texte.setString(contenuTxt);
	setStyle(texte);
	texte.setPosition(position.getX(), position.getY());

	switch (typeTexte)
	{
	case TypeTexte::COMPTEUR:
		textesCompteurs.push_back(texte);
		break;
	case TypeTexte::INSTRUCTION :
		textesInstruction.push_back(texte);
		break;
	}
}

void GestionnaireTexte::afficher()
{
	for (auto& texte : textesCompteurs)
	{
		window.draw(texte);
	}
	for (auto& texte : textesInstruction)
	{
		window.draw(texte);
	}
}

void GestionnaireTexte::vider()
{
	textesCompteurs.clear();
	textesInstruction.clear();
}

