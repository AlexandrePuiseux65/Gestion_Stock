//
//  Menu.c
//  Gestion_Stock
//
//  Created by Alexandre Puiseux on 07/02/2023.
//

#include "gestion_produit.h"

FOUR menu_produit (FOUR Fourniseur)
{
    //Déclaration des variables //FOU Fourniseur[]; int nb_fourniseur
    PROD new_prod ;
    PROD prd_recherche ;
    
    int nb = 10;
    int result;
    int choix;
    int fin = 1;
    
    affiche_gestion ();
    printf("\n\n\n");
    
    Chargement();
    
    while(fin != 0)
    {
        do {
            printf("\t\nQue voulez vous faire ?\n");
            printf("\t\t 1 - Afficher la liste \n");
            printf("\t\t 2 - Trier la liste \n");
            printf("\t\t 3 - Ajouter un nouveau produit \n");
            printf("\t\t 4 - Rechercher un produit \n");
            printf("\t\t 5 - Supprimer un produit \n");
            printf("\t\t 6 - Quitter\n");
            scanf("%d", &choix);
        }while(choix <= 0 || choix >= 10 );
        
        switch(choix)
        {
            case 1 : affiche_liste_produit(Fourniseur.Produit,nb);
                break;
            case 2 : tri_liste_produit(nb, Fourniseur.Produit);
                break;
            case 3 :inserer_un_produit(nb, Fourniseur.Produit, new_prod);
                nb ++;
                break;
            case 4 : prd_recherche = saisir_produit();
                result = rechercher_produit(nb, Fourniseur.Produit, prd_recherche);
                printf("\nLe produit que vous rechercher est a la position numero : %d ", result +1);
                break;
            case 5 : nb-=supprimer_produit(nb,Fourniseur.Produit, prd_recherche);
                printf("\nVoici votre nouvelle liste :\n");
                affiche_liste_produit(Fourniseur.Produit,nb);
            case 6 : printf("Merci :)\n");
                fin = 0;
                break;
            case 7 : printf("Merci :)\n");
                fin = 0;
                break;
            default: printf("\nPas encore fait ...");
                break;
        }
        
    }
    return Fourniseur;
}

/*
 //Déclaration des variables
 PROD listeProd[MAX_SIZE_TAB_PRODUIT];
 PROD new_prod ;
 PROD prd_recherche ;
 
 int nb;
 int result;
 int choix;
 int fin = 1;
 
 affiche_gestion ();
 printf("\n\n\n");
 
 do
 {
     printf("Introduire le nombre de produit : ");
     scanf("%d",&nb);
 }
 while(nb<=0||nb>MAX_SIZE_TAB_PRODUIT);//Blindage
 
 //saisie des données
 saisir_liste_produit(nb,listeProd);
 
 Chargement();
 
 while(fin != 0)
 {
     do {
         printf("\nQue voulez vous faire ?\n");
         printf("\t 1 - Afficher la liste \n");
         printf("\t 2 - Trier la liste \n");
         printf("\t 3 - Sauvegarder la liste \n");
         printf("\t 4 - Ajouter un nouveau produit \n");
         printf("\t 5 - Rechercher un produit \n");
         printf("\t 6 - Supprimer un produit \n");
         printf("\t 7 - Quitter\n");
         scanf("%d", &choix);
     }while(choix <= 0 || choix >= 10 );
     
     switch(choix)
     {
         case 1 : affiche_liste_produit(listeProd,nb);
             break;
         case 2 : tri_liste_produit(nb, listeProd);
             break;
         case 3 : sauvegarde(listeProd, nb);
             break;
         case 4 : inserer_un_produit(nb, listeProd, new_prod);
             nb ++;
             break;
         case 5 : prd_recherche = saisir_produit();
             result = rechercher_produit(nb, listeProd, prd_recherche);
             printf("\nLe produit que vous rechercher est a la position numero : %d ", result +1);
             break;
         case 6 : nb-=supprimer_produit(nb,listeProd, prd_recherche);
             printf("\nVoici votre nouvelle liste :\n");
             affiche_liste_produit(listeProd,nb);
             break;
         case 7 : printf("Merci :)\n");
             fin = 0;
             break;
         default: printf("\nPas encore fait ...");
             break;
     }
     
 }
 */
