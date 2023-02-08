//
//  gestion_fourniseur.c
//  Gestion_Stock
//
//  Created by Alexandre Puiseux on 07/02/2023.
//

#include "gestion_produit.h"

int rechercher_fourniseur(int nb, FOUR * Fourniseur , FOUR four_recheche )
{
    int i = 0;
    int result = -1;
    
    
    while(i < nb && (four_recheche.code =! Fourniseur[i].code) )
    {
        i++;
    }
    
    if (i < nb)
    {
        result = i;
    }
    return result;
}

void affiche_fourniseur(FOUR Fourniseur){
    printf("\t - Code Founiseur : %d", Fourniseur.code);
    affiche_adresse(Fourniseur.Adresse_fourniseur);
    printf("\t - Numero de telephone : (+33)%ld\n", Fourniseur.telephone);
    printf("\t - Liste des produits du Fourniseru %d :\n", Fourniseur.code);
    affiche_liste_produit(Fourniseur.Produit, MAX_NB_PRODUIT);
}

/*
Fonction d'affichage d'une liste de produit de taille nb
Cette fonction affiche ‡ partir d'un tableau de produit "listeProd"
PassÈ en argument de la fonction
le type de retour est vide (void)
*/

void affiche_liste_fourniseur(FOUR* listeFourniseur, int nb){
    int i;
    for(i =0; i< nb;i++ ){
        affiche_fourniseur(listeFourniseur[i]);
    }
}
 /* Fonction de saisie de produit
    Elle saisie un produit temporaire et le retourne ‡ la fin de la saisie
 */
FOUR saisir_fourniseur(void){
    FOUR fourtmp;
    
    int i;
    int nb;
    
    printf("Code fourniseur : ");// Demande du code fourniseur
    scanf("%d", &fourtmp.code);
    fflush(stdin);
    
    printf("Adresse : \n");//demande de l'adresse
    fourtmp.Adresse_fourniseur = saisir_adresse();
    
    printf("Telephone : ");// Demande du telephone
    scanf("%ld", &fourtmp.telephone);
    fflush(stdin);
    
    printf("Combien de produit a t il ? \n");
    scanf("%d", &nb);
    
    for(i = 0; i<nb ; i++)// Demande des porduits
    {
        fourtmp.Produit[i] = saisir_produit();
    }

    return fourtmp;// Retoune de nouveau fourniseur enregistrer
}

/*
Fonction de saisie d'une liste de produit de taille nb
*/

void saisir_liste_fourniseur(int nb, FOUR * listeFourniseur){
    int i;
    for(i=0; i< nb;i++){
        listeFourniseur[i] = saisir_fourniseur(); // afecte la saisie d'un fourniseur à tous les fournsieurs
    }
}


void inserer_fourniseur(int nb,FOUR* listeFourniseur, FOUR new_Fourniseur)
{
    int i = 0;
    int position = 1;
    
    printf("Veuillez rentrer les informations concernant le nouveau Fourniseur \n");
    new_Fourniseur = saisir_fourniseur();
    
    for(i = nb; i >= position; i-- )
    {
        listeFourniseur[i] = listeFourniseur [i-1];
    }
    listeFourniseur[position - 1] = new_Fourniseur;
    nb = nb + 1 ;
    
    printf("\nAffichage avec ajout : \n");
    affiche_liste_fourniseur(listeFourniseur, nb);
    //Sauvegarde à ajouter
}


int supprimer_fourniseur(int nb, FOUR*listFourniseur, FOUR four_recheche )
{
    int i = 0;
    int result = 0;
    int posi = rechercher_fourniseur(nb, listFourniseur, four_recheche);
    
    if(posi!=-1){
        for(i = posi; i<0; i--)
        {
            copieFour(listFourniseur[i], &listFourniseur[i-1]);
        }
        nb = nb - 1;
        result = 1;
    }
    
    return result;
}

