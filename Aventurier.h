#include <iostream>
#include "Donjon.h"
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
            if (pv > 0) {
                return true;
            }
            else {
                return false;
            }
        };

        void afficherStatut(){
            cout << "Position : ( " << x << " , " << y << " )" << endl;
            cout << "Sante : " << pv << "/100" << endl;
            cout << "Inventaire : " << inventaire << " tresors" << endl;
        };

        void boucleDeJeu(Donjon& d){
            while (estVivant() == true){
                // AFFICHAGE DU DONJON ET JOUEUR
                for(int i = 0; i<d.h; i++){
                    for(int j = 0; j<d.l; j++){
                        if (i == x && j == y) {
                            cout << constafficher();
                        }
                        else {
                            cout << d.grille[i][j] -> afficher(); 
                        }
                    };
                cout << endl;
                };
                cout << "" << endl;
                afficherStatut();

                // LECTURE TOUCHE
                char direction;
                cin >> direction;
                if (direction == 'z'){
                    deplacer(-1, 0);
                }
                else if (direction == 's') {
                    deplacer(1, 0);
                }
                else if (direction == 'q') {
                    deplacer(0, -1);
                }
                else if (direction == 'd') {
                    deplacer(0, 1);
                }
            }

        };

};

#endif

