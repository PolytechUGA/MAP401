#include "Douglas_Peucker.h"

Liste_Point algo_Douglas_Peucker(Liste_Point C, int j1, int j2, double d){
    double dmax, dj;
    int k;
    Liste_Point L = creer_liste_Point_vide();
    Point Pj1, Pj2, Pj;
    Tableau_Point table =  sequence_points_liste_vers_tableau (C);
    Pj1 = table.tab[j1];
    Pj2 = table.tab[j2];
    dmax = 0;
    k = j1;
    for(int j = j1+1; j <= j2; j++){
        Pj = table.tab[j];
        dj = distance_point_segment(Pj, Pj1, Pj2);
        if (dmax < dj){
            dmax = dj;
            k=j;
        }
    }
    if ( dmax <= d){
        L = ajouter_element_liste_Point(L,Pj1);
        L = ajouter_element_liste_Point(L,Pj2);
    } else {
        Liste_Point L1 = algo_Douglas_Peucker ( C, j1, k, d);
        Liste_Point L2 = algo_Douglas_Peucker ( C, k, j2, d);
        Cellule_Liste_Point *cel = L2.first;
        L2.first = L2.first->suiv;
        L2.taille = L2.taille-1;
        free(cel);
        L = concatener_liste_Point (L1,L2);
    }
    return L;
}