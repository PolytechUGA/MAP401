#include <stdio.h>
#include "geom2d.h"

int main(int argc, char *argv[]){
    double P_x, P_y, B_x, B_y, A_x, A_y;
    Point P,A,B;
    printf("Entrer la coordonnée x de P : \n");
    scanf(" %lf", &P_x);
    printf("Entrer la coordonnée y de P : \n");
    scanf(" %lf", &P_y);
    printf("Entrer la coordonnée x de A : \n");
    scanf(" %lf", &A_x);
    printf("Entrer la coordonnée y de A : \n");
    scanf(" %lf", &A_y);
    printf("Entrer la coordonnée x de B : \n");
    scanf(" %lf", &B_x);
    printf("Entrer la coordonnée y de B : \n");
    scanf(" %lf", &B_y);
    P = set_point(P_x,P_y);
    A = set_point(A_x, A_y);
    B = set_point(B_x, B_y);
    
    double d = distance_point_segment(P,A,B);
    printf("La distance entre les points est : %f\n", d);
    return 0;

}
