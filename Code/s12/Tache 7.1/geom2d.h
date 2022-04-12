#ifndef _GEOM2D_H_
#define _GEOM2D_H_

#include <stdio.h>
#include <math.h>


typedef struct Vecteur {
    double x , y ; // coordonnees
} Vecteur ;

typedef struct Point {
    double x , y ; // coordonnees 
} Point ;


// cree le point de coordonnées (x,y)
Point set_point ( double x , double y );

// cree le vecteur de coordonnées (x,y)
Vecteur set_vecteur ( double x , double y );

// somme P1+P2 
Point add_point ( Point P1 , Point P2 );

// somme V1+V2 
Vecteur add_vecteur ( Vecteur V1, Vecteur V2);


// Produit aP
Point Produit_avec_un_reel_point ( double a, Point P);

// Produit aV
Vecteur Produit_avec_un_reel_vecteur ( double a, Vecteur V);


// Produit scalaire entre V1 et V2
double produit_scalaire (Vecteur V1, Vecteur V2);


// Norme de V
double norme_vecteur (Vecteur V);


// vecteur correspondant au bipoint AB ∗/
Vecteur vect_bipoint ( Point A, Point B ) ;

// Renvoie le vecteur AB
Point point_bipoint ( Point A, Point B);

// distance entre P1 et P2
double distance_entre_points(Point P1, Point P2);

// Renvoie Vrai si les coordonnees de P1 sont egales a celles de P2 et Faux sinon.
int Points_egaux(Point P1, Point P2);

// Renvoie la distance entre le point P et le segment AB.
double distance_point_segment(Point P, Point A, Point B);

#endif