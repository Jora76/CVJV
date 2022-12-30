#pragma once
#include <vector>
#include <iostream>
#include "ElementInterface.h"
#include "Bouton.h"
//#include "Curseur.h" //modif

class Interface
{
public:
	Interface();
	void ajouter(std::unique_ptr<ElementInterface> element);
	void ajouterBouton(std::unique_ptr<Bouton> bouton);
	void positionner();
	void afficher(sf::RenderWindow& window) const;
	void gererCollisions(ElementInterface* curseur);
	void gererSouris(sf::Event& event, sf::RenderWindow& window);
	void nettoyer();
	void actualiser();
	bool verifierCheckPoints();
	void vider();
	void reinitialiserGrille();
	void viderGrille();
	inline Coordonnees getPosBtn() { return positionBouton; };
	bool dragAutre();
	inline bool getContinuer() { return continuer; };
	inline void setContinuer() { continuer = false; };

private:
	std::vector<std::unique_ptr<ElementInterface>> elements{};
	std::vector<std::unique_ptr<ElementInterface>> aAjouter{};
	std::vector<std::unique_ptr<Bouton>> boutonAAjouter{};
	std::vector<std::unique_ptr<Bouton>> boutons{};
	
	bool aVider = false;
	bool continuer{ false }; 
	Coordonnees positionBouton;
};