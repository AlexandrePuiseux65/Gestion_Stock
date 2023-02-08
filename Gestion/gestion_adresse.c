//
//  gestion_adresse.c
//  Gestion_Stock
//
//  Created by Alexandre Puiseux on 07/02/2023.
//

#include "gestion_produit.h"

ADRE saisir_adresse (void)
{
    ADRE adrestmp;
    
    printf("\t ->Numero de rue : ");
    scanf("%d", &adrestmp.Numero_rue);
    fflush(stdin);
    
    printf("\t ->Nom de rue : ");
    scanf("%s", adrestmp.nomRue);
    fflush(stdin);
    
    printf("\t ->Ville : ");
    scanf("%s", adrestmp.ville);
    fflush(stdin);
    
    printf("\t ->Code Postale : ");
    scanf("%d", &adrestmp.codePostale);
    fflush(stdin);
    
    printf("\t ->Pays : ");
    scanf("%s", adrestmp.pays);
    fflush(stdin);
    
    return adrestmp;
}

void affiche_adresse(ADRE adresse){
    printf("\n\t ->%d %s %s %d %s\n", adresse.Numero_rue,adresse.nomRue, adresse.ville, adresse.codePostale, adresse.pays );
}

