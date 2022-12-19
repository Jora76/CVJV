#include "Panneau.h"

Panneau::Panneau(const Coordonnees& position_ptr, const float angle_ptr) : Bouton{position, "ressources/sprites/Panneau_droite.png" }
{
	type = TypeElement::PANNEAU;
	position = position_ptr;
	sprite.setRotation(angle_ptr);
	sprite.setScale(sprite.getScale().x, sprite.getScale().x);
}

void Panneau::reagirClic(sf::Event& event)
{}

void Panneau::reagirCollision(TypeElement typeAutre, float angle)
{
	if(typeAutre == TypeElement::CURSEUR)
		sprite.setColor(sf::Color::Color(0, 255, 0, 0));
}
void Panneau::setCouleur(bool sourisDessus)
{
	if (sourisDessus)
		sprite.setColor(sf::Color::Color(0, 255, 0, 255));
	else
		sprite.setColor(sf::Color::Color(22, 49, 32, 255));
}

/*
Bug collision Curseur -> panneaux :
	Description :
		Quand il y a plusieurs panneaux sur la grille && que le curseur touche l'un d'eux
		il va refaire le chacarron macarron. 
	Cause : 
		Vu que testerCollision s'execute en boucle, quand le curseur est en collision avec un des panneaux
		et que le curseur n'a aucun moyen de reconnaitre le panneau qu'il touche, quand le test de collision
		pour l'autre panneau s'execute, il se dit : "ah bah je touche un panneau ET je touche pas un panneau"
		Du coup il met l'attribut reactionDejaFaite en true et false en boucle. True quand il teste sa collision 
		avec le panneau qu'il est en train de toucher et false quand il teste sa collision avec l'autre.
	Possible solution : 
		Utiliser le nombre de panneaux renseigné dans les fichiers txt des enigmes , les stocker dans une variable 
		par nombre (ou dans un tableau) grâce à setNombrePanneaux() ainsi quand un panneau est appelé lui mettre en 
		paramètre un de ces nombres pour qu'il puisse etre identifiable. Genre le nombre c'est son ID.
*/