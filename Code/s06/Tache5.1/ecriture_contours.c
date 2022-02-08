#include "ecriture_contours.h"


void ecrire_liste_point_fichier( Liste_Point L, FILE *f){
    fprintf(f, "%d\n", nombre_segment(L));
    Cellule_Liste_Point *tmp;
    tmp = L.first;
    if (tmp == NULL){
        return;
    }
    for (tmp = L.first; tmp->suiv != NULL; tmp = tmp->suiv){
        fprintf(f, " %f %f\n", tmp->data.x, tmp->data.y);
    }
}

void ecrire_contour_fichier_contours(Liste_Contour L, FILE *f){
    int nb_contours = taille_liste_contours(L);
    fprintf(f, "%d\n\n", nb_contours);
    Cellule_Liste_Contour *tmp_;
    tmp_ = L.first;
    if (tmp_ == NULL){
        return;
    }
    for (tmp_ = L.first; tmp_->suiv != NULL; tmp_ = tmp_->suiv){
        fprintf(f, "\n\n");
        ecrire_liste_point_fichier(tmp_->contour, f);
    }
}


void affichage_ecran (Liste_Contour L){
    int nb_c = taille_liste_contours(L);
    int nb_segments = 0; 
    Cellule_Liste_Contour *tmp_ = L.first;
    while (tmp_ != NULL){
        nb_segments = nb_segments + nombre_segment(tmp_->contour);
        tmp_ = tmp_->suiv;
    }
    printf( "\nNombre de contours : %d \n", nb_c);
    printf( "Nombre de segments : %d \n", nb_segments);

}



void ecrire_contour(Liste_Point L)
{
    Tableau_Point TP = sequence_points_liste_vers_tableau(L);
    int k;
    int nP = TP.taille ;
    printf("%d points : [", nP); 
    for (k = 0; k < nP; k++)
    {
        Point P = TP.tab[k];
        printf(" (%5.1f,%5.1f)", P.x, P.y);
    }
    printf( " ] \n" ) ;
    free (TP.tab );
}