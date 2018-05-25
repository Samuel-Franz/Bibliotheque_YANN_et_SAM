#include "iostream"
#include <stdio.h>
#include <assert.h>
#include "Bibliotheque.h"
#include <vector>

using namespace std;



int main() {

    //C:\Users\mapep\OneDrive\Documents\Class\ENSEIRB\C++\Bibliotheque\exemple_mediatheque.txt

    vector<int> ids_dispo;
    Cmediatheque mediatheque; //initialisation de la structure de vecteurs que l'on nomme mediatheque
    int state = 1;
    string input;
    while(state){
		int commande_valide = 0;
        cout << "Que voulez vous faire ? : \n" << endl;
        cout << "Commandes possibles : \n" << "LOAD \n" << "BYE \n" << "SAVE \n" << "ADD\n" << "DELETE\n" << "SHOW\n" << endl;
        cin >> input;

        if (input == "LOAD"){
            cout << "Entrez le chemin et le nom du fichier source :" << endl;
            cin >> input;
            LOAD(input.c_str(), mediatheque, ids_dispo);
            cout << "\n";
			commande_valide = 1;
        }
        if (input == "SAVE"){
            cout << "Entrez le chemin et le nom du fichier de sauvegarde :" << endl;
            cin >> input;
            SAVE(input.c_str(), mediatheque, ids_dispo);
			commande_valide = 1;
        }
        if (input == "ADD"){
            cout << "Quel type de ressource voulez vous ajouter ? : " << endl;
            cin >> input;
            while ((input != "LIVRE") && (input != "REVUE") && (input != "CD") && (input != "DVD") && (input != "VHS") && (input != "RESSOURCE_NUMERIQUE")){
                cout << "Type non reconnu, veuillez ressesir le type : " << endl;
                cin >> input;
            }
            ADD(input, mediatheque,ids_dispo);
			commande_valide = 1;
        }
        if (input == "DELETE"){
            cout << "ID de la ressource a effacer ? \n" << endl;
            int id_delete;
            cin >> id_delete;
            DELETE(id_delete, mediatheque, ids_dispo);
			commande_valide = 1;
        }
        if (input == "SHOW"){
            cout << "Veuillez rentrer l'identifiant de la ressource à afficher :" << endl;
            int id_show;
            cin >> id_show;
            while ((id_show >= *ids_dispo.begin()) || (find(ids_dispo.begin()+1,ids_dispo.end(), id_show)) != ids_dispo.end() || (id_show < 1)){
                cout << "L'identifiant entre n'est pas valide, cette ressource n'existe pas, veuillez en rentrer un autre " << endl;
                cin >> id_show;
            }
            SHOW(id_show, mediatheque);
			commande_valide = 1;
        }
		if (input == "LIST") {
			LIST(mediatheque);
			commande_valide = 1;
		}
        if (input == "BYE"){
            state = 0;
			commande_valide = 1;
        }
        if ( commande_valide == 0)
            cout << "Commande non reconnue! Verifiez la syntaxe\n" << endl;
    }
    return 0;
}
