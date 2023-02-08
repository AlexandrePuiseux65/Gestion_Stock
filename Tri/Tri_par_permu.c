//
//  Tri_par_permu.c
//  Gestion_Stock
//
//  Created by Alexandre Puiseux on 15/01/2023.
//

#include "gestion_produit.h"

/*
 Fonction de tri de liste produit
Cette fonction demande ‡ l'utilisateur le choix du type du tri
1 - tri par nom
2 - tri par prix
Elle prend en argument un nombre de produit ainsi que la liste de ces produits
Le tri s'effectue sur le tableau listeProduit
*/
void tri_liste_produit(int nb, PROD* listeProduit)
{
    PROD prdTmp;// Structure Tampon
    
    int choix;// Choix du tri
    
    //Increment
    int i = 0;
    int j = 0;
    int posimax = 0;
    
    // Facteur de comparaison pour deux chaine de caratère
    int cmp = 0;
    
    do{
        printf("\nQuelle sera votre facteur de tri ? (Choix 1 : Prix / Choix 2 : Nom) => ");
        scanf("%d", &choix);
    }while(choix < 1 || choix >2);//Demande du choix de la manière de tri avec un blindage
    
    if(choix == 1 )
    {
        for(i = 0; i<nb; i++)
        {
            for(j = i+1 , posimax = i; j < nb; j++)
            {
                if(listeProduit[posimax].prix < listeProduit[j].prix)
                {
                    posimax = j;
                }
            }
            //Permutation des valeurs
            if(posimax != i)
            {
                /*
                prdTmp.prix = listeProduit[i].prix;
                listeProduit[i].prix = listeProduit[posimax].prix;
                listeProduit[posimax].prix = prdTmp.prix;
                 */
                copieProd(listeProduit[i],&prdTmp);
                copieProd(listeProduit[posimax],&listeProduit[i]);
                copieProd(prdTmp,&listeProduit[posimax]);
            }
        }
    }else
    {
        for(i = 0; i<nb; i++)
        {
            for(j = i+1 , posimax = i; j < nb; j++)
            {
                cmp = strcmp(listeProduit[posimax].nom, listeProduit[j].nom);
                if(cmp > 0)
                {
                    posimax = j;
                }
            }
            //Permutation des valeurs
            if(posimax != i)
            {
                copieProd(listeProduit[i],&prdTmp);
                copieProd(listeProduit[posimax],&listeProduit[i]);
                copieProd(prdTmp,&listeProduit[posimax]);
            }
        }
    }
    
    affiche_liste_produit(listeProduit, nb);

}
/*
 Code qui permet de copier une chaine de caratère dans une autre chaine de caractère
 */
void copieProd(PROD prdSource, PROD*prDdestination)
{
    strcpy(prDdestination->designation, prdSource.designation);
    strcpy(prDdestination->nom, prdSource.nom);
    prDdestination->prix = prdSource.prix;
    prDdestination->detaille_produit.code = prdSource.detaille_produit.code;
    prDdestination->detaille_produit.QteStq = prdSource.detaille_produit.QteStq;
    prDdestination->detaille_produit.prix_TVA = prdSource.detaille_produit.prix_TVA;
    prDdestination->detaille_produit.Date_limite_Data.jour = prdSource.detaille_produit.Date_limite_Data.jour;
    prDdestination->detaille_produit.Date_limite_Data.mois = prdSource.detaille_produit.Date_limite_Data.mois;
    prDdestination->detaille_produit.Date_limite_Data.annee = prdSource.detaille_produit.Date_limite_Data.annee;
}

/*
 Code qui fais la permutation de deux prix
 */
void permutation (PROD* listeProduit, PROD prdTmp, int i, int posimax)
{
    prdTmp.prix = listeProduit[i].prix;
    listeProduit[i].prix = listeProduit[posimax].prix;
    listeProduit[posimax].prix = prdTmp.prix;
}
