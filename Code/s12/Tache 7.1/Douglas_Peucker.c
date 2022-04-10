#include "Douglas_Peucker.h"

Liste_Point algo_Douglas_Peucker(Liste_Point C, int j1, int j2, double d){
    double dmax, dj;
    int k;
    Liste_Point L = creer_liste_Point_vide();
    Point Pj1, Pj2, Pj;
    Tableau_Point table =  sequence_points_liste_vers_tableau (C); // Prendre des tableau de point en paramettre et transformer en tableau en dehors de la fonction
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

Liste_Bezier3 simplification_douglas_peucker_bezier2(Tableau_Point CONT, int j1, int j2, double d){
    Liste_Bezier3 L= creer_liste_Bezier3_vide();
    double dmax = 0.0;
    double dj;
    int k = j1;
    double n = (double) (j2 - j1);
    Bezier2 B = approx_bezier2(CONT, j1, j2);
    int i;
    double ti;
    for (int j = j1+1; j<=j2; j++){
        i = j - j1;
        ti = (double)((double)(i))/((double)(n));
        dj = distance_point_bezier2(CONT.tab[j], B, ti);
        if (dmax<dj){
            dmax = dj;
            k = j;
        }
    }
    if (dmax<=d){
        Bezier3 B3 = Conversion_B2_B3(B);
        L = ajouter_element_liste_Bezier3(L, B3);
    }
    else {
        Liste_Bezier3 L1 = simplification_douglas_peucker_bezier2( CONT, j1, k, d);
        Liste_Bezier3 L2 = simplification_douglas_peucker_bezier2( CONT, k, j2, d);
        L = concatener_liste_Bezier3 (L1,L2);
    }
    return L;
}


Liste_Bezier3 simplification_douglas_peucker_bezier3(Tableau_Point CONT, int j1, int j2, double d){
    Liste_Bezier3 L= creer_liste_Bezier3_vide();
    double dmax = 0.0;
    double dj;
    int k = j1;
    double n = (double) (j2 - j1);
    Bezier3 B = approx_bezier3(CONT, j1, j2);
    int i;
    double ti;
    for (int j = j1+1; j<=j2; j++){
        i = j - j1;
        ti = (double)((double)(i))/((double)(n));
        dj = distance_point_bezier3(CONT.tab[j], B, ti);
        if (dmax<dj){
            dmax = dj;
            k = j;
        }
    }
    if (dmax<=d){
        L = ajouter_element_liste_Bezier3(L, B);
    }
    else {
        Liste_Bezier3 L1 = simplification_douglas_peucker_bezier3( CONT, j1, k, d);
        Liste_Bezier3 L2 = simplification_douglas_peucker_bezier3( CONT, k, j2, d);
        L = concatener_liste_Bezier3 (L1,L2);
    }
    return L;
}