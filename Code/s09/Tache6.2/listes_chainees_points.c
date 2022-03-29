#include "listes_chainees_points.h"


Cellule_Liste_Point *creer_element_liste_Point(Point v)
{
    Cellule_Liste_Point *el ;
    el = (Cellule_Liste_Point *)malloc(sizeof(Cellule_Liste_Point )); 
    if (el==NULL){
        fprintf (stderr , "creer_element_liste_Point : allocation impossible\n");
        exit (-1); 
    }
    el->data = v; 
    el->suiv = NULL; 
    return el ;
}


Liste_Point creer_liste_Point_vide()
{
    Liste_Point L = {0, NULL, NULL}; 
    return L ;
}

Liste_Point ajouter_element_liste_Point(Liste_Point L, Point e)
{
    Cellule_Liste_Point *el ;
    el = creer_element_liste_Point(e); 
    if (L.taille == 0)
    {
        L.first = L.last = el;
    }
    else
    {
        L.last->suiv = el; L.last = el;
    }
    L. taille++;
    return L ; 
}

Liste_Point supprimer_liste_Point(Liste_Point L)
{
    Cellule_Liste_Point *el=L.first ;
    while (el){
        Cellule_Liste_Point *suiv = el->suiv;
        free(el);
        el=suiv;
    }

    L.first =L.last =NULL; 
    L.taille = 0;
    return L ;
}

Liste_Point concatener_liste_Point(Liste_Point L1, Liste_Point L2)
{

    if (L1.taille == 0) return L2; 
    if (L2.taille == 0) return L1;
    L1.last->suiv = L2.first ; // a la place de L2.first
    L1.last = L2.last ;  
    L1.taille += L2.taille ; 
    return L1;
}

Tableau_Point sequence_points_liste_vers_tableau(Liste_Point L)
{
    Tableau_Point T;
    T.taille = L.taille ;
    T.tab = malloc(sizeof(Point) * T.taille );
    if (T.tab==NULL)
    {
        fprintf(stderr, "sequence_points_liste_vers_tableau : ");
        fprintf(stderr , " allocation impossible\n");
        exit (-1);
    }
    int k = 0;
    Cellule_Liste_Point *el = L.first ;
    while (el)
    {
    T.tab[k] = el->data; k++;
    el = el->suiv;
    }
    return T;
}