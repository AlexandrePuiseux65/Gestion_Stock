//
//  Fichier_sauvegarde.c
//  Gestion_Stock
//
//  Created by Alexandre Puiseux on 16/01/2023.
//

#include "gestion_produit.h"

void sauvegarde(PROD* listProduit, int nb)
{
    int i = 0;
    // Création et ouverture d'un fichier
    FILE* sauvegarde = NULL;
    sauvegarde = fopen("sauvegarde.txt", "a+");

    if(sauvegarde == NULL)
    {
        printf("ERREUR DANS LE FICHIER DE SAUVEGARDE");
        system("cls");
    }
    else
    {
        while(!feof(sauvegarde))
        {
            
        }
    }
    
    fclose(sauvegarde);
}
