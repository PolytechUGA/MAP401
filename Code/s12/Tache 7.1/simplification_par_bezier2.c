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
#include "courbe_bezier.h"
#include "listes_chainees_bezier.h"
#include "liste_contour_bezier.h"

int main (int argc, char* argv[]){

    printf(" Tache7.1 : 1/fichier.pbm 2/Distance seuil d  3/Mode  4/Fichier de sortie EPS\n");
    if(argc < 3){
            printf("erreur : \n");
            printf(" Tache7.1 : 1/fichier.pbm 2/Distance seuil d  3/Mode (0=strocke ou 1=fill) 4/Fichier de sortie EPS\n");
        return -1;
    }
    Image I= lire_fichier_image(argv[1]);
    double d= atof (argv[2]);
    Image I_Masque = cree_image_masque(I);
    Liste_Contour L = extraction_des_contours(I, I_Masque);
    Tableau_Point CONT;
    Liste_Contour_bezier LB = creer_liste_Contour_bezier_vide();
    Liste_Bezier3 B;
    int cpt = 0;

    for (Cellule_Liste_Contour *tmp_contour = L.first; tmp_contour != NULL ; tmp_contour = tmp_contour->suiv){
        CONT =  sequence_points_liste_vers_tableau (tmp_contour->contour);
        B = simplification_douglas_peucker_bezier2(CONT, 0, CONT.taille-1, d);

        LB = ajouter_element_liste_Contour_bezier(LB,B);
        cpt= cpt+B.nb_Bezier3;
    }
    int mode = atoi(argv[3]);
    FILE *f_EPS = NULL; 
    f_EPS = fopen(argv[4], "w");
    if( f_EPS == NULL){
        printf(" Problème d'ouverture du fichier EPS \n");
        return -2;
    }
    printf("Nombre de courbes de Bezier : %d\n", cpt);
    
    ecriture_fichier_EPS_bezier3(f_EPS, mode, I, LB);
    fclose(f_EPS);
    return 1;
}
