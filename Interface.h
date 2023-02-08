#pragma once
#include <vector>
#include <iostream>
#include <array>

#include "ElementInterface.h"
#include "Bouton.h"
#include "GestionnaireTexte.h"

class Interface
{
public:
	Interface();
	void ajouter(std::unique_ptr<ElementInterface> element);
	void ajouterBouton(std::unique_ptr<Bouton> bouton);
	void positionner();
	void afficher(sf::RenderWindow& window) const;
	void gererCollisions(ElementInterface* curseur);
	void gererSouris(sf::Event& event, sf::RenderWindow& window, sf::View& view);
	void nettoyer();
	void actualiser();
	bool verifierCheckPoints();
	void vider();
	void reinitialiserGrille();
	void viderGrille();
	inline Coordonnees getPosBtn() { return positionBouton; };
	bool dragAutre();
	inline bool getContinuer() { return continuer; };
	inline void setContinuer(bool booleen) { continuer = booleen; };

	void setComptPanneaux(size_t i, unsigned short int compt);
	void actualiserComptPanneau(unsigned short int terme, int typePanneau);
	bool panneauDispo(float typePanneau);
	void ajouterCompteurs(GestionnaireTexte& compteur);
	void mettre_A_Jour_Txt_ComptPanneau(GestionnaireTexte& texte);
	void defilerTxt(GestionnaireTexte& txt, sf::Text& texte, const Coordonnees& position, sf::RenderWindow& window);

private:
	std::vector<std::unique_ptr<ElementInterface>> elements{};
	std::vector<std::unique_ptr<ElementInterface>> aAjouter{};
	std::vector<std::unique_ptr<Bouton>> boutonAAjouter{};
	std::vector<std::unique_ptr<Bouton>> boutons{};
	
	bool aVider = false;
	bool continuer{ false }; 
	Coordonnees positionBouton;
	std::array <unsigned short int, 5> compteursPanneaux;
	std::array <unsigned short int, 5> compteursPanneauxInit;
	size_t emplacementTypePanneau(int typePanneau);

	void reinitialiserCompteurs();

	sf::Clock chrono; 
	sf::Time tempsMax;
};