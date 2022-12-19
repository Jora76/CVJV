#include "Interface.h"

Interface::Interface()
{

}

void Interface::ajouter(std::unique_ptr<ElementInterface> element) //ajoute les éléments fraichement chargés dans un vector temporaire pour éviter une erreur de copie des pointeurs uniques dans la mémoire
{
	aAjouter.push_back(std::move(element));
}

void Interface::ajouterBouton(std::unique_ptr<Bouton> bouton)
{
	boutonAAjouter.push_back(std::move(bouton));
}

void Interface::afficher(sf::RenderWindow& window) const //affiche les éléments dans la fenetre lorsque la méthode est appelée dans le main
{
	for (auto& element : elements)
	{
		element->afficher(window);
	}
	for (auto& bouton : boutons)
	{
		bouton->afficher(window);
	}
}


void Interface::positionner() //place les élements dans l'interface
{
	for (auto i{ 0u }; i < elements.size(); ++i)
	{
		elements[i]->positionner();
	}
	for (auto i{ 0u }; i < boutons.size(); ++i)
	{
		boutons[i]->positionner();
	}
	
}

void Interface::nettoyer() //ajoute les éléments du vector temporaire au vector principal et vide le vector temporaire
{
	if (aVider)
	{
		elements.clear();
		boutons.clear();
		aVider = false;
	}
	auto finTableau = std::remove_if(std::begin(elements), std::end(elements), ElementInterface::aSupprimer);
	elements.erase(finTableau, std::end(elements));
	for (auto& element : aAjouter)
	{
		elements.push_back(std::move(element));
	}
	aAjouter.clear();

	auto finTableauBoutons = std::remove_if(std::begin(boutons), std::end(boutons), Bouton::aSupprimer);
	boutons.erase(finTableauBoutons, std::end(boutons));
	for (auto& bouton : boutonAAjouter)
	{
		boutons.push_back(std::move(bouton));
	}
	boutonAAjouter.clear();
}

void Interface::gererCollisions(ElementInterface* curseur)
{
	for (auto& element : elements)
	{
		curseur->testerCollision(*element);
	}
	for (auto& bouton : boutons)
	{
		curseur->testerCollision(*bouton);
	}
}

void Interface::gererSouris(sf::Event& event, sf::RenderWindow& window)
{
	if (sf::Event::MouseMoved)
	{
		for (auto& bouton : boutons)
		{
			bouton->sourisEstDessus(event, window);
		}
	}
}/*

 Utile pour déplacement curseur mais je sais pas pourquoi j'ai mis ce corps de fonction juste pour ça 

void Interface::actualiser()
{
	for (auto i{ 0u }; i < boutons.size(); ++i)
	{
		boutons[i]->actualiser();
	}
}*/

bool Interface::verifierCheckPoints()
{
	for (size_t i{ 0 }; i < elements.size(); ++i)
	{
		if (elements[i]->estCheckpoint() == false && i == elements.size() - 1)
		{
			return true;
		}
		else if (elements[i]->estCheckpoint() == true)
			return false;
	}
}

void Interface::vider()
{
	aVider = true;
}

/*
Pour régler répétition de code pour les types Bouton et ElementInterface pourquoi pas
leur créer une classe mere commune qui va gérer ...
Avec typeid()
faire fonction qui prend en parametre un bouton pour pouvoir utiliser méthodes de la classe bouton
et pour savoir si l'objet testé doit utiliser cette fonction on utilise typeid()
*/