//
//  gestion_produit.h
//  Gestion_Stock
//
//  Created by Alexandre Puiseux on 10/01/2023.
//

#ifndef GESTION_PRODUIT_H_INCLUDED
#define GESTION_PRODUIT_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SIZE_TAB_PRODUIT 100
#define MAX_NB_PRODUIT 10

//Différente structure que on utilise :
struct Date{
    int jour;
    int mois;
    int annee;
};typedef struct Date DATE;

struct Detail_produit{
    int code;
    float prix_TVA;
    float QteStq;
    DATE Date_limite_Data;
};typedef struct Detail_produit DET_PROD;

struct Produit{
    char nom[40];
    char designation[60];
    float prix;
    DET_PROD detaille_produit;
};typedef struct Produit PROD;

struct Adresse{
    int Numero_rue;
    char nomRue [30];
    char ville [30];
    int codePostale;
    char pays [30];
};typedef struct Adresse ADRE;

struct Fournisseur{
    int code;
    ADRE Adresse_fourniseur;
    long telephone;
    PROD Produit[10];
};typedef struct Fournisseur FOUR;



//Mettre les diffÈrentes fonctions de gestion produit

//Code de Tri Produit
void tri_liste_produit(int nb, PROD* listeProduit);
void permutation (PROD* listeProduit, PROD prdTmp, int i, int posimax);

//Code de Tri founiseur
void tri_liste_fourniseur(int nb, FOUR* listeFouniseur);

//Code pour fichier et la sauvegarde des produit
void sauvegarde(FOUR* listFournisseur, int nb );
FOUR ouverture(FOUR* listFournisseur, int nb);

//Code Bonnus
void Chargement(void);
void affiche_gestion (void);
void affiche_gestion_Fourniseur (void);

//Code produit
PROD saisir_produit(void); // fonction de saisie de produit
void saisir_liste_produit(int nb, PROD * listeProd); //fonction saisie de liste produit
void affiche_produit(PROD prd); //fonction d'affichage de produit
void affiche_liste_produit(PROD* listeProd, int nb); //fonction d'affichage de produit
void inserer_un_produit(int nb,PROD* listeProduit, PROD new_prod);
int rechercher_produit(int nb, PROD*listProduit, PROD prd_recheche );//rechercher un produit dans une liste de produit
int supprimer_produit(int nb, PROD*listProduit, PROD prd_recheche );
void copieProd(PROD prdSource, PROD*prDdestination);

//Code adresse
ADRE saisir_adresse (void);
void affiche_adresse(ADRE adresse);

//Code Date
DATE saisir_date (void);
void affiche_date(DATE datetmp);

//Code Fourniseur
int rechercher_fourniseur(int nb, FOUR * Fourniseur , FOUR four_recheche );
void affiche_fourniseur(FOUR Fourniseur);
void affiche_liste_fourniseur(FOUR* listeFourniseur, int nb);
FOUR saisir_fourniseur(void);
void saisir_liste_fourniseur(int nb, FOUR * listeFourniseur);
void inserer_fourniseur(int nb,FOUR* listeFourniseur, FOUR new_Fourniseur);
void copieFour(FOUR fourSource, FOUR*fourDdestination);
int supprimer_fourniseur(int nb, FOUR*listFourniseur, FOUR four_recheche );

//Menu
FOUR menu_produit (FOUR Fourniseur);



#endif // GESTION_PRODUIT_H_INCLUDED
