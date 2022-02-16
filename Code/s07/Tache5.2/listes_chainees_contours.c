#include "listes_chainees_contours.h"


Cellule_Liste_Contour *creer_element_liste_Contour(Contour v)
{
    Cellule_Liste_Contour *el ;
    el = (Cellule_Liste_Contour *)malloc(sizeof(Cellule_Liste_Contour )); 
    if (el==NULL){
        fprintf (stderr , "creer_element_liste_Contour : allocation impossible\n");
        exit (-1); 
    }
    el->contour = v; 
    el->suiv = NULL; 
    return el ;
}


Liste_Contour creer_liste_Contour_vide()
{
    Liste_Contour L = {0, NULL, NULL}; 
    return L ;
}

Liste_Contour ajouter_element_liste_Contour(Liste_Contour L, Contour e)
{
    Cellule_Liste_Contour *el;
    el = creer_element_liste_Contour(e); 
    if (L.nb_contour == 0)
    {
        L.first = L.last = el;
    }
    else
    {
        L.last->suiv = el; L.last = el;
    }
    L.nb_contour++;
    return L ; 
}

Liste_Contour supprimer_liste_Contour(Liste_Contour L)
{
    Cellule_Liste_Contour *el=L.first ;
    while (el){
        Cellule_Liste_Contour *suiv = el->suiv;
        free(el);
        el=suiv;
    }

    L.first =L.last =NULL; 
    L.nb_contour = 0;
    return L ;
}

Liste_Contour concatener_liste_Contour(Liste_Contour L1, Liste_Contour L2)
{

    if (L1.nb_contour == 0) return L2; 
    if (L2.nb_contour == 0) return L1;
    L1.last->suiv = L2.first ;
    L1.last = L2.last ;  
    L1.nb_contour += L2.nb_contour ; 
    return L1;
}


int taille_liste_contours (Liste_Contour L){
    return L.nb_contour;
}