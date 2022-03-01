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


    printf(" Tache6.2 : 1/fichier.pbm 2/Distance seuil d  3/Mode  4/Fichier de sortie EPS\n");
    if(argc < 3){
            printf("erreur : \n");
            printf(" Tache6.2 : 1/fichier.pbm 2/Distance seuil d  3/Mode (0=strocke ou 1=fill) 4/Fichier de sortie EPS\n");
        return -1;
    }
    Image I;
    int d;
    d= atoi (argv[2]);
    Liste_Contour L;
    I = lire_fichier_image(argv[1]);
    Image I_Masque = cree_image_masque(I);
    L = extraction_des_contours(I, I_Masque);

    // Cellule_Liste_Contour *cel = L.first;

    for (Cellule_Liste_Contour *tmp_contour = L.first; tmp_contour != NULL ; tmp_contour = tmp_contour->suiv){
        printf (" taille :%d \n", tmp_contour->contour.taille);
        tmp_contour->contour = algo_Douglas_Peucker(tmp_contour->contour , 0, tmp_contour->contour.taille, d);
    }
    // 
    // for (int i=1; i<L.nb_contour; i++){
    //     cel->contour = algo_Douglas_Peucker(cel->contour , 0, 1, d);
    //     cel = cel->suiv;
    // }
    affichage_ecran(L);
    int mode = atoi(argv[3]);

    FILE *f_EPS = NULL; 
    f_EPS = fopen(argv[4], "w");
    if( f_EPS == NULL){
        printf(" Problème d'ouverture du fichier EPS \n");
        return -2;
    }
    ecriture_fichier_EPS_tache5(f_EPS, mode, I, L);
    fclose(f_EPS);
    return 1;
}
