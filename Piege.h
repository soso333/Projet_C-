#ifndef PIEGE_H
#define PIEGE_H
#include <iostream>
using namespace std;
#include "Case.h"
#include "Aventurier.h"

class Piege : public Case {

    /*
    Classe permettant de définir une case piège dans le labyrinthe 

    Paramètres : 
        degats : int (private)
        Permet de définir les dégats que subit un joueur par le piège

    Méthode : 
        afficher() : char 
        Permet d'afficher la chaine de caractere du piège dans le labyrinthe (avec T)

        appliqueEffet(Aventurier& aventurier) : void
        Prend en paramètre le joueur et lui applique des dégats
        Permet d'appliquer l'effet du piège sur le joueur
    
    
    */
    private : 
        int degats;

    public:
        //constructeur
        Piege(int a = 25){
            type = TypeCase::Piege;
            degats = a;
        }

        char afficher()const override{
            char a = 'T';
            return a;
        }

        virtual void appliqueEffet(Aventurier& aventurier){ //en cas de coup par le monstre
            aventurier.setPV(max(0, aventurier.getPV() - degats)); 
            std::cout << "Vous venez de subir " << degats << "pv de degat de la part du piège" << std::endl;
        }

   
};

#endif