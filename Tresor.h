#ifndef TRESOR_H
#define TRESOR_H
#include <iostream>
using namespace std;
#include "Case.h"
#include "Aventurier.h"

class Tresor : public Case {

    /* Classe permettant de définir le trésor qu'un joueur peut avoir

    Paramètres : 
        valeur : int (private)
        Permet de définir une valeur à une récompense perçue par un joueur (exemple : +10 pv))

    Méthode : 
        afficher() : char
        Permet d'afficher la chaîne de caractère représentant le trésor dans le labyrinthe (par +)

        appliqueEffet() : void
        Permet d'appliquer l'effet du trésor sur le joueur directement
    */

    private : 
        int valeur;

    public : 
        //constructeur
        Tresor(int a = 10){
            type = TypeCase::Tresor;
            valeur = a;
        }

        char afficher()const override{
            char b = '+';
            return b;
        }

        virtual void appliqueEffet(Aventurier& aventurier){ //permettant d'appliquer tous les effets du trésor au joueur directement
            aventurier.setPV(min(aventurier.getPV() + valeur, 100));;
            aventurier.setInventaire(aventurier.getInventaire() + 1);
            std::cout << "Un tresor a ete trouve , vous gagnez " << valeur << "pv et un tresor" << std::endl;
        }
};

#endif