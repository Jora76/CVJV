#include "GestionnaireTexte.h"

GestionnaireTexte::GestionnaireTexte(sf::RenderWindow& window_ptr) : window { window_ptr }
{
	police.loadFromMemory(data, data_length);
}

void GestionnaireTexte::setStyle(sf::Text& texte, int taille)
{
	texte.setFillColor(sf::Color::Green);
	texte.setCharacterSize(taille);
	texte.setFont(police);
}

//void GestionnaireTexte::defiler(sf::Text& texte)
//{
//	std::string string = texte.getString();
//	std::string str;
//	chrono.restart().asMilliseconds();
//	for (auto i = 0; i < string.size(); i)
//	{ 
//		sf::Time temps = sf::milliseconds(chrono.getElapsedTime().asMilliseconds());
//		if (temps >= test)
//		{
//			str += string[i];
//			texte.setString(str);
//			window.clear();
//			window.draw(texte);
//			window.display();
//			++i;
//			chrono.restart().asMilliseconds();
//		}
//	}
//
//	/*for (auto i = 0; i < string.size(); i)
//	{
//		str += string[i];
//		texte.setString(str);
//		window.clear();
//		window.draw(texte);
//		window.display();
//		++i;
//		std::this_thread::sleep_for(std::chrono::milliseconds(20));
//	}*/
//}

void GestionnaireTexte::actualiserCompteurs(size_t i, std::string& contenu)
{
	textesCompteurs[i].setString(contenu);
}

void GestionnaireTexte::ajouter(std::string& contenuTxt, const Coordonnees& position, int typeTexte, int taille)
{
	sf::Text texte;
	texte.setString(contenuTxt);
	setStyle(texte, taille);
	texte.setPosition(position.getX(), position.getY());

	switch (typeTexte)
	{
	case TypeTexte::COMPTEUR:
		textesCompteurs.push_back(texte);
		break;
	case TypeTexte::INSTRUCTION:
		textesInstruction.push_back(texte);
		break;
	case TypeTexte::AUTRE:
		textesAutres.push_back(texte);
		break;
	case TypeTexte::DIALOGUE:
		dialogueActuel = texte;
		break;
	}
}

void GestionnaireTexte::afficher(sf::Text& texte)
{
	window.draw(texte);
}

void GestionnaireTexte::afficher()
{
	window.draw(dialogueActuel);

	for (auto& texte : textesCompteurs)
	{
		window.draw(texte);
	}
	for (auto& texte : textesInstruction)
	{
		window.draw(texte);
	}
	for (auto& texte : textesAutres)
	{
		window.draw(texte);
	}
}

void GestionnaireTexte::vider()
{
	textesCompteurs.clear();
	textesInstruction.clear();
	textesAutres.clear();
	dialogueActuel.setString(" ");
}

