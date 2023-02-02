#include "Enigme.h"

Enigme::Enigme(Interface& interface_ptr) : interface {interface_ptr}
{}

void Enigme::lireFichier(std::string_view const& chemin)
{
	std::ifstream enigme(chemin.data());

	if (!enigme)
	{ 
		std::cout << "Le fichier n'a pas pu etre charge." << std::endl;
		exit (EXIT_FAILURE);
	}
	else
	{
		int donnee;
		while (enigme >> donnee)
		{
			grille.push_back(donnee);
		}
	}
}

void Enigme::generer(std::string_view const& chemin)
{
	lireFichier(chemin);
	size_t grille_Iter = 0;
	for (auto& ligne : grille)
	{
		switch (ligne)
		{
		case coordonneesPremiereCase:
			position.setX(grille[1]);
			position.setY(grille[2]);
			Coordonnees::initialiserGrille(position.getX(), position.getY());
			break;
			
		case comp:
			++grille_Iter;
			for (grille_Iter; grille_Iter < grille.size(); ++grille_Iter)
			{
				switch (grille[grille_Iter])
				{
				case boutonGrille:
					if(grille[grille_Iter + 1] == fin)
						position.setFinGrilleY(position.getY());
					interface.ajouterBouton(std::make_unique<BoutonGrille>(interface, position));
					break;
				case checkPoint:
					interface.ajouter(std::make_unique<CheckPoint>(interface, position));
					break;
				case arrivee:
					interface.ajouter(std::make_unique<Arrivee>(interface, position));
					break;
				case obstacle:
					interface.ajouter(std::make_unique<Obstacle>(interface, position));
					break;
				case depart:
					break;
				case faille:
					interface.ajouter(std::make_unique<Faille>(interface, position));
					break;
				case interrupteur:
					interface.ajouter(std::make_unique<Interrupteur>(interface, position));
					break;
				case ligneSuivante:
					position.setFinGrilleX(position.getX());
					position.setX(grille[1] - OFFSET);
					position.setY(OFFSET);
					break;
				}
				position.setX(OFFSET);
			}
		}
		++grille_Iter;
	}
	
	position.setX(grille[3]);
	position.setY(grille[4]);
	interface.ajouterBouton(std::make_unique<Curseur>(interface, position));

	// 152 296 -> 373 -> 451
	auto posPanneauY = 316;
	auto angle = 0.f;
	position.setX(172); //ne pas oublier de mettre ça dans une variable const 
	position.setY(posPanneauY); // pas celui la par contre
	for (auto i = 0; i < 4; ++i)
	{
		interface.ajouterBouton(std::make_unique<PanneauDirection>(position, angle, interface));
		if (i == 0 || i == 2)
			angle += 180;
		else
		{
			angle += 90;
		}
		posPanneauY += 77;
		position.setY(posPanneauY);
	}
	interface.ajouterBouton(std::make_unique<Teleporteur>(position, interface));

// initialisation des compteurs de panneaux

	for (auto i = 0; i < 5; ++i)
	{
		interface.setComptPanneaux(i, grille[i + 5]);
	}

	grille.clear();
}

/*void Enigme::lireFichier(std::string_view const& chemin)
	Ouvre le .txt contenant le contenu de l'énigme correspondant et le stocke dans un tableau vector.
	Le fichier .txt contient toutes les infos que le générateur doit avoir pour placer correctement les obets dans la grille d'énigme.

  void Enigme::generer(std::string_view const& chemin)
	Parcourt une à une chaque case du tableau remplit dans lireFichier, calibre les coordonnees de la première case de la grille d'enigme
	ainsi que celles de départ de Curseur et génère l'objet correspondant au code qui
	lui a été attribué dans l'énumération se trouvant dans Enigme.h tout en 
	incrémentant les coordonnees de position grâce à l'offset initialisé dans le header d'Enigme
	
	Etant limité par la SFML, j'ai dû mettre le curseur en dernier dans l'ordre d'appel afin que le 
	Z-index soit respecté. Dans le cas contraire, Curseur serait passé en dessous des objets appelés après lui. (reglé)*/