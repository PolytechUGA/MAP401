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


Bezier2 cree_Bezier2(){
    Bezier2 B;
    Point P0;
    P0.x = 0;
    P0.y= 0;
    B.C0 = P0;
    B.C1 = P0;
    B.C2 = P0;
    return B;
}

//(1-t)²C0 + 2t(1-t)C1 + C2t²
Point C_Bezier2(Bezier2 B, double t){
    Point P1,P2,P3,R;
    double coef0, coef1, coef2;
    coef0 = (1-t)*(1-t);
    coef1 = 2*t*(1-t);
    coef2 = t*t;

    P1 = Produit_avec_un_reel_point(coef0, B.C0);
    P2 = Produit_avec_un_reel_point(coef1, B.C1 );
    P3 = Produit_avec_un_reel_point(coef2, B.C2);
    R = add_point(P1, P2);
    R = add_point(R, P3);
    return R;
}

Bezier3 creer_Bezier3(){
    Bezier3 B3;
    Point P0;
    P0.x = 0;
    P0.y = 0;
    B3.C0 = P0;
    B3.C1 = P0;
    B3.C2 = P0;
    return B3;
}
//(1-t)³C0 + 3t(1-t)²C1 + 3t²(1-t)C2 + t² C3
Point C_Bezier3(Bezier3 B, double t){
    Point P0, P1,P2,P3,R;
    double coef0, coef1, coef2, coef3;
    coef0 = (1-t)*(1-t)*(1-t);
    coef1 = 3*t*(1-t)*(1-t);
    coef2 = 3*t*t*(1-t);
    coef3 = t*t;

    P0 = Produit_avec_un_reel_point(coef0, B.C0);
    P1 = Produit_avec_un_reel_point(coef1, B.C1);
    P2 = Produit_avec_un_reel_point(coef2, B.C2);
    P3 = Produit_avec_un_reel_point(coef3, B.C3);
    R = add_point(P0, P1);
    R = add_point(R, P2);
    R = add_point(R, P3);
    return R;
}

Bezier3 Conversion_B2_B3(Bezier2 B){
    Bezier3 B3 = creer_Bezier3();
    B3.C0 = B.C0;

    B3.C1 = Produit_avec_un_reel_point(2, B.C1);
    B3.C1 = add_point(B.C0, B3.C1);
    B3.C1 = Produit_avec_un_reel_point(1/3, B3.C1);

    B3.C2 = Produit_avec_un_reel_point(2, B.C1);
    B3.C2 = add_point(B3.C2, B.C2);
    B3.C2 = Produit_avec_un_reel_point(1/3, B3.C2);

    B3.C3 = B3.C2;
    return B3;
}

