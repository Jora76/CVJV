#include "GestionnaireRessources.h"


std::unordered_map<std::string_view, sf::Texture> GestionnaireRessources::ressources{};//création tableau de pairs pour gestion dynamique des textures des sprites en mémoire

sf::Texture const& GestionnaireRessources::getRessource(std::string_view const& chemin)
{
	auto resultat = ressources.find(chemin);
	if (resultat == std::end(ressources))
	{
		if (!ressources[chemin].loadFromFile(chemin.data()))
		{
			std::cerr << "Erreur : impossible de charger la texture" << chemin << std::endl;
		}
		ressources[chemin].setSmooth(true);
		return ressources[chemin];
	}
	return resultat->second;
}

//Le gestionnaire de ressources prend en paramètre un string_view pointant vers la texture à charger
//Il teste si la texture est déja en mémoire. Si oui, il pointe vers la texture correspondante. Si non, il la charge et crée une nouvelle pair pour celle-ci.