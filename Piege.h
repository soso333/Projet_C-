#ifndef PIEGE_H
#define PIEGE_H

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

        appliqueEffet(int points_de_vie_joueur) : int 
        Prend en paramètre les pv de l'aventurier et lui applique des dégats
        Renvoie les pv restants de l'aventurier
        Permet d'appliquer l'effet du piège sur le joueur
    
    
    */
    private : 
        int degats;

    public:

        void init(int a){
            degats = a; 
        }

        char afficher(){
            char a = 'T';
            return a;
        }

        virtual int appliqueEffet(int points_de_vie_joueur){ //en cas de coup par le monstre
            points_de_vie_joueur -= degats; 
            return points_de_vie_joueur;
        }
};

#endif