#include "geom2d.h"

int main(int argc, char **argv){
    Point A, B, C;
    Vecteur U;
    A = set_point(1.0, -3.0);
    printf("A = (%f,%f) \n", A.x, A.y);
    B = set_point(4.0, 1.0);
    printf("B = (%f,%f) \n", B.x, B.y);
    C = add_point(A,B);     /* -> C = (5.0, -2.0) */
    printf("C : somme de A et B  \t= (%f,%f) \n", C.x, C.y);
    U = vect_bipoint(C,A);  /* -> U = (-4.0, -1.0) */
    printf("D : vecteur entre A et B = (%f,%f) \n", U.x, U.y);
    return 0;
}