#pragma once
#include "ElementInterface.h"
class Fenetre :
    public ElementInterface
{
public:
    Fenetre(std::string_view const& chemin);
};

