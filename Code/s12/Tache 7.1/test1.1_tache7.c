#include <stdio.h>
#include <stdlib.h>
#include "calcul_contour.h"
#include "image.h"
#include "geom2d.h"
#include "courbe_bezier.h"
#include "listes_chainees_points.h"
#include "listes_chainees_contours.h"


int main (int argc, char* argv[]){

    printf(" Programme de test de la fonction approx_bezier2 \n");
    // Cas n = 1
    Point P1,P2;
    P1 = set_point(0.000000, 1.000000);
    P2 = set_point(2.000000, 1.000000);
    Liste_Point L_P = creer_liste_Point_vide();
    L_P = ajouter_element_liste_Point(L_P, P1);
    L_P = ajouter_element_liste_Point(L_P, P2);

    Tableau_Point tableau = sequence_points_liste_vers_tableau(L_P);
    Bezier2 B1 =  cree_Bezier2();
    B1 = approx_bezier2(tableau, 0, 1);
    Point Q = add_point(P1,P2);
    Q = Produit_avec_un_reel_point(1.0/2.0 , Q);
    if (Points_egaux(B1.C0, P1) && Points_egaux(B1.C1,Q) && Points_egaux(B1.C2,P2)){
        printf("Test cas n=1 PASS\n");
    } else {
        printf("Test cas n=1 FAIL\n");
    }

    // Cas n >= 2:
    double n = 2.0;
    double t;
    Point P3 = set_point(3.000000, 3.000000);
    L_P = ajouter_element_liste_Point(L_P, P3);
    tableau = sequence_points_liste_vers_tableau(L_P);
    Bezier2 B2= cree_Bezier2();
    B2.C0 = P1;
    B2.C1 = P2;
    B2.C2 = P3; 
    Liste_Point L = creer_liste_Point_vide();
    for (double i = 0.0; i <= n; i=i+1.0){
        t = i/n;
        L= ajouter_element_liste_Point(L, C_Bezier2(B2,t));
    }
    tableau = sequence_points_liste_vers_tableau(L);

    B2 =  approx_bezier2(tableau, 0, 2);
    if (Points_egaux(B2.C0, P1) && Points_egaux(B2.C1,P2) && Points_egaux(B2.C2,P3)){
        printf("Test cas n>=2 PASS\n");
    } else {
        printf("Test cas n>=2 FAIL\n");
    }
    
    
    Point P0 = set_point(0.000000, 0.000000);
    P1 = set_point(1.000000, 0.000000);
    P2 = set_point(1.000000, 1.000000);
    P3 = set_point(1.000000, 2.000000);
    Point P4 = set_point(2.000000, 2.000000);
    Point P5 = set_point(3.000000, 2.000000);
    Point P6 = set_point(3.000000, 3.000000);
    Point P7 = set_point(4.000000, 3.000000);
    Point P8 = set_point(5.000000, 3.000000);
    Liste_Point L3= creer_liste_Point_vide();
    L3 = ajouter_element_liste_Point(L3, P0);
    L3 = ajouter_element_liste_Point(L3, P1);
    L3 = ajouter_element_liste_Point(L3, P2);
    L3 = ajouter_element_liste_Point(L3, P3);
    L3 = ajouter_element_liste_Point(L3, P4);
    L3 = ajouter_element_liste_Point(L3, P5);
    L3 = ajouter_element_liste_Point(L3, P6);
    L3 = ajouter_element_liste_Point(L3, P7);
    L3 = ajouter_element_liste_Point(L3, P8);
    tableau = sequence_points_liste_vers_tableau(L3);


    n = 8.0;
    B2 =  approx_bezier2(tableau, 0, n);
    Q = set_point(1.547619, 2.452381);
    if ( Points_egaux(B2.C2,P8) && Points_egaux(B2.C0, P0)&& (B2.C1.x - Q.x)<= 0.00001 && (B2.C1.y - Q.y)<= 0.00001){ //Points_egaux(B2.C0, P0) && Points_egaux(B2.C1,Q) &&
        printf("Test cas tableau page 52 PASS\n");
    } else {
        printf("Test cas tableau page 52 FAIL\n");
    }
}
