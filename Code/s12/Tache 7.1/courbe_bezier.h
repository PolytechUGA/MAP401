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

Bezier2 cree_Bezier2();

Bezier3 creer_Bezier3();

Point C_Bezier2(Bezier2 B, double t);

Point C_Bezier3(Bezier3 B, double t);

Bezier3 Conversion_B2_B3(Bezier2 B);

Bezier2 approx_bezier2(Tableau_Point L, int j1, int j2);

double calcul_alpha( double n );

double calcul_beta(double n);

double calcul_lamda(double n);

double calcul_gama(double k, double n);

Bezier3 approx_bezier3(Tableau_Point L, int j1, int j2);

double distance_point_bezier2(Point Pj, Bezier2 B, double ti);

double distance_point_bezier3(Point Pj, Bezier3 B, double ti);













#endif