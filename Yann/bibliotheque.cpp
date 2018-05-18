#include "bibliotheque.h"

#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <string.h>
using namespace std;

//******************************Cressource*********************************************************

//Constructeurs
Cressource::Cressource(string titre,string auteur,date date_de_sortie,int ID){
    _titre = titre;
    _auteur = auteur;
    _date_de_sortie.jour = date_de_sortie.jour;
    _date_de_sortie.mois = date_de_sortie.mois;
    _date_de_sortie.annee = date_de_sortie.annee;
    _type = RESSOURCE;
    _ID = ID;
}

Cressource::Cressource(){
};

//Destructeurs
Cressource::~Cressource(){
};

//METHODES
void Cressource::affichage() {
    cout << "Titre : " << _titre << endl;
    cout << "Auteur : " << _auteur << endl;
    cout << "Date De Sortie : " << _date_de_sortie.jour << "/" << _date_de_sortie.mois << "/" <<_date_de_sortie.annee << endl;
    switch ( _type )
    {
        case LIVRE:
            cout << "Type : Livre" << endl;
            break;
        case REVUE:
            cout << "Type : Revue" << endl;
            break;
        case CD:
            cout << "Type : CD" << endl;
            break;
        case VHS:
            cout << "Type : VHS" << endl;
            break;
        case DVD:
            cout << "Type : DVD" << endl;
            break;
        case RESSOURCE:
            cout << "Type : RESSOURCE" << endl;
            break;
    }
    cout << "Identifiant : " << _ID << endl;
    cout << "Locataire : " << _locataire << endl;
    if (_locataire.compare("") == 0){
        cout << "Ressource disponible" << endl;
    }
    else{
        cout << "Periode d'emprunt : " << _periode_emprunt.debut.jour << "/" << _periode_emprunt.debut.mois << "/" << _periode_emprunt.debut.annee << " - " << _periode_emprunt.fin.jour << "/" << _periode_emprunt.fin.mois << "/" << _periode_emprunt.fin.annee << endl;
    }
}

string Cressource::get_titre(){
  return _titre;
}

string Cressource::get_auteur(){
    return _auteur;
}

date Cressource::get_date_de_sortie(){
    return _date_de_sortie;
}

TYPE Cressource::get_type(){
    return _type;
}

int Cressource::get_ID(){
    return _ID;
}

string Cressource::get_locataire(){
    return _locataire;
}

periode Cressource::get_periode_emprunt(){
    return _periode_emprunt;
}

void  Cressource::emprunt(string locataire, periode periode_emprunt){
    _locataire = locataire;
    _periode_emprunt.debut.jour  = periode_emprunt.debut.jour;
    _periode_emprunt.debut.mois  = periode_emprunt.debut.mois;
    _periode_emprunt.debut.annee = periode_emprunt.debut.annee;
    _periode_emprunt.fin.jour    = periode_emprunt.fin.jour;
    _periode_emprunt.fin.mois    = periode_emprunt.fin.mois;
    _periode_emprunt.fin.annee   = periode_emprunt.fin.annee;
}

void Cressource::remise() {
    _locataire = "";
    _periode_emprunt.debut.jour  = 0;
    _periode_emprunt.debut.mois  = 0;
    _periode_emprunt.debut.annee = 0;
    _periode_emprunt.fin.jour    = 0;
    _periode_emprunt.fin.mois    = 0;
    _periode_emprunt.fin.annee   = 0;
}

//******************************Clivre***************************************************************

//Constructeur
Clivre::Clivre(string titre, string auteur, date date_de_sortie,int ID,
  int nbr_page, string collection, string resume){

  _titre = titre;
  _auteur = auteur;
  _date_de_sortie.jour = date_de_sortie.jour;
  _date_de_sortie.mois = date_de_sortie.mois;
  _date_de_sortie.annee = date_de_sortie.annee;
  _type = LIVRE;
  _ID = ID;
  _nbr_pages  = nbr_page;
  _collection = collection;
  _resume     = resume;
}

//Clivre::affichage
