//Uxue
#include "Donjon.h"

Donjon::~Donjon(){
    for(int i = 0; i<h; i++){
        for(int j = 0; j<l; j++){
            delete grille[i][j]; 
        };
    };
};

void Donjon::genererLabyrinthe(int x, int y){
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
            grille[x][y]->setVisite(true);
            grille[nx1][ny1]->setVisite(true);

            genererLabyrinthe(nx, ny);
        }
    }
}

void Donjon::initialiserGrille(int largeur, int hauteur) {
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
    genererLabyrinthe(0, 0);
    delete grille[0][0];
    delete grille[hauteur-1][largeur-1];
    grille[0][0] = CaseFactory::creerCase(TypeCase::Passage); //poserEntree(grille);
    grille[hauteur-1][largeur-1] = CaseFactory::creerCase(TypeCase::Passage); //poserSortie(grille);
}

void Donjon::placerElements(){
    for(int i = 0; i<h; i++){
        for(int j = 0; j<l; j++){
            if(grille[i][j]->afficher() == ' '){
                int r = rand()%100 + 1;
                if(r < 5){
                    delete grille[i][j];
                    grille[i][j] = CaseFactory::creerCase(TypeCase::Tresor);
                }
                else if(r>=5 && r <10){
                    delete grille[i][j];
                    grille[i][j] = CaseFactory::creerCase(TypeCase::Monstre);
                }
                else if(r>=10 && r<13){
                    delete grille[i][j];
                    grille[i][j] = CaseFactory::creerCase(TypeCase::Piege);
                }
            }
        }
    }
}

/*
vector<pair<int, int>> Donjon::trouverChemin(pair<int, int> depart,  pair<int, int> arrivee){
    queue<pair<int, int>> file = {};
    vector<vector<bool>> visite(h, vector<bool>(l));
    vector<vector<pair<int, int>>> parent(h, vector<pair<int, int>>(l));

    for(int i = 0; i<h; i++){
        for(int j = 0; j<l; j++){
            visite[i][j] = false;
            parent[i][j] = {-1, -1};
        }
    }

    file.push(depart);
    visite[depart.first][depart.second] = true;

    pair<int, int> NORD = {-1, 0};
    pair<int, int> SUD = {1, 0};
    pair<int, int> EST = {0, 1};
    pair<int, int> OUEST = {0, -1};
    vector<pair<int, int>> directions = {NORD, SUD, EST, OUEST};

    while(!file.empty()){
        
        pair<int, int> courant = file.front();
        file.pop();

        if (courant == arrivee){
            return reconstruireChemin(parent, depart, arrivee);
        }
        
        for(int i = 0; i<4; i++){
            pair<int, int> d = directions[i];
            int nx = d.first + courant.first;
            int ny = d.second + courant.second;
            pair<int, int> v = {nx, ny};
            if(nx>=0 && nx<h && ny>=0 && ny<l && visite[nx][ny] == false && grille[nx][ny]->type != TypeCase::Mur){
                visite[nx][ny] = true;
                parent[nx][ny] = courant;
                file.push(v);
            }
        }
    }
    return {};


}
vector<pair<int, int>> Donjon::reconstruireChemin(vector<vector<pair<int, int>>> parent, pair<int, int> depart, pair<int, int> arrivee){

}

*/