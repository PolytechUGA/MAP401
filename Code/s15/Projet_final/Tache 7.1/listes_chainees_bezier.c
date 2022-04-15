#include "listes_chainees_bezier.h"


Cellule_Liste_Bezier3 *creer_element_liste_Bezier3(Bezier3 v)
{
    Cellule_Liste_Bezier3 *el ;
    el = (Cellule_Liste_Bezier3 *)malloc(sizeof(Cellule_Liste_Bezier3 )); 
    if (el==NULL){
        fprintf (stderr , "creer_element_liste_Bezier3 : allocation impossible\n");
        exit (-1); 
    }
    el->B = v; 
    el->suiv = NULL; 
    return el ;
}


Liste_Bezier3 creer_liste_Bezier3_vide()
{
    Liste_Bezier3 L = {0, NULL, NULL}; 
    return L ;
}

Liste_Bezier3 ajouter_element_liste_Bezier3(Liste_Bezier3 L, Bezier3 e)
{
    Cellule_Liste_Bezier3 *el;
    el = creer_element_liste_Bezier3(e); 
    if (L.nb_Bezier3 == 0)
    {
        L.first = L.last = el;
    }
    else
    {
        L.last->suiv = el; L.last = el;
    }
    L.nb_Bezier3++;
    return L ; 
}

Liste_Bezier3 supprimer_liste_Bezier3(Liste_Bezier3 L)
{
    Cellule_Liste_Bezier3 *el=L.first ;
    while (el){
        Cellule_Liste_Bezier3 *suiv = el->suiv;
        free(el);
        el=suiv;
    }

    L.first =L.last =NULL; 
    L.nb_Bezier3 = 0;
    return L ;
}

Liste_Bezier3 concatener_liste_Bezier3(Liste_Bezier3 L1, Liste_Bezier3 L2)
{

    if (L1.nb_Bezier3 == 0) return L2; 
    if (L2.nb_Bezier3 == 0) return L1;
    L1.last->suiv = L2.first ;
    L1.last = L2.last ;  
    L1.nb_Bezier3 += L2.nb_Bezier3 ; 
    return L1;
}


int taille_liste_Bezier3 (Liste_Bezier3 L){
    return L.nb_Bezier3;
}