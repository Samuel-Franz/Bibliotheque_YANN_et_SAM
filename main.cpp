#include "iostream"
#include <stdio.h>
#include <assert.h>
#include "Bibliotheque.h"
#include <vector>
#include <iomanip>

using namespace std;

//*********************************************************************************************//
//                                                                                             //
//                                          PATH :                                             //
//  C:\Users\mapep\OneDrive\Documents\Class\ENSEIRB\C++\Bibliotheque\exemple_mediatheque.txt   //
//                                                                                             //
//*********************************************************************************************//

//C:\Users\mapep\OneDrive\Documents\Class\ENSEIRB\C++\Bibliotheque\exemple_mediatheque.txt

int main() {

//**************************************************************************//
//                              INITIALISATION                              //
//**************************************************************************//

    vector<int> ids_dispo;    // Initialisation du vecteur des identifiant disponibles
    Cmediatheque mediatheque; // Initialisation de la structure de la mediatheque
    Cmediatheque recherche;   // Initialisation de la structure de recherche
    int state = 1;
    string input;
    cout << "********************************************************************************************" << endl;
    CMD_help();
    cout << "********************************************************************************************" << endl;

    while(state){

        int commande_valide = 0; // Flag de validité syntaxique d'une commande

        cout << "\n";
        cout << "********************************************************************************************" << endl;
        cout << "\n";

        cout << "Que voulez vous faire ? :" << endl;
        cout << "Commandes possibles : \n" << left << setw(15) << "LOAD"      <<
                                              left << setw(15) << "BYE"       <<
                                              left << setw(15) << "SAVE"      <<
                                              left << setw(15) << "ADD"       << "DELETE\n" <<
                                              left << setw(15) << "SHOW"      <<
                                              left << setw(15) << "LIST"      <<
                                              left << setw(15) << "SEARCH"    <<
                                              left << setw(15) << "RENT"      << "CLEAR\n"  <<
                                              left << setw(15) << "RETURN\n"  << endl;

		cin >> input;

//**************************************************************************//
//                                                                          //
//                   EXECUTION DES DIFFERENTES COMMANDES                    //
//                                                                          //
//**************************************************************************//

//**************************************************************************//
//                                   LOAD                                   //
//**************************************************************************//

        if (input == "LOAD"){
            cout << "Entrez le chemin et le nom du fichier source :" << endl;
            cin >> input;
            LOAD(input.c_str(), mediatheque, ids_dispo);
            cout << "\n";
            commande_valide = 1;
        }

//**************************************************************************//
//                                   SAVE                                   //
//**************************************************************************//

        if (input == "SAVE"){
            cout << "Entrez le chemin et le nom du fichier de sauvegarde :" << endl;
            cin >> input;
            SAVE(input.c_str(), mediatheque, ids_dispo);
            commande_valide = 1;
        }

//**************************************************************************//
//                                   ADD                                    //
//**************************************************************************//

        if (input == "ADD"){
            cout << "Quel type de ressource voulez vous ajouter ? : " << endl;
            cin >> input;
            while ((input != "LIVRE") && (input != "REVUE") && (input != "CD") && (input != "DVD") && (input != "VHS") && (input != "RESSOURCE_NUMERIQUE")){
                cout << "Type non reconnu, veuillez ressaisir le type : " << endl;
                cin >> input;
            }
            ADD(input, mediatheque,ids_dispo);
            commande_valide = 1;
        }

//**************************************************************************//
//                                  DELETE                                  //
//**************************************************************************//

        if (input == "DELETE"){
            cout << "Connaissez-vous l'identifiant de la ressource a effacer ? (OUI ou NON) : " << endl;
            cin >> input;
            if (input == "OUI"){
                cout << "ID de la ressource a effacer ?" << endl;
                int id_delete;
                cin >> id_delete;
                DELETE(id_delete, mediatheque, ids_dispo);
                commande_valide = 1;
            }
            else{
                LIST_ID(mediatheque);
                cout << "ID de la ressource a effacer ?" << endl;
                int id_delete;
                cin >> id_delete;
                DELETE(id_delete, mediatheque, ids_dispo);
                commande_valide = 1;
            }
        }

//**************************************************************************//
//                                   SHOW                                   //
//**************************************************************************//

        if (input == "SHOW"){
            cout << "Connaissez-vous l'identifiant de la ressource a afficher ? (OUI ou NON) : " << endl;
            cin >> input;
            if (input == "OUI"){
                cout << "Veuillez rentrer l'identifiant de la ressource a afficher :" << endl;
                int id_show;
                cin >> id_show;
                while ((id_show >= *ids_dispo.begin()) || (find(ids_dispo.begin()+1,ids_dispo.end(), id_show)) != ids_dispo.end() || (id_show < 1)){
                    cout << "L'identifiant entre n'est pas valide, cette ressource n'existe pas, veuillez en rentrer un autre " << endl;
                    cin >> id_show;
                }
                cout << "\n";
                SHOW(id_show, mediatheque);
                commande_valide = 1;
            }
            else{
                LIST_ID(mediatheque);
                cout << "Veuillez rentrer l'identifiant de la ressource a afficher :" << endl;
                int id_show;
                cin >> id_show;
                while ((id_show >= *ids_dispo.begin()) || (find(ids_dispo.begin()+1,ids_dispo.end(), id_show)) != ids_dispo.end() || (id_show < 1)){
                    cout << "L'identifiant entre n'est pas valide, cette ressource n'existe pas, veuillez en rentrer un autre " << endl;
                    cin >> id_show;
                }
                cout << "\n";
                SHOW(id_show, mediatheque);
                commande_valide = 1;
            }

        }

//**************************************************************************//
//                                   LIST                                   //
//**************************************************************************//

        if (input == "LIST") {
            if (recherche.livres.empty() && recherche.revues.empty() && recherche.cds.empty() && recherche.dvds.empty() && recherche.vhs.empty() && recherche.ressources_numeriques.empty()){
                LIST(mediatheque);
                commande_valide = 1;
            }
            else{
                LIST(recherche);
                commande_valide = 1;
            }
        }

//**************************************************************************//
//                                  SEARCH                                  //
//**************************************************************************//

        if (input == "SEARCH"){
            cout << "Que voulez vous rechercher?" << endl;
            cin >> input;
            SEARCH(input, mediatheque, recherche);
            if (!recherche.livres.empty() || !recherche.revues.empty() || !recherche.cds.empty() || !recherche.dvds.empty() || !recherche.vhs.empty() || !recherche.ressources_numeriques.empty()){
                cout << recherche.livres.size() + recherche.revues.size() + recherche.cds.size() + recherche.dvds.size() + recherche.vhs.size() + recherche.ressources_numeriques.size() << " " << "resultats trouves" << endl;
                cout << "Entrez 'LIST' pour les afficher ou CLEAR pour les effacer" << endl;
            }
            else
                cout << "Aucun resultat trouve" << endl;
            commande_valide = 1;
        }

//**************************************************************************//
//                                  CLEAR                                   //
//**************************************************************************//

        if (input == "CLEAR"){
            CLEAR(recherche);
            commande_valide = 1;
        }

//**************************************************************************//
//                                   RESET                                  //
//**************************************************************************//

        if (input == "RESET"){
            CLEAR(mediatheque);
            commande_valide = 1;
        }

//**************************************************************************//
//                                   RENT                                   //
//**************************************************************************//

        if (input == "RENT") {
            cout << "Connaissez-vous l'identifiant de la ressource a louer ? (OUI ou NON) : " << endl;
            cin >> input;
            if (input == "OUI") {
                cout << "Veuillez rentrer l'identifiant de la ressource a louer :" << endl;
                int id_rent;
                cin >> id_rent;
                while ((id_rent >= *ids_dispo.begin()) ||
                       (find(ids_dispo.begin() + 1, ids_dispo.end(), id_rent)) != ids_dispo.end() || (id_rent < 1)) {
                    cout
                            << "L'identifiant entre n'est pas valide, cette ressource n'existe pas, veuillez en rentrer un autre "
                            << endl;
                    cin >> id_rent;
                }
                cout << "\n";
                RENT(id_rent, mediatheque);
                commande_valide = 1;
            } else {
                SEARCH("Disponible", mediatheque, recherche);
                LIST_ID(recherche);
                CLEAR(recherche);
                cout << "Veuillez rentrer l'identifiant de la ressource a louer :" << endl;
                int id_rent;
                cin >> id_rent;
                while ((id_rent >= *ids_dispo.begin()) ||
                       (find(ids_dispo.begin() + 1, ids_dispo.end(), id_rent)) != ids_dispo.end() || (id_rent < 1)) {
                    cout
                            << "L'identifiant entre n'est pas valide, cette ressource n'existe pas, veuillez en rentrer un autre "
                            << endl;
                    cin >> id_rent;
                }
                cout << "\n";
                RENT(id_rent, mediatheque);
                commande_valide = 1;
            }
        }

//**************************************************************************//
//                                  RETURN                                  //
//**************************************************************************//

        if (input == "RETURN") {
            cout << "Connaissez-vous l'identifiant de la ressource a rendre ? (OUI ou NON) : " << endl;
            cin >> input;
            if (input == "OUI") {
                cout << "Veuillez rentrer l'identifiant de la ressource a rendre :" << endl;
                int id_return;
                cin >> id_return;
                while ((id_return >= *ids_dispo.begin()) ||
                       (find(ids_dispo.begin() + 1, ids_dispo.end(), id_return)) != ids_dispo.end() || (id_return < 1)) {
                    cout
                            << "L'identifiant entre n'est pas valide, cette ressource n'existe pas, veuillez en rentrer un autre "
                            << endl;
                    cin >> id_return;
                }
                cout << "\n";
                RETURN(id_return, mediatheque);
                commande_valide = 1;
            } else {
                SEARCH("Loue", mediatheque, recherche);
                LIST_ID(recherche);
                CLEAR(recherche);
                cout << "Veuillez rentrer l'identifiant de la ressource a rendre :" << endl;
                int id_return;
                cin >> id_return;
                while ((id_return >= *ids_dispo.begin()) ||
                       (find(ids_dispo.begin() + 1, ids_dispo.end(), id_return)) != ids_dispo.end() || (id_return < 1)) {
                    cout
                            << "L'identifiant entre n'est pas valide, cette ressource n'existe pas, veuillez en rentrer un autre "
                            << endl;
                    cin >> id_return;
                }
                cout << "\n";
                RETURN(id_return, mediatheque);
                commande_valide = 1;
            }
        }

//**************************************************************************//
//                                   BYE                                    //
//**************************************************************************//

        if (input == "BYE"){
            state = 0;
            commande_valide = 1;
        }

//**************************************************************************//
//                                   HELP                                   //
//**************************************************************************//

        if (input == "LOAD_help"){
            LOAD_help();
            commande_valide = 1;
        }

        if (input == "SAVE_help"){
            SAVE_help();
            commande_valide = 1;
        }

        if (input == "ADD_help"){
            ADD_help();
            commande_valide = 1;
        }

        if (input == "DELETE_help"){
            DELETE_help();
            commande_valide = 1;
        }

        if (input == "SHOW_help"){
            SHOW_help();
            commande_valide = 1;
        }

        if (input == "LIST_help"){
            LIST_help();
            commande_valide = 1;
        }

        if (input == "CLEAR_help"){
            CLEAR_help();
            commande_valide = 1;
        }

        if (input == "SEARCH_help"){
            SEARCH_help();
            commande_valide = 1;
        }

        if (input == "RENT_help"){
            RENT_help();
            commande_valide = 1;
        }

        if (input == "RETURN_help"){
            RETURN_help();
            commande_valide = 1;
        }

        if (input == "BYE_help"){
            BYE_help();
            commande_valide = 1;
        }

        if (input == "CMD_help"){
            CMD_help();
            commande_valide = 1;
        }

        if ( commande_valide == 0)
            cout << "Commande non reconnue! Verifiez la syntaxe\n" << endl;
    }

    return 0;
}