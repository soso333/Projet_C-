#ifndef PASSAGE_H
#define PASSAGE_H
#include "Case.h"

class Passage : public Case {

    /* Classe permettant de définir un mur

    Méthode : 
        afficher() : char
        Permet d'afficher la chaîne de caractère représentant le passage dans le labyrinthe (par  )

        appliqueEffet() : void
        RIen ne se passe, mais il faut quand même définir cette méthode pour que le code compile, vu que c'est une méthode virtuelle dans la classe Case
    */

    public:
        Passage(){
            type = TypeCase::Passage;
        }
        
        char afficher(){
            char a = ' ';
            return a;
        }

        virtual void appliqueEffet(Aventurier& aventurier){ 
        }

};

#endif