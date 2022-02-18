#include "Douglas-Peucker.h"

Liste_Point algo_Douglas_Peucker(Liste_Point C, int j1, int j2, int d){
    Liste_Point L;
    int dmax, k , dj;
    Point Pj1, Pj2, Pj, S;
    Tableau_Point table =  sequence_points_liste_vers_tableau (L);
    Pj1 = table.tab[j1];  
    Pj2 = table.tab[j2];  
    S =  point_bipoint(Pj1, Pj2);
    dmax = 0;
    k = j1;
    for(int j = j1+1; j = j2; j++){
        dj = distance_point_segment(Pj, Pj1, Pj2);
        if (dmax < dj){
            dmax = dj;
            k=j;
        }
    }

    if ( dmax <= d){
        ajouter_element_liste_Point(L,S);
    } else {
        Liste_Point L1 = algo_Douglas_Peucker (C,j1,k,d);
        Liste_Point L2 = algo_Douglas_Peucker (C, k,j2,d);
        L = concatener_liste_Point (L1,L2);
    }
    return L;
}