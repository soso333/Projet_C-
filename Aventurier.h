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

        //permet au joueur de fuir
        int x_precedent, y_precedent;
        
        //stocker le pas selon x et le pas selon y 
        int pas_x, pas_y;
    
    public:
        Aventurier(){
           pv = 100;
           x = 0;
           y = 0;
           inventaire = 0; 

           //ajout des positions précédentes du joueur pour permettre au joueur de fuir face au monstre
           x_precedent = 0;
           y_precedent = 0;
           pas_x = 0; 
           pas_y = 0;
        };

        ~Aventurier() = default;

        char constafficher(){
            char a = '@';
            return a;
        };

        void deplacer(int nx, int ny){
            // si (x+nx,y+ny) dans grille est différent de MUR => x = x + nx et y = y + ny
            x_precedent = x;
            y_precedent = y;
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
            int nx=0;
            int ny=0;

            vector<pair<int,int>> chemin;   // pour calcul chemin optimal
            int distance;
            chemin = d.trouverChemin({0,0}, {d.h-1,d.l-1});
            distance = chemin.size()-1;

            while (estVivant() == true){
                
                char direction;

                if (direction == 'p'){

                    // AFFICHAGE DU DONJON ET JOUEUR
                    for(int i = 0; i<d.h; i++){
                        for(int j = 0; j<d.l; j++){
                            if (i == x && j == y) {
                                cout << constafficher();
                            }
                            else {
                                bool dans_chemin = false;
                                for (int k = 0; k<chemin.size();k++){
                                    if (chemin[k].first == i && chemin[k].second == j){
                                        dans_chemin = true;
                                    }
                                }
                                if (dans_chemin == true){
                                    cout << ".";
                                }
                                else{
                                cout << d.grille[i][j] -> afficher(); 
                                }
                            }
                        };
                    cout << endl;
                    };
                    cout << "" << endl;
                    afficherStatut();
                    cout << "Distance à la sortie : " << distance << " cases" << endl;

                    cin >> direction;
                }

                else {
                    //réinitialisation des pas du joueur à chaque itération : 
                    pas_x = 0; 
                    pas_y = 0; 

                    // LECTURE TOUCHE
                    if (direction == 'z'){
                    // deplacer(-1, 0);

                    //petit changement pour se déplacer uniquement si y a pas un mur sur le chemin
                    pas_x = -1;
                    pas_y = 0;
                    }
                    else if (direction == 's') {
                    //  deplacer(1, 0);
                        pas_x = 1;
                        pas_y = 0;
                    }
                    else if (direction == 'q') {
                    // deplacer(0, -1);
                        pas_x = 0; 
                        pas_y = -1;
                    }
                    else if (direction == 'd') {
                    //  deplacer(0, 1);
                        pas_x = 0; 
                        pas_y = 1;
                    }
                    
                    nx = x + pas_x;
                    ny = y + pas_y;
                    //on vérifie qu'on fonce pas sur un mur
                    if (nx>=0 && nx<d.h && ny>=0 && ny<d.l && d.grille[x+pas_x][y+pas_y] -> type != TypeCase::Mur) {
                        deplacer(pas_x, pas_y);
                        d.grille[x][y] -> appliqueEffet(*this); //on applique l'effet de la case sur le joueur
                        
                        chemin = d.trouverChemin({x,y}, {d.h-1,d.l-1});
                        distance = chemin.size()-1;

                        if (d.grille[nx][ny] -> type == TypeCase::Tresor){
                            d.grille[x][y] = CaseFactory::creerCase(TypeCase::Passage);
                        }
                    }

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
                    cout << "Distance à la sortie : " << distance << " cases" << endl;

                    
                    // AFFICHAGE VICTOIRE
                    if (x == d.h-1 && y == d.l-1){
                        cout << "FELICITATIONS !! Vous avez gagné la partie !!" << endl;
                        return;
                    }

                    /*else {
                        cout << "Tu es face à un mur l'équipe" << endl;
                    }*/

                    cin >> direction;
                }
                
            
            }

            // FIN DE PARTIE
            cout << "GAME OVER :(" << endl;
            return;

        };

};

#endif


