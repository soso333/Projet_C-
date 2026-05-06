#ifndef MUR_H
#define MUR_H
#include "Case.h"

class Mur : public Case {

    /* Classe permettant de définir un mur

    Méthode : 
        afficher() : char
        Permet d'afficher la chaîne de caractère représentant le mur dans le labyrinthe (par #)

        appliqueEffet() : void
        Rien ne se passe, mais il faut quand même définir cette méthode pour que le code compile, vu que c'est une méthode virtuelle pure dans la classe Case
    */

    public:
        Mur() {
            type = TypeCase::Mur;
        }
        
        char afficher(){
            char a = '#';
            return a;
        }

        virtual void appliqueEffet(Aventurier& aventurier){ 
        }
};

#endif