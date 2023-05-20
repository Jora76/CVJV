#pragma once

#include <SFML/Graphics.hpp>
#include <string_view>
#include <unordered_map>
#include <iostream>
#include <SFML/Audio.hpp>

template <typename T>
class GestionnaireRessources
{
	public:
		GestionnaireRessources() = delete; //évite toute création d'objet de type Gestionnaireressources
		static T const& getRessource(std::string_view const& chemin) // const pour ne pas modifier texture chargée
		{
			auto resultat = ressources.find(chemin);
			if (resultat == std::end(ressources))
			{
				if (!ressources[chemin].loadFromFile(chemin.data()))
				{
					std::cerr << "Erreur : impossible de charger la ressource" << chemin << std::endl;
				}
				//ressources[chemin].setSmooth(true);
				return ressources[chemin];
			}
			return resultat->second;
		}

	private:
		static std::unordered_map<std::string_view, T> ressources;
};

