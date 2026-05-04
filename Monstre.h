#ifndef MONSTRE_H
#define MONSTRE_H

#include <iostream>
#include "Aventurier.h"

class Monstre : public Case{

    /* Classe permettant de définir le monstre qu'un joueur peut rencontrer

    Paramètres : 
        valeur : int (private)
        Permet de définir une valeur qui supprime des points de vie à un joueur
        pv : int (private)
        Permet de définir les points de vie du monstre (pour le combat)

    Méthode : 
        init : void 
        Permet d'initiliaser la valeur de l'attaque du monstre

        afficher() : char
        Permet d'afficher la chaîne de caractère représentant le monstre dans le labyrinthe (par +)

        appliqueEffet(int points_de_vie_joueur) : int
        Permet d'appliquer l'effet de l'attaque du monstre sur le joeur
        Prends en paramètre les pv de l'aventurier

        fuite() : void 
        Permet de déterminer si le joueur veut fuir ou pas face au monstre

        vaincu() : void
        Permet de dire si le monstre est vaincu ou pas s'il y a combat (s'il fuit pas)
    */

    private : 
        int valeur;
        int pv;

    public : 
        void init(int a, int b){
            valeur = a;
            pv = b;
        }

        char afficher(){
            char a = 'M';
            return a;
        }

        virtual int appliqueEffet(int points_de_vie_joueur){ //en cas de coup par le monstre
            points_de_vie_joueur -= valeur; 
            return points_de_vie_joueur;
        }

        //je sais pas s'il faut le mettre dans cette classe mais voilà je le définis ici
        //les noms des paramètres etc serot changés en fonction de ce que vous ferez
        // adresse du joueur comme ça ça modifie directement sa position
        void fuite(Aventurier& aventurier, int position_precedente_x, int position_precedente_y, bool est_fuite){

            if (est_fuite == true) { 
                aventurier.x = position_precedente_x;
                aventurier.y = position_precedente_y;
            }
        }

        //dialogue pour dire que le combat est fini, pour arrêter le combat on aura qu'à juste plus utiliser applique_effet...
        void vaincu(){

            if (pv <= 0) {
                std::cout << "le monstre a été vaincu" <<std::endl;
            }
        }


};

#endif