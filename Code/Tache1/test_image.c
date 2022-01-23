#include <stdio.h>
#include "image.h"
#include "types_macros.h"


int main(int argc, char * argv[]){
    // FILE * f;
    if(argc != 2){
        printf("Erreur, vous devez entre une image en argument. \n");
        return -1;
    }

    // f=fopen(argv[1], "w");
    // if(f == NULL){
    //     printf("Erreur d'ouverture du fichier \n");
    //     return -1;
    // }
    printf(" -------- Afficher image ----------\n");
    Image I;
    I = lire_fichier_image(argv[1]);    
    Pixel p = get_pixel_image(I,3,2);
    printf("la couleur du pixel à la position (3,2) est %d\n", p);
    printf("lecture OK \n");    
    if(I.H == hauteur_image (I))
        printf("La hauteur de l'image est OK \n");
    else 
        printf("La hauteur de l'image est INCORRECT \n");
    if(I.L == largeur_image (I))
        printf("La largeur de l'image est OK \n");
    else 
        printf("La largeur de l'image est INCORRECT \n");
    ecrire_image(I);


    printf(" -------- Afficher image negative----------\n");
    Image I_neg = negatif_image(I);
    ecrire_image(I_neg);
    supprimer_image(&I_neg);
    printf(" -------- Afficher image negative supprimé----------\n");
    ecrire_image(I_neg);

    p = get_pixel_image(I,3,2);
    printf("la couleur du pixel à la position (3,2) est %d\n", p);


    Pixel p2 = get_pixel_image(I,20,2);
    printf("la couleur du pixel en dehors de l'image est %d\n", p2);

    set_pixel_image(I,20,2, NOIR);
    printf("la couleur du pixel en dehors de l'image est %d\n", p2);
    return 0;

}