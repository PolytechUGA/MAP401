#include "calcul_contour.h"
#include "ecriture_contours.h"
#include "image.h"

int main(int argc, char **argv){
    if(argc != 3){
        printf("Erreur, 1/Image.pbm 2/Fichier de sortie \n");
        return -1;
    }
    Image I;
    Liste_Point L;
    // Lis l'image donnée en arguments
    I = lire_fichier_image(argv[1]);
    FILE *f_out = NULL; 
    f_out = fopen(argv[2], "w");
    if( f_out == NULL){
        printf(" Problème d'ouverture du fichier de sortie \n");
        return -2;
    }
    // Calcul les contours de cette image et écrit ses contours dans un fichier donner en 2e argument
    L = calcul_contour(I);
    ecrire_liste_point_fichier(L , f_out);
    fclose (f_out);
    printf("Nombre de segments dans l'image : %d \n", nombre_segment(L));
    return 1;
}