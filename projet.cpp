#include <iostream>
#include <vector>
using namespace std;


class Case{
    public:
        virtual char afficher() = ();
        virtual ~Case() = default;
};


class Donjon{
    vector<vector<Case*>> grille;
    public:
        void generer(int largeur, int hauteur);
        void afficher();
        vector<pair<int, int>> trouverChemin();
};
