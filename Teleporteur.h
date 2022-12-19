#pragma once
#include "Bouton.h"
class Teleporteur :
    public Bouton
{
public:
    explicit Teleporteur(const Coordonnees& position_ptr);
    //void setNombrePanneaux();
private:
    virtual void reagirClic(sf::Event& event) override;
    virtual void reagirCollision(TypeElement typeAutre, float angle = 0) override;
    virtual void setCouleur(bool sourisDessus) override;
};

