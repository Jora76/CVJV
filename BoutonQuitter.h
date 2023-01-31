#pragma once
#include "Bouton.h"
class BoutonQuitter :
    public Bouton
{
public:
    BoutonQuitter(sf::RenderWindow& window_ptr, Coordonnees& position_ptr);
private:
    virtual void reagirClic(sf::Event& event) override;
    virtual void reagirSouris(bool sourisDessus) override;
    sf::RenderWindow& window;
};

