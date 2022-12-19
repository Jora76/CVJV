#pragma once
#include "ElementInterface.h"
#include <iostream>

class Bouton :
    public ElementInterface
{
public:
    Bouton(Coordonnees const& position_ptr, std::string_view chemin);
    void sourisEstDessus(sf::Event& event, sf::RenderWindow& window);
    static inline bool aSupprimer(std::unique_ptr<Bouton>& bouton) { return bouton->supprimer; };
    inline bool getValider() { return valider; };
    Coordonnees supprimerSiPanneau();
protected:
    virtual void reagirClic(sf::Event& event) = 0;
    bool selection{ false };
    bool supprimer{ false };
    static bool valider;
    sf::Clock dernierClic;
    virtual void setCouleur(bool sourisDessus) = 0;
    //sf::Event event{};
private:
    void testerClic(sf::Event& event);
};

