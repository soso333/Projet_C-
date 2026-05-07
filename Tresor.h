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
        Permet de définir une valeur à une récompense perçue par un joueur (exemple : +10 trésors)

    Méthode : 
        init : void 
        Permet d'initiliaser la valeur du trésor

        afficher() : char
        Permet d'afficher la chaîne de caractère représentant le trésor dans le labyrinthe (par +)

        appliqueEffet() : void
        Permet d'appliquer l'effet du trésor sur le joueur directement
    */

    private : 
        int valeur;

    public : 
        Tresor(){
            type = TypeCase::Tresor;
            init();
        };

        void init(int a = 10){
            valeur = a;
        }

        char afficher()const override{
            char b = '+';
            return b;
        }

        virtual void appliqueEffet(Aventurier& aventurier){ //permettant d'appliquer tous les effets du trésor au joueur directement
            aventurier.setPV(aventurier.getPV() + valeur);
            aventurier.setInventaire(aventurier.getInventaire() + 1);
            std::cout << "Un trésor a été trouvé , vous gagnez " << valeur << "pv et un trésor" << std::endl;
        }

      

};

#endif