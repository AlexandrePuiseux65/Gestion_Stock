//
//  Fichier_sauvegarde.c
//  Gestion_Stock
//
//  Created by Alexandre Puiseux on 16/01/2023.
//


#include "gestion_produit.h"


void sauvegarde(FOUR* listFournisseur, int nb)
{
    // Création et ouverture d'un fichier
    int i;
    int j;
    FILE* sauvegarde = NULL;
    sauvegarde = fopen("ListedesFournisseurs.txt", "w+");
    if(sauvegarde == NULL)
    {
        printf("ERREUR DANS LE FICHIER DE SAUVEGARDE");
        exit(1);
    }
    else
    {
        for(i=0; i<nb; i++)
        {
            //
            fprintf(sauvegarde," - Code Fournisseur %d\n",listFournisseur[i].code);
            fprintf(sauvegarde," - Telephone : (+33)%ld",listFournisseur[i].telephone);
            fprintf(sauvegarde,"\n - Adresse :%d Rue %s %s %d %s :\n",listFournisseur[i].Adresse_fourniseur.Numero_rue,listFournisseur[i].Adresse_fourniseur.nomRue,listFournisseur[i].Adresse_fourniseur.ville,listFournisseur[i].Adresse_fourniseur.codePostale,listFournisseur[i].Adresse_fourniseur.pays);
                
            for(j=0; j<10; j++)
            {
                fprintf(sauvegarde," - %s | %s | %f\n",listFournisseur[i].Produit[j].nom,listFournisseur[i].Produit[j].designation,listFournisseur[i].Produit[j].prix );
                fprintf(sauvegarde,"\t -> Code : %d\n",listFournisseur[i].Produit[j].detaille_produit.code);
                fprintf(sauvegarde,"\t -> TVA : %f %%\n",listFournisseur[i].Produit[j].detaille_produit.prix_TVA);
                fprintf(sauvegarde,"\t -> Quantitee : %f\n",listFournisseur[i].Produit[j].detaille_produit.QteStq);
                fprintf(sauvegarde,"\t -> Date Limite %d/ %d/ %d \n",listFournisseur[i].Produit[j].detaille_produit.Date_limite_Data.jour,listFournisseur[i].Produit[j].detaille_produit.Date_limite_Data.mois,listFournisseur[i].Produit[j].detaille_produit.Date_limite_Data.annee);
            }
        if (fgetc(sauvegarde)=='EOF')
        {
            printf("Fin de fichier\n");
        }
        }
    }
    
    fclose(sauvegarde);
}

FOUR ouverture(FOUR* listFournisseur, int nb)
{
    int i;
    int j;
    FOUR new_fou [nb];
    FILE* sauvegarde = NULL;
    sauvegarde = fopen("ListedesFournisseurs.txt", "r");
    if(sauvegarde == NULL)
    {
        printf("ERREUR DANS LE FICHIER DE SAUVEGARDE");
        exit(1);
    }
    else
    {
        for(i=0; i<nb; i++)
        {
            //
            fscanf(sauvegarde," - Code Fournisseur %d\n",&listFournisseur[i].code);
            fscanf(sauvegarde," - Telephone : (+33)%ld",&listFournisseur[i].telephone);
            fscanf(sauvegarde,"\n - Adresse :%d Rue %s %s %d %s :\n",&listFournisseur[i].Adresse_fourniseur.Numero_rue,listFournisseur[i].Adresse_fourniseur.nomRue,listFournisseur[i].Adresse_fourniseur.ville,&listFournisseur[i].Adresse_fourniseur.codePostale,listFournisseur[i].Adresse_fourniseur.pays);
                
            for(j=0; j<10; j++)
            {
                fscanf(sauvegarde," - %s | %s | %f\n",listFournisseur[i].Produit[j].nom,listFournisseur[i].Produit[j].designation,&listFournisseur[i].Produit[j].prix );
                fscanf(sauvegarde,"\t -> Code : %d\n",&listFournisseur[i].Produit[j].detaille_produit.code);
                fscanf(sauvegarde,"\t -> TVA : %f %%\n",&listFournisseur[i].Produit[j].detaille_produit.prix_TVA);
                fscanf(sauvegarde,"\t -> Quantitee : %f\n",&listFournisseur[i].Produit[j].detaille_produit.QteStq);
                fscanf(sauvegarde,"\t -> Date Limite %d/ %d/ %d \n",&listFournisseur[i].Produit[j].detaille_produit.Date_limite_Data.jour,&listFournisseur[i].Produit[j].detaille_produit.Date_limite_Data.mois,&listFournisseur[i].Produit[j].detaille_produit.Date_limite_Data.annee);
            }
            copieFour(listFournisseur[i], &new_fou[i]);
        
        if (fgetc(sauvegarde)=='EOF'){
            printf("Fin de fichier\n");
        }
            
        }
    }
    
    fclose(sauvegarde);
    return *new_fou;
}

