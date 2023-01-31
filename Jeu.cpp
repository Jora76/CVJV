#include "Jeu.h"

Jeu::Jeu(Interface& interface_ptr, Enigme& enigme_ptr, GestionnaireTexte& texte_ptr) : interface{ interface_ptr }, enigme{enigme_ptr}, texte{texte_ptr}
{
}


void Jeu::demarrer() //Doit etre appelée qu'une seule fois. 
{
    choisirEnigme();
    interface.ajouter(std::make_unique<Fenetre>(cheminFenetre));
    interface.ajouterBouton(std::make_unique<BoutonValider>(interface));
    interface.ajouterBouton(std::make_unique<BoutonSupprimer>(interface));
    enigme.generer(cheminEnigme);
    instanceActuelle = Instance::MENU;
    initTexte();
}

void Jeu::choisirEnigme()
{
    if (compteur < 3) {
       // compteur = 2;
        ++compteur;
    }
    else
        terminer();
    cheminEnigme = "ressources/niveaux/enigme" + std::to_string(compteur) + ".txt";
    cheminFenetre = "ressources/sprites/Fenetre_" + std::to_string(compteur) + ".png";
}

void Jeu::actualiserTexte() //gerer tout court, pas juste texte
{
    switch (instanceActuelle)
    {
    case Instance::ENIGME:
        interface.mettre_A_Jour_Txt_ComptPanneau(texte);
        texte.afficher();
        break;
    }
}


void Jeu::continuer()
{
    texte.vider();
    demarrer();
    interface.setContinuer();
}

void Jeu::actualiser()
{
    if (interface.getContinuer() == true)
    {
        continuer();
    }
    actualiserTexte();
}

void Jeu::initTexte()
{
    switch (instanceActuelle)
    {
    case Instance::ENIGME:
        texte.ajouter(texteConsigne, posTxtConsigne, 1);
        texte.ajouter(texteObjectif, posTxtObjectif, 1);
        interface.ajouterCompteurs(texte);
        break;
    case Instance::MENU:
        texte.ajouter(texteMenu, posTxtMenu, 3);
        break;
    }
}

void Jeu::terminer()
{
    interface.vider();
}
