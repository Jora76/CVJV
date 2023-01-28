#pragma once
#include "ElementInterface.h"
#include <iostream>

class Bouton :
    public ElementInterface
{
public:
    Bouton(Coordonnees const& position_ptr, std::string_view chemin);
    bool sourisEstDessus(sf::Event& event, sf::RenderWindow& window, sf::View& view);
    static inline bool aSupprimer(std::unique_ptr<Bouton>& bouton) { return bouton->supprimer; };
    inline bool getValider() { return valider; };
    inline Coordonnees getPos() { return position; };
    void supprimerPanneau();
protected:
    virtual void reagirClic(sf::Event& event) = 0;
    bool selection{ false };
    bool supprimer{ false };
    virtual void setCouleur(bool sourisDessus) = 0;
    virtual void testerClic(sf::Event& event, sf::RenderWindow& window, sf::View& view);
private:
};

