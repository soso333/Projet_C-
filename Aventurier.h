#include <iostream>
using namespace std;

#ifndef AVENTURIER_H
#define AVENTURIER_H

class Aventurier {
    public:
        int pv;
        int x, y;
        int inventaire;
    
    public:
        Aventurier(){
           pv = 100;
           x = 0;
           y = 0;
           inventaire = 0; 
        };
        ~Aventurier() = default;

        char constafficher(){
            char a = '@';
            return a;
        };

        void deplacer(int nx, int ny){
            // si (x+nx,y+ny) dans grille est différent de MUR => x = x + nx et y = y + ny
            x = x + nx;
            y = y + ny;
        };

        bool estVivant(){
            return pv > 0;
        };

        void afficherStatut(){
            cout << "Position : ( " << x << " , " << y << " )" << endl;
            cout << "Sante : " << pv << "/100" << endl;
            cout << "Inventaire : " << inventaire << " tresors" << endl;
        };

};

#endif

