#include <stdio.h>
#include "image.h"
#include "types_macros.h"


int main(int argc, char * argv[]){
    // Vérification que le nombre d'arguments est correct 
    if(argc != 2){
        printf("Erreur, vous devez entre une image en argument. \n");
        return -1;
    }
    printf(" -------- Afficher image ----------\n");
    Image I;
    // Lis l'image entrée en paramètre
    I = lire_fichier_image(argv[1]);  
    // Récupère la valeur d'un pixel et vérifie que celle-ci est correct  
    Pixel p = get_pixel_image(I,3,2);
    if (p==1){
        printf("Get_pixel_image OK\n");
        printf("la couleur du pixel à la position (3,2) est %d\n", p);
    } else {
        printf(" Pb execution fonction Get_pixel_image\n");
    }
    printf("lecture OK \n");
    // Vérifie que la hauteur et la largeur de l'image sont correct    
    if(I.H == hauteur_image (I))
        printf("La hauteur de l'image est OK \n");
    else
        printf("La hauteur de l'image est INCORRECT \n");
    if(I.L == largeur_image (I))
        printf("La largeur de l'image est OK \n");
    else 
        printf("La largeur de l'image est INCORRECT \n");
    // Ecrit l'image de base dans le terminal  
    ecrire_image(I);


    printf(" -------- Afficher image negative----------\n");
    // Calcule l'image négative
    Image I_neg = negatif_image(I);
    // Puis l'écrit 
    ecrire_image(I_neg);
    // Test de la fonction supprimer image
    supprimer_image(&I_neg);
    printf(" -------- Afficher image negative supprimé----------\n");
    ecrire_image(I_neg);

    p = get_pixel_image(I,3,2);
    printf("la couleur du pixel à la position (3,2) est %d\n", p);

    Pixel p2 = get_pixel_image(I,20,2);
    printf("la couleur du pixel en dehors de l'image est %d\n", p2);
    // Test de la fonction qui permet de modifier la couleur d'un pixel
    set_pixel_image(I,20,2, NOIR);
    if (p2==0){
        printf("Set_pixel_image OK\n");
        printf("la couleur du pixel à la position (20,2) est %d\n", p2);
    } else {
        printf(" Pb execution fonction Set_pixel_image\n");
    }
    printf("la couleur du pixel en dehors de l'image est %d\n", p2);

    set_pixel_image(I,20,2, BLANC);
    printf("la couleur du pixel à la position (3,2) modifié est %d\n", p2);
    supprimer_image(&I);
    return 0;
}