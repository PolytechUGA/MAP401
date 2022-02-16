#include <stdio.h>
#include "calcul_contour.h"
#include "sortie_EPS.h"

int main(int argc , char *argv[]){
    // printf(" arguments : 1/fichier.pbm 2/fichier.txt 3/fichier.EPS 4/mode (0=strocke ou 1=fill) \n");
    
    if(argc != 5){
        printf(" Erreur : 1/fichier.pbm 2/fichier.txt 3/fichier.EPS 4/mode (0=strocke ou 1=fill) \n");
        return -1;
    }
    Image I;
    Liste_Contour L;
    int mode = atoi(argv[4]);
    I = lire_fichier_image(argv[1]);

    
    FILE *f_txt = NULL; 
    f_txt = fopen(argv[2], "w");
    if( f_txt == NULL){
        printf(" Problème d'ouverture du fichier txt\n");
        return -2;
    }
    FILE *f_EPS = NULL; 
    f_EPS = fopen(argv[3], "w");
    if( f_EPS == NULL){
        printf(" Problème d'ouverture du fichier EPS \n");
        return -2;
    }


    
    // Partie 1
    Image I_Masque = cree_image_masque(I);
    
    L = extraction_des_contours(I, I_Masque);
    affichage_ecran(L);
    ecrire_contour_fichier_contours(L, f_txt);

    // Partie 2
    
    

    //ecriture_fichier_EPS(f_out,mode, I, L);
    fclose (f_txt);
    fclose(f_EPS);
    return 1;
}