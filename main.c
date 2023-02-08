//
//  main.c
//  Gestion_Stock
//
//  Created by Alexandre Puiseux on 10/01/2023.
//
#include "gestion_produit.h"

int main()
{
    //Déclaration des variables
    FOUR Fourniseur [MAX_SIZE_TAB_PRODUIT];
    FOUR new_Fourniseur;
    
    int nb = 0;
    int result;
    int choix;
    int fin = 1;
    int i;
    
    affiche_gestion_Fourniseur ();
    printf("\n\n\n");
    do{
        printf("Nombre de fournisseur a ajoutez : ");
        scanf("%d", &nb);
        
    }while(nb < 0 || nb  >MAX_SIZE_TAB_PRODUIT);
    
    saisir_liste_fourniseur(nb, Fourniseur);
    
    Chargement();
    
    while(fin != 0)
    {
        do {
            printf("\nQue voulez vous faire ?\n");
            printf("\t 1 - Afficher la liste des fournisseurs \n");
            printf("\t 2 - Trier la liste des fournisseurs \n");
            printf("\t 3 - Sauvegarder la nouvelle liste des fournisseurs \n");
            printf("\t 4 - Ajouter un nouveau fournisseur \n");
            printf("\t 5 - Rechercher un fournisseur \n");
            printf("\t 6 - Supprimer un fournisseur \n");
            printf("\t 7 - Afficher les produits d'un fournisseur \n");
            printf("\t 8 - Afficher la liste des Fournisseurs sauvegarder \n");
            printf("\t 9 - Quitter\n");
            scanf("%d", &choix);
        }while(choix <= 0 || choix >= 10 );
        
        switch(choix)
        {
            case 1 : affiche_liste_fourniseur(Fourniseur, nb);
                break;
            case 2 :tri_liste_fourniseur(nb, Fourniseur);
                break;
            case 3 :sauvegarde(Fourniseur, nb);
                break;
            case 4 :inserer_fourniseur(nb,Fourniseur,new_Fourniseur);
                nb ++;
                break;
            case 5 :
                printf("Code du fournisseur rechercher : ");
                scanf("%d", &new_Fourniseur.code);
                result = rechercher_fourniseur(nb, Fourniseur, new_Fourniseur);
                printf("\nLe Fournisseur que vous rechercher est a la position numero : %d \n", result +1);
                affiche_fourniseur(Fourniseur[result]);
                break;
            case 6 :nb-=supprimer_fourniseur(nb, Fourniseur, new_Fourniseur);
                printf("\nVoici votre nouvelle liste :\n");
                affiche_liste_fourniseur(Fourniseur, nb);
                break;
            case 7 :printf("Entre le code du Fournisseur : ");
                scanf("%d", &new_Fourniseur.code);
                result = rechercher_fourniseur(nb, Fourniseur, new_Fourniseur);
                Fourniseur[result] = menu_produit(Fourniseur[result]);
                break;
            case 8 :
                for(i=0; i<nb; i++)
                {
                    Fourniseur[i] = ouverture(Fourniseur, nb);
                }
                affiche_liste_fourniseur(Fourniseur, nb);
                break;
            case 9:printf("Merci :)\n");
                fin = 0;
                break;
            default: printf("\nPas encore fait ...");
                break;
        }
        
    }
    return 0;
}
