#pragma once
#include "Panneau.h"
class Teleporteur :
    public Panneau
{
public:
    explicit Teleporteur(const Coordonnees& position_ptr, Interface& interface_ptr);
    //void setNombrePanneaux();
private:
    //virtual void reagirCollision(TypeElement typeAutre, float angle = 0) override;
    //virtual void setCouleur(bool sourisDessus) override;
    virtual void genererPanneau() override;
};

