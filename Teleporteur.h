#pragma once
#include "Panneau.h"
class Teleporteur :
    public Panneau
{
public:
    explicit Teleporteur(const Coordonnees& position_ptr, Interface& interface_ptr);
private:
    virtual void genererPanneau() override;
    virtual float getTypePanneau() override;
};

