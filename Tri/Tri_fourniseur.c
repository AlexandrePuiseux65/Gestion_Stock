//
//  Tri_fourniseur.c
//  Gestion_Stock
//
//  Created by Alexandre Puiseux on 08/02/2023.
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
void tri_liste_fourniseur(int nb, FOUR* listeFouniseur)
{
    FOUR fourTmp;// Structure Tampon
    
    //Increment
    int i = 0;
    int j = 0;
    int posimax = 0;
    
    // Facteur de comparaison pour deux chaine de caratère

    for(i = 0; i<nb; i++)
    {
        for(j = i+1 , posimax = i; j < nb; j++)
        {
            if(listeFouniseur[posimax].code < listeFouniseur[j].code)
            {
                posimax = j;
            }
        }
        //Permutation des valeurs
        if(posimax != i)
        {
            copieFour(listeFouniseur[i], &fourTmp);
            copieFour(listeFouniseur[posimax], &listeFouniseur[i]);
            copieFour(fourTmp, &listeFouniseur[posimax]);
        }
    }
    
    affiche_liste_fourniseur(listeFouniseur, nb);

}
/*
 Code qui permet de copier les information d'un fourniseur dans un autre fourniseur source
 */
void copieFour(FOUR fourSource, FOUR*fourDdestination)
{
    int i ;
    
    fourDdestination->code = fourSource.code;
    fourDdestination->telephone = fourSource.telephone;
    fourDdestination->Adresse_fourniseur = fourSource.Adresse_fourniseur;
    
    for(i = 0; i>MAX_NB_PRODUIT; i++)
    {
        fourDdestination->Produit[i] = fourSource.Produit[i];
    }

}


