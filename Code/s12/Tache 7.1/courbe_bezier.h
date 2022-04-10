#ifndef _COURBE_BEZIER_H_
#define _COURBE_BEZIER_H_
#include "geom2d.h"
#include <stdio.h>
#include <math.h>
#include "listes_chainees_points.h"

typedef struct Bezier2 {
    Point C0;
    Point C1;
    Point C2;
} Bezier2 ;

typedef struct Bezier3 {
    Point C0;
    Point C1;
    Point C2;
    Point C3;
} Bezier3 ;

// Creer une courbe de Bezier 2 avec C0 = C1 = C2 = (0,0)
Bezier2 cree_Bezier2();

// Creer une courbe de Bezier 3 avec C0 = C1 = C2 = C3 = (0,0)
Bezier3 creer_Bezier3();

// Calcule le point de la courbe de Bezier 2 C(t) au point t.
Point C_Bezier2(Bezier2 B, double t);

// Calcule le point de la courbe de Bezier 3 C(t) au point t.
Point C_Bezier3(Bezier3 B, double t);

// Convertie une courbe de Bezier de degré 2 en courbe de Bezier de degré 3.
Bezier3 Conversion_B2_B3(Bezier2 B);

// Fonction d’approximation d’une courbe de bézier 2 à partir de 2 points ou plus.
Bezier2 approx_bezier2(Tableau_Point L, int j1, int j2);

// Calcul de la variable alpha nécessaire dans le calcul de approx_bezier3
double calcul_alpha( double n );

// Calcul de la variable beta nécessaire dans le calcul de approx_bezier3
double calcul_beta(double n);

// Calcul de la variable lambda nécessaire dans le calcul de approx_bezier3
double calcul_lamda(double n);

// Calcul de la variable gama nécessaire dans le calcul de approx_bezier3
double calcul_gama(double k, double n);

// Fonction d’approximation d’une courbe de bézier 3 à partir de 2 points ou plus,
// puisque si on a 2 points, la fonction appelle approx_bezier2 puis convertie la 
// courbe obtenue en une courbe de bezier 3.
Bezier3 approx_bezier3(Tableau_Point L, int j1, int j2);

// Calcule la distance entre une courbe de Bezier 2 et un point donné.
double distance_point_bezier2(Point Pj, Bezier2 B, double ti);

// Calcule la distance entre une courbe de Bezier 3 et un point donné.
double distance_point_bezier3(Point Pj, Bezier3 B, double ti);

#endif
