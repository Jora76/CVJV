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

//-----------------------------------------------------------------------------------------------------

	auto finTableau = std::remove_if(std::begin(elements), std::end(elements), ElementInterface::aSupprimer);
	elements.erase(finTableau, std::end(elements));
	for (auto& element : aAjouter)
	{
		elements.push_back(std::move(element));
	}
	aAjouter.clear();

//-----------------------------------------------------------------------------------------------------

	auto finTableauBoutons = std::remove_if(std::begin(boutons), std::end(boutons), Bouton::aSupprimer);
	boutons.erase(finTableauBoutons, std::end(boutons));
	for (auto& bouton : boutonAAjouter)
	{
		boutons.push_back(std::move(bouton));
	}
	boutonAAjouter.clear();
}

/*Utile pour :
*	- gestion collision curseur -> (elements -> tous && boutons -> panneaux)
*/

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

/*Utile pour :
*	- reactions clics des boutons (curseur, panneaux, boutons, boutons grille)
*/

void Interface::gererSouris(sf::Event& event, sf::RenderWindow& window)
{
	if (sf::Event::MouseMoved)
	{
		for (auto& bouton : boutons)
		{
			if (bouton->getType() == TypeElement::BOUTON_GRILLE && bouton->sourisEstDessus(event, window) == true)
			{
				positionBouton = bouton->getPos();
			}
			else if(bouton->getType() != TypeElement::BOUTON_GRILLE && bouton->sourisEstDessus(event, window) == true)
			{
				positionBouton = { 0.f, 0.f };
				//bouton->sourisEstDessus(event, window);
			}
		}
	}
}

 /*Utile pour :
 *	- déplacement curseur
 *	- apparition/disparition checkpoints
 */
void Interface::actualiser() 
{
	for (auto i{ 0u }; i < boutons.size(); ++i)
	{
		boutons[i]->actualiser();
	}
	for (auto i{ 0u }; i < elements.size(); ++i)
	{
		elements[i]->actualiser();
	}
}

/*Utile pour :
*	- parcourir elements et regarder s'il y a encore des checkpoints avec type = CHECKPOINT
*  Si il en reste, retourne false et remet les checkpoints et le curseur à leur position initiale
*  si il n'y en a plus retourne true et appelle Interface::vider()
*  Cette méthode est appelée lors de la collision entre Curseur et Arrivée.
*/

bool Interface::verifierCheckPoints()
{
	for (size_t i{ 0 }; i < elements.size(); ++i)
	{
		if (elements[i]->getType() != TypeElement::CHECKPOINT && i == elements.size() - 1)
		{
			return true;
		}
		else if (elements[i]->getType() == TypeElement::CHECKPOINT)
			return false;
	}
}

void Interface::reinitialiserGrille()
{
	for (auto& element : elements)
	{
		if (element->getType() == TypeElement::CHECKPOINT_RECUPERE)
			element->setType(TypeElement::CHECKPOINT);
	}
}

void Interface::viderGrille() 
{
	for (auto& bouton : boutons)
	{
		if (bouton->getType() == TypeElement::PANNEAU || bouton->getType() == TypeElement::TP)
		{
			bouton->supprimerPanneau();
		}
	}
	reinitialiserCompteurs();
}

bool Interface::dragAutre()
{
	for (size_t i{ 0 }; i < boutons.size(); ++i)
	{
		if (boutons[i]->getType() == TypeElement::PANNEAU_DRAG)
		{
			return true;
		}
		else if (boutons[i]->getType() != TypeElement::PANNEAU_DRAG && i == boutons.size() - 1)
		{
			return false;
		} 
	}
}

void Interface::vider()
{
	aVider = true;
	continuer = true;
}

size_t Interface::emplacementTypePanneau(int typePanneau)
{
	switch (typePanneau)
	{
	case 0:
		return 0;
		break;
	case 180:
		return 1;
		break;
	case 270:
		return 2;
		break;
	case 90:
		return 3;
		break;
	case -1:
		return 4;
		break;
	default:
		return 3;
		break;
	}
}

void Interface::setComptPanneaux(size_t i, unsigned short int compt)
{
	compteursPanneaux[i] = compt;
	compteursPanneauxInit[i] = compt;
}

void Interface::actualiserComptPanneau(unsigned short int terme, int typePanneau)
{
	compteursPanneaux[emplacementTypePanneau(typePanneau)] += terme;
	for (auto& compteur : compteursPanneaux)
		std::cout << "maj compt : " << compteur << std::endl;
	std::cout << std::endl;
}

bool Interface::panneauDispo(float typePanneau)
{
	return compteursPanneaux[emplacementTypePanneau(typePanneau)] != 0;
}

void Interface::reinitialiserCompteurs()
{
	for (auto i = 0; i < compteursPanneaux.size(); ++i)
	{
		compteursPanneaux[i] = compteursPanneauxInit[i];
	}
}

/*
	Regler répétition de code dans cette classe, c'est vraiment le bordel là.
*/