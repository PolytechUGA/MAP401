#include <stdio.h>
#include "geom2d.h"
#include <math.h>

Point set_point ( double x , double y ){
    Point P = {x,y} ;
    return P ;
}

Vecteur set_vecteur ( double x , double y ){
    Vecteur V = {x,y} ;
    return V ;
}



Point add_point ( Point P1 , Point P2 ){
    return set_point ( P1.x+P2.x , P1.y+P2.y ) ;
}

Vecteur add_vecteur ( Vecteur V1, Vecteur V2){
    return set_vecteur ( V1.x+V2.x , V1.y+V2.y ) ;
}



Point Produit_avec_un_reel_point ( double a, Point P){
    return set_point ( a* P.x, a* P.y);
}

Vecteur Produit_avec_un_reel_vecteur ( double a, Vecteur V){
    return set_vecteur ( a* V.x, a* V.y);
}



double produit_scalaire (Vecteur V1, Vecteur V2){
    return V1.x*V2.x + V1.y*V2.y;
}

//ALBIN CHANGE

Vecteur vect_bipoint ( Point A, Point B){
    Vecteur V = {B.x-A.x , B.y-A.y } ;
    return V;
}

double norme_vecteur (Vecteur V){
    return sqrt((V.x*V.x)  +  (V.y*V.y));
}

double distance_entre_points(Point P1, Point P2){
    double a = (P1.x - P2.x) * (P1.x - P2.x);
    double b = (P1.y - P2.y) * (P1.y - P2.y);
    return sqrt ( a + b );
}


