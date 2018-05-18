#include "iostream"
#include <stdio.h>
#include <assert.h>
#include "Bibliotheque.h"
#include <vector>

using namespace std;




int main() {



/*
    date datesortie;
    datesortie.jour = 1;
    datesortie.mois = 10;
    datesortie.annee = 1996;
    periode periodeemprunt;
    periodeemprunt.debut.jour = 4;
    periodeemprunt.debut.mois = 9;
    periodeemprunt.debut.annee = 2000;
    periodeemprunt.fin.jour = 1;
    periodeemprunt.fin.mois = 9;
    periodeemprunt.fin.annee = 2020;
    int nbr_pages = 40;
    string collection = "aaaaaaaaaa";
    string resume = "AAAAAAA";
    Clivre *livre1 = new Clivre("Berserk","Kentaro Miura", datesortie, 117,nbr_pages,collection,resume);
    //livre1->affichage();
    /*ressource1->emprunt("Divette",periodeemprunt);
    ressource1->affichage();
    ressource1->remise();
    ressource1->affichage();
    cout << "\n" << endl;

    vector<Clivre*> liivres;
    liivres.push_back(livre1);
    liivres.push_back(livre1);
    liivres[0]->affichage();
    liivres[1]->affichage();*/

/*
    vector<Clivre*> livres;
    vector<Crevue*> revues;
    vector<Ccd*> cds;
    vector<Cdvd*> dvds;
    vector<Cvhs*> vhs;
    vector<Cressource_numerique*> ressources_numeriques;
    const char *nomfichier = "exemple_mediatheque.txt";

    LoadMediatheque2(nomfichier,livres,revues,cds,dvds,vhs,ressources_numeriques);
    livres[0]->affichage();
    cout << "\n" << endl;
    /*revues[0]->affichage();
    cout << "\n" << endl;
    cds[0]->affichage();
    cout << "\n" << endl;
    dvds[0]->affichage();
    cout << "\n" << endl;
    vhs[0]->affichage();
    cout << "\n" << endl;
    ressources_numeriques[0]->affichage();
    cout << "\n" << endl;
    livres[1]->affichage();
    */

    /*
     *  const char *nomfichier = "exemple_mediatheque.txt";
        LoadMediatheque1(nomfichier, mediatheque);
        mediatheque.livres[0]->affichage();
        mediatheque.revues[0]->affichage();
        mediatheque.livres[1]->affichage();
     */

    //C:\Users\mapep\OneDrive\Documents\Class\ENSEIRB\C++\Bibliotheque\cmake-build-debug\exemple_mediatheque.txt

    vector<int> ids;
    vector<int> ids_dispo;
    ids_dispo.push_back(12345);
    ids_dispo.push_back(117);
    Cmediatheque mediatheque; //initialisation de la structure de vecteurs que l'on nomme mediatheque
    int state = 1;
    while(state){

        string input;
        cout << "Que voulez vous faire ? : \n" << endl;
        cout << "Commandes possibles : \n" << "LOAD \n" << "BYE \n" << "SAVE" << endl;
        cin >> input;

        if (input == "LOAD"){
            cout << "Entrez le chemin et le nom du fichier source :" << endl;
            cin >> input;
            LOAD(input.c_str(), mediatheque, ids, ids_dispo);
        }
        if (input == "SAVE"){
            cout << "Entrez le chemin et le nom du fichier de sauvegarde :" << endl;
            cin >> input;
            SAVE(input.c_str(), mediatheque, ids_dispo);
        }
        if (input == "BYE"){
            state = 0;
        }
    }
    return 0;
}