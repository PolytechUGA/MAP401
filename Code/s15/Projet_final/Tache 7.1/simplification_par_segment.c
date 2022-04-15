#include "Douglas_Peucker.h"
#include "image.h"
#include "listes_chainees_contours.h"   
#include <stdio.h>
#include <stdlib.h>
#include "calcul_contour.h"
#include "sortie_EPS.h"
#include "ecriture_contours.h"
#include "listes_chainees_points.h"
#include "geom2d.h"

int main (int argc, char* argv[]){
    // Arguments
    printf(" Tache6.2 : 1/fichier.pbm 2/Distance seuil d  3/Mode  4/Fichier de sortie EPS\n");

    // Gestion des erreurs
    if(argc < 3){
            printf("erreur : \n");
            printf(" Tache6.2 : 1/fichier.pbm 2/Distance seuil d  3/Mode (0=strocke ou 1=fill) 4/Fichier de sortie EPS\n");
        return -1;
    }

    // Exctraction des contours de l'image
    Image I;
    double d;
    d= atof(argv[2]);
    Liste_Contour L;
    I = lire_fichier_image(argv[1]);
    Image I_Masque = cree_image_masque(I);
    L = extraction_des_contours(I, I_Masque);
    supprimer_image(&I_Masque);
    Tableau_Point table;
    // On applique l'algorithme à chaque contour
    
    for (Cellule_Liste_Contour *tmp_contour = L.first; tmp_contour != NULL ; tmp_contour = tmp_contour->suiv){
        table = sequence_points_liste_vers_tableau (tmp_contour->contour);
        tmp_contour->contour = algo_Douglas_Peucker(table , 0, tmp_contour->contour.taille-1, d);
        //free(table.tab);
    }
    // Affichage du nombre de contour et de segment
    affichage_ecran(L);

    // Gestion des erreurs
    int mode = atoi(argv[3]);
    FILE *f_EPS = NULL; 
    f_EPS = fopen(argv[4], "w");
    if( f_EPS == NULL){
        printf(" Problème d'ouverture du fichier EPS \n");
        return -2;
    }
    ecriture_fichier_EPS_tache5(f_EPS, mode, I, L);
    supprimer_image(&I);
    supprimer_liste_Contour(L);
    fclose(f_EPS);
    return 1;
}
