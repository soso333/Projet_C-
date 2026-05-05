#ifndef DONJON_H
#define DONJON_H

#include <algorithm>
#include <vector>
#include <iostream>
#include <random>
#include "CaseFactory.h"
#include "Case.h"
using namespace std;

class Donjon{
    /* Classe permettant de définir le donjon où le joueur va s'aventurer.

    Paramètres :
        - l : int (private)
            Largeur du labyrinthe.
        - h : int (private)
            Hauteur du labyrinthe.
    
    Méthodes :
        - Donjon()
            Constructeur de la classe Donjon.
        - ~Donjon()
            Destructeur de la classe Donjon.
        - genererLabyrinthe(int x, int y) : void
            Permet de générer le labyrinthe à travers une méthode récursive.
        - initialiserGrille(int largeur, int hauteur) : void
            Permet d'initialiser la grille (le labyrinthe) de base en creusant des passages dans les murs.
        - placerElements() : void
            Permet de placer les pièges, les monstres et les trésors sur la grille.
        - afficher() : void
            Permet l'affichage de la grille.
    */
    
    public:
        vector<vector<Case*>> grille;
        int l;
        int h;
    public :
        vector<pair<int, int>> trouverChemin(...);
        Donjon(){
           h = 0;
           l = 0; 
        };
        ~Donjon();
        void genererLabyrinthe(int x, int y);
        void initialiserGrille(int largeur, int hauteur);
        void placerElements();
        void afficher();
};

#endif