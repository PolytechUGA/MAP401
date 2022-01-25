#include "contour.h"

int main(int argc, char **argv){
    if(argc != 2){
        printf("Erreur, vous devez entre une image en argument. \n");
        return -1;
    }
    Image I;
    I = lire_fichier_image(argv[1]);
    calcul_contour(I);
    return 1;
}