#include "contour.h"

int main(int argc, char **argv){
    if(argc != 3){
        printf("Erreur, vous devez entre une image en argument. \n");
        return -1;
    }
    Image I;
    Liste_Point L;
    I = lire_fichier_image(argv[1]);
    FILE *f_out = NULL; 
    f_out = fopen(argv[2], "w");
    if( f_out == NULL){
        printf(" Problème d'ouverture du fichier de sortie \n");
        return -2;
    }
    L = calcul_contour(I);
    ecrire_contour_fichier(L , f_out);
    fclose (f_out);
    printf("Nombre de segments dans l'image : %d \n", nombre_segment(L));
    return 1;
}  
    // Contour C1, C2;
    // C1 = creer_liste_Point_vide();
    // printf("C1 : ");
    // C1 = ajouter_element_liste_Point(C1, set_point(5, 3));
    // C1 = ajouter_element_liste_Point(C1, set_point(3, 1));
    // C1 = ajouter_element_liste_Point(C1, set_point(7, 2));
    // C1 = ajouter_element_liste_Point(C1, set_point(1, 6));
    // printf("C1 : ");
    // ecrire_contour (C1);
    // C2 = creer_liste_Point_vide();
    // C2 = ajouter_element_liste_Point (C2, set_point(9,5));
    // C2 = ajouter_element_liste_Point (C2, set_point(5,7));
    // printf("C2 : ");
    // ecrire_contour (C2);
    // C1 = concatener_liste_Point (C1 , C2);
    // printf("C1 : ");
    // C1 = supprimer_liste_Point(C1);
    // printf("C1 : ");
    // ecrire_contour (C1);