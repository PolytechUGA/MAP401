#include "calcul_contour.h"
#include "sortie_EPS.h"

#define STROKE 0
#define FILL 1



int main(int argc, char **argv){
    printf(" arguments : 1/image 2/fichier 3/mode (0=strocke ou 1=fill) \n");
    // Gestion d'erreur
    if(argc != 4){
        printf("Erreur, vous devez entre une image en argument. \n");
        return -1;
    }
    Image I;
    Liste_Point L;
    // Récupération du mode
    int mode = atoi(argv[3]);
    // Lecture de l'image
    I = lire_fichier_image(argv[1]);
    FILE *f_out = NULL;
    // Gestion d'erreur
    f_out = fopen(argv[2], "w");
    if( f_out == NULL){
        printf(" Problème d'ouverture du fichier de sortie \n");
        return -2;
    }
    // Ecriture dans le fichier f_out sous forme EPS
    L = calcul_contour(I);
    ecriture_fichier_EPS(f_out, mode, I, L);
    fclose (f_out);
    // Affichage du nombre de segment de l'image
    printf("Nombre de segments dans l'image : %d \n", nombre_segment(L));
    return 1;
}  