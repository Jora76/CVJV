#pragma once
#include "Interface.h"
#include "ElementInterface.h"
#include "BoutonGrille.h"
class Panneau :
    public Bouton
{
public:
    explicit Panneau(const Coordonnees& position_ptr, const float angle_ptr, Interface& interface_ptr);
    //inline bool getDrag() { return drag; };
   // void setNombrePanneaux();
private:
    virtual void reagirClic(sf::Event& event) override;
    virtual void reagirCollision(TypeElement typeAutre, float angle = 0) override;
    virtual void setCouleur(bool sourisDessus) override;
    virtual void testerClic(sf::Event& event, sf::RenderWindow& window) override;

    float angle;
    Coordonnees posDrop;
    Coordonnees posInit;
    Interface& interface;
};

