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
    // Les 4 directions : nord, sud, est et ouest avec un pas de 2
    int NORD[2] = {-2, 0};
    int SUD[2] = {2, 0};
    int EST[2] = {0, 2};
    int OUEST[2] = {0, -2};
    int *directions[4] = {NORD, SUD, EST, OUEST};

    // Mélange à travers les indices associés aux directions
    int indices[4] = {0, 1, 2 ,3};
    random_device rd;
    mt19937 g(rd());
    shuffle(std::begin(indices), std::end(indices), g);

    for(int i = 0; i<4; i++){
        int *d = directions[indices[i]];
        // Position à deux cases de distance de la case actuelle
        int nx = d[0] + x;
        int ny = d[1] + y;
        
        // Position à une case de distance de la case actuelle
        int nx1 = d[0]/2 + x;
        int ny1 = d[1]/2 + y;

        if(nx >= 0 && ny >= 0 && nx < h && ny < l && grille[nx][ny] -> getVisite() == false){
            // Pour éviter les fuites de Mémoire on efface la case existante
            delete grille[nx1][ny1];
            delete grille[nx][ny];

            // Création des cases et modification de l'état de chaque case visité au passage
            grille[x][y] = CaseFactory::creerCase(TypeCase::Passage);
            grille[nx1][ny1] = CaseFactory::creerCase(TypeCase::Passage);
            grille[nx][ny] = CaseFactory::creerCase(TypeCase::Passage);
            grille[x][y]->setVisite(true);
            grille[nx1][ny1]->setVisite(true);

            // Recursive Bactracking pour la génération
            genererLabyrinthe(nx, ny);
        }
    }
}

void Donjon::initialiserGrille(int largeur, int hauteur) {
    // Pour récupérer la valeur de la hauteur et la largeur de la grille et les utiliser ailleurs
    l = largeur;
    h = hauteur;

    // allocation dynamique à travers le resize en fonction de la hauteur et de la largeur
    grille.resize(hauteur);
    for(int i = 0; i < hauteur; i++) {
        grille[i].resize(largeur);
    }
    for(int i = 0; i<hauteur; i++){
        for(int j = 0; j<largeur; j++){
            grille[i][j] = CaseFactory::creerCase(TypeCase::Mur);
        };
    };

    // Initialisation des passages aux positions initiale et finale
    genererLabyrinthe(0, 0);
    delete grille[0][0];
    delete grille[hauteur-1][largeur-1];
    grille[0][0] = CaseFactory::creerCase(TypeCase::Passage); 
    grille[hauteur-1][largeur-1] = CaseFactory::creerCase(TypeCase::Passage); 
}

void Donjon::placerElements(){
    for(int i = 0; i<h; i++){
        for(int j = 0; j<l; j++){

            // Évite de placer des éléments (autres que Passage) à l'entrée
            bool entree;
            if(i == 0 && j == 0){
                entree = true;
            }
            else{
                entree = false;
            }
            if(grille[i][j]->afficher() == ' ' && entree == false){
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


vector<pair<int, int>> Donjon::trouverChemin(pair<int, int> depart,  pair<int, int> arrivee){
    queue<pair<int, int>> file = {};
    vector<vector<bool>> visite(h, vector<bool>(l));
    vector<vector<pair<int, int>>> parent(h, vector<pair<int, int>>(l));

    // Initialisation de visite et de parent
    for(int i = 0; i<h; i++){
        for(int j = 0; j<l; j++){
            visite[i][j] = false;
            parent[i][j] = {-1, -1};
        }
    }

    file.push(depart);
    visite[depart.first][depart.second] = true;

    // Définition des 4 directions 
    pair<int, int> NORD = {-1, 0};
    pair<int, int> SUD = {1, 0};
    pair<int, int> EST = {0, 1};
    pair<int, int> OUEST = {0, -1};
    vector<pair<int, int>> directions = {NORD, SUD, EST, OUEST};

    // Algorithme de BFS : Breadth First Search
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
    vector<pair<int, int>> chemin = {};
    pair<int, int> courant = arrivee;
    
    while(courant != depart){
        chemin.insert(chemin.begin(), courant);
        courant = parent[courant.first][courant.second];
    }
    chemin.insert(chemin.begin(), depart);
    return chemin;
}

