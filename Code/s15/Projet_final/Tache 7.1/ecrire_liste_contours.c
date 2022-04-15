
#include <stdio.h>
#include "calcul_contour.h"
#include "sortie_EPS.h"

int main(int argc , char *argv[]){
    // Arguments
    printf(" Tache5.1 : 1/fichier.pbm 2/fichier.txt \n");
    printf(" Tache5.2 : 1/fichier.pbm 2/fichier.EPS 3/mode (0=strocke ou 1=fill) \n");

    // Gestion des erreurs
    if(argc < 3){
            printf("ERREUR : \n");
            printf(" Tache5.1 : 1/fichier.pbm 2/fichier.txt \n");
            printf(" Tache5.2 : 1/fichier.pbm 2/fichier.EPS 3/mode (0=strocke ou 1=fill) \n");
        return -1;
    }

    // Exctraction des contours
    Image I;
    Liste_Contour L;
    I = lire_fichier_image(argv[1]);
    Image I_Masque = cree_image_masque(I);
    L = extraction_des_contours(I, I_Masque);
    affichage_ecran(L);


    if(argc == 3){
        // Gestion des erreurs
        FILE *f_txt = NULL; 
        f_txt = fopen(argv[2], "w");
        if( f_txt == NULL){
            printf(" Problème d'ouverture du fichier txt\n");
            return -2;
        }
        
        // Ecris les contours dans le fichier f_txt
        ecrire_contour_fichier_contours(L, f_txt);
        fclose (f_txt);
    }

    if (argc == 4){
        // Gestion des erreurs
        int mode = atoi(argv[3]);
        FILE *f_EPS = NULL; 
        f_EPS = fopen(argv[2], "w");
        if( f_EPS == NULL){
            printf(" Problème d'ouverture du fichier EPS \n");
            return -2;
        }

        // Ecriture dans le fichier f_EPS des contours de l'images, en format EPS et avec le mode passé en paramêtre.
        ecriture_fichier_EPS_tache5(f_EPS, mode, I, L);
        fclose(f_EPS);
    }
    return 1;
}