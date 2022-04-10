#include "liste_contour_bezier.h"


Cellule_Liste_Contour_bezier *creer_element_liste_Contour_bezier( Liste_Bezier3 v)
{
    Cellule_Liste_Contour_bezier *el ;
    el = (Cellule_Liste_Contour_bezier *)malloc(sizeof(Cellule_Liste_Contour_bezier )); 
    if (el==NULL){
        fprintf (stderr , "creer_element_liste_Contour : allocation impossible\n");
        exit (-1); 
    }
    el->contour_bezier = v; 
    el->suiv = NULL; 
    return el ;
}


Liste_Contour_bezier creer_liste_Contour_bezier_vide()
{
    Liste_Contour_bezier L = {0, NULL, NULL}; 
    return L ;
}

Liste_Contour_bezier ajouter_element_liste_Contour_bezier(Liste_Contour_bezier L, Liste_Bezier3 e)
{
    Cellule_Liste_Contour_bezier *el;
    el = creer_element_liste_Contour_bezier(e); 
    if (L.nb_contour_bezier == 0)
    {
        L.first = L.last = el;
    }
    else
    {
        L.last->suiv = el; L.last = el;
    }
    L.nb_contour_bezier++;
    return L ; 
}

Liste_Contour_bezier supprimer_liste_Contour_bezier(Liste_Contour_bezier L)
{
    Cellule_Liste_Contour_bezier *el=L.first ;
    while (el){
        Cellule_Liste_Contour_bezier *suiv = el->suiv;
        free(el);
        el=suiv;
    }

    L.first =L.last =NULL; 
    L.nb_contour_bezier = 0;
    return L ;
}

Liste_Contour_bezier concatener_liste_Contour_bezier(Liste_Contour_bezier L1, Liste_Contour_bezier L2)
{

    if (L1.nb_contour_bezier == 0) return L2; 
    if (L2.nb_contour_bezier == 0) return L1;
    L1.last->suiv = L2.first ;
    L1.last = L2.last ;  
    L1.nb_contour_bezier += L2.nb_contour_bezier ; 
    return L1;
}


int taille_liste_contours_bezier (Liste_Contour_bezier L){
    return L.nb_contour_bezier;
}