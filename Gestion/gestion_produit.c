//
//  gestion_produit.c
//  Gestion_Stock
//
//  Created by Alexandre Puiseux on 10/01/2023.
//
#include "gestion_produit.h"

/*Fonction d'affichage de produit
*/
void affiche_produit(PROD prd){
    printf("\t\t• %s | %s | %f | %d | %f %%| %f | %d /%d /%d | \n",prd.nom, prd.designation, prd.prix, prd.detaille_produit.code, prd.detaille_produit.prix_TVA, prd.detaille_produit.QteStq, prd.detaille_produit.Date_limite_Data.jour, prd.detaille_produit.Date_limite_Data.mois, prd.detaille_produit.Date_limite_Data.annee);
}
/*
Fonction d'affichage d'une liste de produit de taille nb
Cette fonction affiche ‡ partir d'un tableau de produit "listeProd"
PassÈ en argument de la fonction
le type de retour est vide (void)
*/

void affiche_liste_produit(PROD* listeProd, int nb){
    int i;
    for(i =0; i< nb;i++ ){
        affiche_produit(listeProd[i]);
    }
}
 /* Fonction de saisie de produit
    Elle saisie un produit temporaire et le retourne ‡ la fin de la saisie
 */
PROD saisir_produit(void){
    PROD prdtmp;
    printf("Introduire le nom : ");
    scanf("%s",prdtmp.nom);
    //prdtmp.nom[39] = '\0';
    fflush(stdin);
    printf("Introduire la designation : ");
    scanf("%s",prdtmp.designation);
    //prdtmp.nom[59] = '\0';
    fflush(stdin);
    printf("Introduire le prix : ");
    scanf("%f",&prdtmp.prix);
    
    fflush(stdin);
    printf("Introduire le code du produit : ");
    scanf("%d", &prdtmp.detaille_produit.code);
    
    fflush(stdin);
    printf("Introduire le taux TVA : ");
    scanf("%f", &prdtmp.detaille_produit.prix_TVA);
    
    fflush(stdin);
    printf("Introduire la quantite de ce produit (Nombre d unite) : ");
    scanf("%f", &prdtmp.detaille_produit.QteStq);
    
    fflush(stdin);
    printf("Introduire la date : \n");
    prdtmp.detaille_produit.Date_limite_Data = saisir_date ();

    return prdtmp;
}

/*
Fonction de saisie d'une liste de produit de taille nb
*/

void saisir_liste_produit(int nb, PROD * listeProd){
    int i;
    for(i=0; i< nb;i++){
        listeProd[i] = saisir_produit();
    }
}


void inserer_un_produit(int nb,PROD* listeProduit, PROD new_prod)
{
    int i = 0;
    int position = 1;
    
    printf("Veuillez rentrer les informations concernant le nouveau produit \n");
    new_prod = saisir_produit();
    
    for(i = nb; i >= position; i-- )
    {
        listeProduit[i] = listeProduit [i-1];
    }
    listeProduit[position - 1] = new_prod;
    nb = nb + 1 ;
    
    printf("\nAffichage avec ajout : \n");
    affiche_liste_produit(listeProduit,nb);
    //Sauvegarde à ajouter
}

int rechercher_produit(int nb, PROD*listProduit, PROD prd_recheche )
{
    int i = 0;
    int result = -1;
    
    
    while((i < nb && strcmp(prd_recheche.nom, listProduit[i].nom) != 0 ))
    {
        i++;
    }
    
    if (i < nb)
    {
        result = i;
    }
    return result;
}


int supprimer_produit(int nb, PROD*listProduit, PROD prd_recheche )
{
    int i = 0;
    int result = 0;
    int posi = rechercher_produit(nb, listProduit, prd_recheche);
    
    if(posi!=-1){
        for(i = posi; i<0; i--)
        {
            copieProd(listProduit[i],&listProduit[i-1]);
        }
        nb = nb - 1;
        result = 1;
//        printf("\n Voici la liste actuelle : \n");
//        affiche_liste_produit(listProduit,nb);
    }
    
    return result;
}

