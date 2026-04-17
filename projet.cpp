#include <iostream>
#include <vector>
using namespace std;


class Case{
    public:
        virtual char afficher() = 0;
        virtual ~Case() = default;
};

class Mur : public Case {
    public:
        char afficher(){
            char a = '#';
            return a;
        }
};

class Passage : public Case{

};
class Tresor : public Case {
    public:
        char afficher(){
            char a = '+';
            return a;
        }
};
class Monstre : public Case{
    public:
        char afficher(){
            char a = 'M';
            return a;
        }
};
class Piege : public Case {
    public:
        char afficher(){
            char a = 'T';
            return a;
        }
};
class Aventurier : public Case {
    public:
        char constafficher(){
            char a = '@';
            return a;
        }
};


class Donjon{
    vector<vector<Case*>> grille;
    public:
        void generer(int largeur, int hauteur);
        void afficher();
        vector<pair<int, int>> trouverChemin();
};
