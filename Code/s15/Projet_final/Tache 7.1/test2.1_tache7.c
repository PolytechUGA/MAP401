#include <stdio.h>
#include <stdlib.h>
#include "calcul_contour.h"
#include "image.h"
#include "geom2d.h"
#include "courbe_bezier.h"
#include "listes_chainees_points.h"
#include "listes_chainees_contours.h"


int main (int argc, char* argv[]){

    printf(" Programme de test de la fonction approx_bezier3 \n");
    // Cas n = 1
    Point P1,P2, P3,P4, Q1,Q2;
    P1 = set_point(0.000000, 1.000000);
    P2 = set_point(2.000000, 1.000000);
    P3 = set_point(3.000000, 3.000000);
    Liste_Point L_P = creer_liste_Point_vide();
    L_P = ajouter_element_liste_Point(L_P, P1);
    L_P = ajouter_element_liste_Point(L_P, P2);

    Tableau_Point tableau = sequence_points_liste_vers_tableau(L_P);
    Bezier3 B1 =  creer_Bezier3();
    B1 = approx_bezier3(tableau, 0, 1);
    Q1 = Produit_avec_un_reel_point(2, P1);
    Q1 = add_point(Q1, P2);
    Q1 = Produit_avec_un_reel_point(1.0/3.0, Q1);

    Q2 = Produit_avec_un_reel_point(2, P2);
    Q2 = add_point(P1, Q2);
    Q2 = Produit_avec_un_reel_point(1.0/3.0, Q2);

    if (Points_egaux(B1.C0, P1) && Points_egaux(B1.C1,Q1) && Points_egaux(B1.C2,Q2) && Points_egaux(B1.C3,P2)){
        printf("Test cas n=1 PASS\n");
    } else {
        printf("Test cas n=1 FAIL\n");
    }

    // Cas n = 2
    L_P = ajouter_element_liste_Point(L_P, P3);
    tableau = sequence_points_liste_vers_tableau(L_P);
    B1 =  creer_Bezier3();
    Point TMP;
    B1 = approx_bezier3(tableau, 0, 2);
    TMP = Produit_avec_un_reel_point(-1, P3);
    Q1 = Produit_avec_un_reel_point(4, P2);
    Q1 = add_point(Q1, TMP);
    Q1 = Produit_avec_un_reel_point(1.0/3.0, Q1);

    TMP = Produit_avec_un_reel_point(4, P2);
    Q2 = Produit_avec_un_reel_point(-1, P1);
    Q2 = add_point(TMP, Q2);
    Q2 = Produit_avec_un_reel_point(1.0/3.0, Q2);


    if (Points_egaux(B1.C0, P1) && Points_egaux(B1.C1, Q1) && Points_egaux(B1.C2, Q2) && Points_egaux(B1.C3, P3)){
        printf("Test cas n=2 PASS\n");
    } else {
        printf("Test cas n=2 FAIL\n");
    }

    // Cas n >= 3:    
    double n = 3.0;
    double t;
    P4 = set_point(6.000000, 1.000000);
    L_P = ajouter_element_liste_Point(L_P, P4);
    tableau = sequence_points_liste_vers_tableau(L_P);
    Bezier3 B2= creer_Bezier3();
    B2.C0 = P1;
    B2.C1 = P2;
    B2.C2 = P3;
    B2.C3 = P4;
    Liste_Point L = creer_liste_Point_vide();
    for (double i = 0.0; i <= n; i=i+1.0){
        t = i/n;
        L= ajouter_element_liste_Point(L, C_Bezier3(B2,t));
    }
    tableau = sequence_points_liste_vers_tableau(L);

    B2 =  approx_bezier3(tableau, 0, (int)n);
    
    if (((B2.C0.x - P1.x)<= 0.00001) && (B2.C0.y - P1.y)<= 0.00001 && 
        (B2.C1.x - P2.x)<= 0.00001 && (B2.C1.y - P2.y)<= 0.00001 && 
        (B2.C2.x - P3.x)<= 0.00001 && (B2.C2.y - P3.y)<= 0.00001 && 
        (B2.C3.x - P4.x)<= 0.00001 && (B2.C3.y - P4.y)<= 0.00001){
        printf("Test cas n>=3 PASS\n");
    } else {
        printf("Test cas n>=3 FAIL\n");
    }
    
    
    Point P0 = set_point(0.000000, 0.000000);
    P1 = set_point(1.000000, 0.000000);
    P2 = set_point(1.000000, 1.000000);
    P3 = set_point(1.000000, 2.000000);
    P4 = set_point(2.000000, 2.000000);
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
    B2 =  approx_bezier3(tableau, 0, n);
    Q1 = set_point(1.737287, 0.929380);
    Q2 = set_point(1.844176, 3.489158);
    if ( Points_egaux(B2.C3,P8) && Points_egaux(B2.C0, P0)&& (B2.C1.x - Q1.x)<= 0.00001 && (B2.C1.y - Q1.y)<= 0.00001 && (B2.C2.x - Q2.x)<= 0.00001 && (B2.C2.y - Q2.y)<= 0.00001){
        printf("Test cas tableau page 52 PASS\n");
    } else {
        printf("Test cas tableau page 52 FAIL\n");
    }
}
