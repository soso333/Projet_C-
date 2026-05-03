//Uxue
#include <vector>
#include <iostream>
#include "Mur.h"
#include "Passage.h"
using namespace std;

class Donjon { 
    /* Classe permettant de définir le donjon où le joueur va s'aventurer.

    Paramètres :
        - l : int (private)
            Largeur du labyrinthe.
        - h : int (private)
            Hauteur du labyrinthe.
    
    Méthodes :
        - genererLabyrinthe(int x, int y) : void
            Permet de générer le labyrinthe à travers une méthode récursive.
        - initialiserGrille(int largeur, int hauteur) : void
            Permet d'initialiser la grille (le labyrinthe) de base en creusant des passages dans les murs.
        - placerElements() : void
            Permet de placer les pièges, les monstres et les trésors sur la grille.
        - afficher() : void
            Permet l'affichage de la grille.
    */
    vector<vector<Case*>> grille;
    private:
        int l;
        int h;
    public : 

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
                    delete grille[nx1][ny1];
                    delete grille[nx][ny];

                    grille[x][y] = CaseFactory::creerCase(TypeCase::Passage);
                    grille[nx1][ny1] = CaseFactory::creerCase(TypeCase::Passage);
                    grille[nx][ny] = CaseFactory::creerCase(TypeCase::Passage);
                    grille[nx1][ny1]->setVisite(true);
                    genererLabyrinthe(nx, ny);
                }
            }
        }
        
        void initialiserGrille(int largeur, int hauteur) {
            l = largeur;
            h = hauteur;
            grille.resize(hauteur);
            for(int i = 0; i < hauteur; i++) {
                grille[i].resize(largeur);
            }
            for(int i = 0; i<hauteur; i++){
                for(int j = 0; j<largeur; j++){
                    grille[i][j] = CaseFactory::creerCase(TypeCase::Mur); //CaseFactory?
                };
            };
            genererLabyrinthe(1, 1);
            delete grille[0][0];
            delete grille[hauteur-1][largeur-1];
            grille[0][0] = CaseFactory::creerCase(TypeCase::Passage); //poserEntree(grille);
            grille[hauteur-1][largeur-1] = CaseFactory::creerCase(TypeCase::Passage); //poserSortie(grille);
        }
        
        void placerElements(){
            for(int i = 0; i<h; i++){
                for(int j = 0; j<l; j++){
                    if(grille[i][j]->afficher() == ' '){
                        int r = rand()%100 + 1;
                        if(r < 5){
                            delete grille[i][j];
                            grille[i][j] = CaseFactory::creerCase(TypeCase::Tresor)
                        }
                        else if(r>=5 && r <10){
                            delete grille[i][j];
                            grille[i][j] = CaseFactory::creerCase(TypeCase::Monstre)
                        }
                        else if(r>=10 && r<13){
                            delete grille[i][j];
                            grille[i][j] = CaseFactory::creerCase(TypeCase::Piege)
                        }
                    }
                }
            }
        }
        
        void afficher(){
            for(int i = 0; i<h; i++){
                for(int j = 0; j<l; j++){
                    cout << grille[i][j] -> afficher(); 
                };
            cout << endl;
            };
        }
};