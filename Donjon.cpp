//Uxue
#include <vector>
#include <iostream>
#include "Mur.h"
#include "Passage.h"
//using namespace std;

class Donjon { 
    vector<vector<Case*>> grille;
    private:
        int l;
        int h;
    public : 
        void generer(int largeur, int hauteur) {
            l = largeur;
            h = hauteur;
            grille.resize(hauteur);
            for(int i = 0; i < hauteur; i++) {
                grille[i].resize(largeur);
            }
            for(int i = 0; i<hauteur; i++){
                for(int j = 0; j<largeur; j++){
                    grille[i][j] = Mur; //CaseFactory?
                };
            };
        }

        void afficher(){
            //blablabla
        }

        vector<pair<int, int>> trouverChemin(...);

        void genererLabyrinthe(int x, int y){
            grille[x][y]->setVisite(true);
            int NORD[2] = {-2, 0};
            int SUD[2] = {2, 0};
            int EST[2] = {0, 2};
            int OUEST[2] = {0, -2};
            int *directions[4] = {NORD, SUD, EST, OUEST};

            // Mélange
            int indices[4] = {0, 1, 2 ,3};
            std::random_device rd;
            std::mt19937 g(rd());
            std::shuffle(std::begin(indices), std::end(indices), g);

            for(int i = 0; i<4; i++){
                int *d = directions[indices[i]];
                int nx = d[0] + x;
                int ny = d[1] + y;

                int nx1 = d[0]/2 + x;
                int ny1 = d[1]/2 + y;

                if(nx >= 0 && ny >= 0 && nx < h && ny < l && grille[nx][ny] -> getVisite() == false){
                    grille[x][y] = Passage;
                    grille[nx1][ny1] = Passage;
                    grille[nx][ny] = Passage;
                    grille[nx1][ny1]->setVisite(true);
                    genererLabyrinthe(nx, ny);
                }
            }
        }
};