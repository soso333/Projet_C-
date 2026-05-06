#ifndef PIEGE_H
#define PIEGE_H
#include "Case.h"
#include "Aventurier.h"

class Piege : public Case {

    /*
    Classe permettant de définir une case piège dans le labyrinthe 

    Paramètres : 
        degat : int (private)
        Permet de définir les dégats que subit un joueur par le piège

    Méthode : 
        init : void
        Permet d'initialiser les valeurs

        afficher() : char 
        Permet d'afficher la chaine de caractere du piège dans le labyrinthe (avec T)

        appliqueEffet(Aventurier& aventurier) : void
        Prend en paramètre le joueurde l'aventurier et lui applique des dégats
        Permet d'appliquer l'effet du piège sur le joueur
    
    
    */
    private : 
        int degats;

    public:
        Piege(){
            type = TypeCase::Piege;
            init();
        }

        void init(int a = 25){
            degats = a; 
        }

        char afficher(){
            char a = 'T';
            return a;
        }

        virtual void appliqueEffet(Aventurier& aventurier){ //en cas de coup par le monstre
            aventurier.pv -= degats; 
            std::cout << "Vous venez de subir " << degats << "de la part du piège" << std::endl;
        }
};

#endif