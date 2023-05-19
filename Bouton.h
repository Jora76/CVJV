#pragma once
#include "ElementInterface.h"
#include "GestionnaireRessources.h"
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
    bool tailleMax{ false };
    bool supprimer{ false };
    virtual void reagirSouris(bool sourisDessus);
    virtual void testerClic(sf::Event& event, sf::RenderWindow& window, sf::View& view);
    static constexpr float COEF_TAILLE = 0.8f;
    /*sf::Sound clic;
    sf::Sound dessus;*/
private:
};

