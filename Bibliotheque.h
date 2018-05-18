#ifndef BIBLIOTHEQUE_BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_BIBLIOTHEQUE_H
#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

enum TYPE{LIVRE,REVUE,CD,VHS,DVD,RESSOURCE,RESSOURCE_NUMERIQUE};


typedef struct date {
    int jour;
    int mois;
    int annee;
} date;

typedef struct periode {
    date debut;
    date fin;
} periode;

//******************************Cressource***********************************//

class Cressource{
protected:
    //Attributs
    string _titre;
    string _auteur;
    date   _date_de_sortie;
    TYPE   _type;
    int    _ID;
    string _locataire;
    periode _periode_emprunt;

public:
    //Methodes
    Cressource(ifstream& Lfichier, string Lbuff, vector<int> &Lids);
    Cressource(string titre,string auteur,date date_de_sortie,int ID);
    Cressource();
    ~Cressource();
    void   emprunt(string locataire, periode periode_emprunt);
    void   remise();
    void   affichage();
    string get_titre();
    string get_auteur();
    date get_date_de_sortie();
    TYPE   get_type();
    int    get_ID();
    string get_locataire();
    periode get_periode_emprunt();
    void from_file(ifstream& Lfichier, string Lbuff, vector<int> &Lids);
    void save_to_file(const char* Lnomfichier);
};

//********************************Clivre*************************************//

class Clivre : public Cressource{
protected:
    int    _nbr_pages;
    string _collection;
    string _resume;

public:
    Clivre(ifstream& Lfichier, string Lbuff, vector<int> &Lids);
    Clivre(string titre, string auteur, date date_de_sortie,int ID, int nbr_page, string collection, string resume);
    Clivre();
    ~Clivre();
    int    get_nbr_pages();
    string get_collection();
    string get_resume();
    void   affichage();
    void from_file(ifstream& Lfichier,string Lbuff, vector<int> &Lids);
    void save_to_file(const char* Lnomfichier);
};

//********************************Crevue*************************************//

class Crevue : public Clivre{
protected:
    string  _editeur;
    int     _nbr_articles;
    string _nom_articles;

public:
    Crevue(ifstream& Lfichier, string Lbuff, vector<int> &Lids);
    Crevue(string titre,string auteur,date date_de_sortie,int ID,int nbr_page, string collection, string resume, string editeur, int nbr_articles, string nom_articles);
    Crevue();
    ~Crevue();
    string  get_editeur();
    int     get_nbr_articles();
    string get_nom_articles();
    void   affichage();
    void from_file(ifstream& Lfichier, string Lbuff, vector<int> &Lids);
    void save_to_file(const char* Lnomfichier);

};

//*********************************Ccd***************************************//

class Ccd : public Cressource{
protected:
    int _duree;
    int _nbr_pistes;
    string _maison_de_production;

public:
    //Methode
    Ccd();
    Ccd(ifstream& Lfichier, string Lbuff, vector<int> &Lids);
    Ccd(string titre,string auteur,date date_de_sortie,int ID, int duree, int nbr_pistes,
        string maison_de_production);
    ~Ccd();
    void affichage();
    int get_duree();
    string get_maison_de_producton();
    int get_nbr_pistes();
    void from_file(ifstream& Lfichier, string Lbuff, vector<int> &Lids);
    void save_to_file(const char* Lnomfichier);
};

//*********************************Cvhs**************************************//

class Cvhs : public Cressource{
    //Attributs
protected:
    int _duree;
    string _maison_de_production;

    //Methode
public:
    Cvhs();
    Cvhs(ifstream& Lfichier, string Lbuff, vector<int> &Lids);
    Cvhs(string titre,string auteur,date date_de_sortie,int ID, int duree, string maison_de_production);
    ~Cvhs();
    void affichage();
    int get_duree();
    string get_maison_de_producton();
    void from_file(ifstream& Lfichier, string Lbuff, vector<int> &Lids);
    void save_to_file(const char* Lnomfichier);

};

//*********************************Cdvd**************************************//

class Cdvd : public Cressource{
    //Attributs
protected:
    int _duree;
    string _maison_de_production;
    int _nbr_chapitres;

public:
    //Methode
    Cdvd();
    Cdvd(ifstream& Lfichier, string Lbuff, vector<int> &Lids);
    Cdvd(string titre,string auteur,date date_de_sortie,int ID, int duree, string maison_de_production, int nbr_chapitres);
    ~Cdvd();
    void affichage();
    int get_duree();
    string get_maison_de_producton();
    int get_nbr_chapitres();
    void from_file(ifstream& Lfichier, string Lbuff, vector<int> &Lids);
    void save_to_file(const char* Lnomfichier);

};

//***************************Cressource_numerique****************************//

class Cressource_numerique : public Cressource{
    //Attributs
protected:
    int _taille;
    string _chemin_acces;
    string _format;

public:
    //Methodeh
    Cressource_numerique();
    Cressource_numerique(ifstream& Lfichier, string Lbuff, vector<int> &Lids);
    Cressource_numerique(string titre,string auteur,date date_de_sortie,int ID, int taille, string chemin_acces, string format);
    ~Cressource_numerique();
    void affichage();
    int get_taille();
    string get_format();
    string get_chemin_acces();
    void from_file(ifstream& Lfichier, string Lbuff, vector<int> &Lids);
    void save_to_file(const char* Lnomfichier);

};


class Cmediatheque{
public:
    vector<Clivre*> livres;
    vector<Crevue*> revues;
    vector<Ccd*> cds;
    vector<Cdvd*> dvds;
    vector<Cvhs*> vhs;
    vector<Cressource_numerique*> ressources_numeriques;
};

void LOAD(const char* Lnomfichier, Cmediatheque &Lmediatheque, vector<int> &Lids, vector<int> &Lids_dispo);

void LoadMediatheque2(const char* Lnomfichier, vector<Clivre*> &Llivres, vector<Crevue*> &Lrevues, vector<Ccd*> &Lcds, vector<Cdvd*> &Ldvds, vector<Cvhs*> &Lvhs,
                      vector<Cressource_numerique*> &Lressources_numerique);

void LoadMediatheque3(const char* Lnomfichier, vector<Clivre*> &Llivres, vector<Crevue*> &Lrevues, vector<Ccd*> &Lcds, vector<Cdvd*> &Ldvds, vector<Cvhs*> &Lvhs,
                      vector<Cressource_numerique*> &Lressources_numeriques);

void SAVE(const char* Lnomfichier, Cmediatheque &Lmediatheque, vector<int> &Lids_dispo);

void ADD(Cmediatheque &Lmediatheque, vector<int> &Lids, vector<int> &Lids_dispo);

#endif //BIBLIOTHEQUE_BIBLIOTHEQUE_H

