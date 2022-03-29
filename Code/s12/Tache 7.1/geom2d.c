#include "geom2d.h"


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

Vecteur vect_bipoint ( Point A, Point B){
    Vecteur V = {B.x-A.x , B.y-A.y } ;
    return V;
}

Point point_bipoint ( Point A, Point B){
    Point V = {B.x-A.x , B.y-A.y } ;
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


int Points_egaux(Point P1, Point P2){
    return (P1.x == P2.x && P1.y == P2.y);
}

double distance_point_segment(Point P, Point A, Point B){
    if (Points_egaux(A, B)){
        return distance_entre_points(A, P);
    } else {
        
    }
    Vecteur AP = vect_bipoint(A,P);
    Vecteur AB = vect_bipoint(A,B);
    double lambda = produit_scalaire (AP, AB) / produit_scalaire (AB, AB);

    if (lambda <0){
        return distance_entre_points(A, P);
    } else if(lambda <= 1){
        Point Q = Produit_avec_un_reel_point (-1, A);
        Q = add_point(B,Q);
        Q = Produit_avec_un_reel_point (lambda, Q);
        Q = add_point(A,Q);
        return distance_entre_points(Q, P);
    } else {
        return distance_entre_points(B, P);
    }
}

