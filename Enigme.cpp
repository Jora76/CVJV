#include "Enigme.h"

Enigme::Enigme(Interface& interface_ptr) : interface {interface_ptr}
{
}

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
		int test;
		while (enigme >> test)
		{
			grille.push_back(test);
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
			break;
		//case qtePanneaux:
		case comp:
			++grille_Iter;
			for (grille_Iter; grille_Iter < grille.size(); ++grille_Iter)
			{
				switch (grille[grille_Iter])
				{
				case boutonGrille:
					if(grille[grille_Iter + 1] == fin)
						Coordonnees::initialiserGrille(position.getX(), position.getY());
					interface.ajouterBouton(std::make_unique<BoutonGrille>(interface, position));
					break;
				case checkPoint:
					interface.ajouter(std::make_unique<CheckPoint>(interface, position));
					break;
				case arrivee:
					interface.ajouter(std::make_unique<Arrivee>(interface, position));
					break;
				case obstacle:
					//interface.ajouter(std::make_unique<Obstacle>(interface, position));
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
}

/*void Enigme::lireFichier(std::string_view const& chemin)
	Ouvre le .txt contenant le contenu de l'�nigme correspondant et le stocke dans un tableau vector.
	Le fichier .txt contient toutes les infos que le g�n�rateur doit avoir pour placer correctement les obets dans la grille d'�nigme.

  void Enigme::generer(std::string_view const& chemin)
	Parcourt une � une chaque case du tableau remplit dans lireFichier, calibre les coordonnees de la premi�re case de la grille d'enigme
	ainsi que celles de d�part de Curseur et g�n�re l'objet correspondant au code qui
	lui a �t� attribu� dans l'�num�ration se trouvant dans Enigme.h tout en 
	incr�mentant les coordonnees de position gr�ce � l'offset initialis� dans le header d'Enigme
	
	Etant limit� par la SFML, j'ai d� mettre le curseur en dernier dans l'ordre d'appel afin que le 
	Z-index soit respect�. Dans le cas contraire, Curseur serait pass� en dessous des objets appel�s apr�s lui.*/