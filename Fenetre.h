#pragma once
#include "ElementInterface.h"
class Fenetre :
    public ElementInterface
{
public:
    Fenetre(std::string_view const& chemin);
    Fenetre(std::string_view const& chemin, const Coordonnees& position_ptr);/*
private:
    Coordonnees& position;*/
};

