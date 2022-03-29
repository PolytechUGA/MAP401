#include "courbe_bezier.h"



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

Bezier2 approx_bezier2(Tableau_Point L, int j1, int j2){
    double n = (double)(j2 - j1);
    Bezier2 B = cree_Bezier2();
    if (n == 1){
        B.C0 = L.tab[j1];
        B.C2 = L.tab[j2];
        B.C1 = Produit_avec_un_reel_point(1/2, add_point(B.C0, B.C2));
    }
    else {
        double alpha = (3*n)/(n*n-1);
        double beta = (1-2*n)/(2*(n+1));
        Point somme = set_point(0, 0);
        for (int i = 1; i<n; i++){
            somme = add_point(somme, L.tab[i+j1]);
        }
        B.C1 = add_point(Produit_avec_un_reel_point(alpha, somme), Produit_avec_un_reel_point(beta, add_point(L.tab[j1], L.tab[j2])));
    }
    return B;
}

double distance_point_bezier2(Point Pj, Bezier2 B, double ti){
    return distance_entre_points(C_Bezier2(B, ti), Pj);
}

double calcul_alpha( double n ){
    double numerateur = -(15*n*n*n) + (5*n*n) + (2*n) + 4;
    double denominateur = 3 * (n + 2) * ((3* n * n ) + 1);
    return numerateur/denominateur;
}


double calcul_beta(double n){
    double numerateur = (10*n*n*n) - (15*n*n) + n + 2;
    double denominateur = 3 * (n + 2) * ((3* n * n ) + 1);
    return numerateur/denominateur;
}

double calcul_lamda(double n){
    double numerateur = (70*n);
    double denominateur = 3 * ((n*n) - 1) * ((n*n) - 4) * (3*(n*n) + 1);
    return numerateur/denominateur;
}

double calcul_gama(double k, double n){
    return ( (6*k*k*k*k) -  (8*n*k*k*k) + (6*k*k) - (4*n*k) + (n*n*n*n)  - (n*n) );
}

Bezier3 approx_bezier3(Tableau_Point L, int j1, int j2){
    double n = (double) (j2 - j1);
    Bezier3 B = creer_Bezier3();
    if (n < 3 ){
        Bezier2 B2 = approx_bezier2(L, j1, j2);
        B = Conversion_B2_B3 (B2);
    } else {
        B.C0 = L.tab[j1];
        B.C3 = L.tab[j2];
        Point C1 = Produit_avec_un_reel_point(calcul_alpha(n),B.C0);
        Point somme = set_point(0, 0);
        for (int i = 1; i<n; i++){
            somme =  add_point(somme, Produit_avec_un_reel_point( calcul_gama(i, n)  , L.tab[i+j1] ) );
        }
        somme = Produit_avec_un_reel_point (calcul_lamda(n) , somme);
        somme = add_point (somme, C1);
        C1 = Produit_avec_un_reel_point(calcul_beta(n),B.C3);
        B.C1 = add_point (somme, C1);
        

        Point C2 = Produit_avec_un_reel_point(calcul_beta(n),B.C0);
        somme = set_point(0, 0);
        for (int i = 1; i<n; i++){
            somme =  add_point(somme, Produit_avec_un_reel_point( calcul_gama(n - i, n)  , L.tab[i+j1] ) );
        }
        somme = Produit_avec_un_reel_point (calcul_lamda(n) , somme);
        somme = add_point (somme, C2);
        C2 = Produit_avec_un_reel_point(calcul_alpha(n),B.C3);
        B.C2 = add_point (somme, C2);
    }
    return B;
}

double distance_point_bezier3(Point Pj, Bezier3 B, double ti){
    return distance_entre_points(C_Bezier3(B, ti), Pj);
}
