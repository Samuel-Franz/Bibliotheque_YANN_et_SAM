#ifndef BIBLIOTHEQUE_BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_BIBLIOTHEQUE_H
#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

enum TYPE{LIVRE,REVUE,CD,VHS,DVD,RESSOURCE};

typedef struct date {
    int jour;
    int mois;
    int annee;
} date;

typedef struct periode {
  date debut;
  date fin;
} periode;

//******************************Cressource*********************************************************

class Cressource{
protected:
    //Attributs
    string _titre;
    string _auteur;
    date    _date_de_sortie;
    TYPE   _type;
    int    _ID;
    string _locataire;
    periode _periode_emprunt;

public:
    //Methodes
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
};

//******************************Clivre***************************************************************

class Clivre : public Cressource{
protected:
  int    _nbr_pages;
  string _collection;
  string _resume;

public:
  Clivre(string titre, string auteur, date date_de_sortie,int ID, int nbr_page, string collection, string resume);
  int    get_nbr_pages();
  string get_collection();
  string get_resume();
  void   affichage();
};

//******************************************Crevue******************************************************
class Crevue : public Clivre{
protected:
  string  _editeur;
  int     _nbr_articles;
  string _nom_articles;

public:
  Crevue(string titre,string auteur,date date_de_sortie,int ID,int nbr_page, string collection, string resume, string editeur, int nbr_articles, string nom_articles);
  string  get_editeur();
  int     get_nbr_articles();
  string get_nom_articles();

};

#endif //BIBLIOTHEQUE_BIBLIOTHEQUE_H
