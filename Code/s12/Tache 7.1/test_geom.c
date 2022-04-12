#include "geom2d.h"

int main(int argc, char **argv){
    Point A, B, C, D, E;
    Vecteur U, V1, V2, VR;
    A = set_point(1.0, -3.0);
    double x=3, norme, d;
     printf(" test set_point : ");
    if (A.x == 1.0 && A.y == -3.0){
        printf("Pass \n");
        printf("A = (%f,%f) \n", A.x, A.y);
    }
    else 
        printf("Fail \n");

     printf(" test set_point : ");
    B = set_point(4.0, 1.0);
    if(B.x==4.0 && B.y == 1.0 ){
        printf("Pass \n");
        printf("B = (%f,%f) \n", B.x, B.y);
    }
    else 
        printf("Fail \n");


    C = add_point(A,B);     /* -> C = (5.0, -2.0) */
    printf(" test somme de 2 points : ");
    if(C.x==5.0 && C.y == -2.0 ){
        printf("Pass \n");
        printf("C : somme de A et B  \t= (%f,%f) \n", C.x, C.y);   
    }
    else 
        printf("Fail \n");
    

    V1= set_vecteur(0.0, 2.0);
    V2 = set_vecteur (0.0, 4.0);
    printf(" test set_vecteur : ");
    if (V1.x == 0.0 && V1.y == 2.0)
        printf("Pass \n");
    else 
        printf("Fail \n");



    printf(" test add_vecteur : ");
    VR = add_vecteur(V1,V2);
    if (VR.x == 0.0 && VR.y == 6.0)
        printf("Pass \n");
    else 
        printf("Fail \n");


    printf(" test produit_avec_un_reel_vecteur : ");
    VR = Produit_avec_un_reel_vecteur(x,V1);
    if (VR.x == 0.0 && VR.y == 6.0)
        printf("Pass \n");
    else 
        printf("Fail \n");


    printf(" test vect_bipoint : ");
    U = vect_bipoint(A,B);  /* -> U = (-3.0, 4.0) */
    if(U.x==3.0 && U.y == 4.0 )
        printf("Pass \n");
    else 
        printf("Fail \n");

    printf(" test norme_vecteur : ");
    norme = norme_vecteur(V1);
    if (norme == 2)
        printf("Pass \n");
    else
        printf("Fail \n");
    
    D = set_point(0.0, 1.0);
    E = set_point(0.0, 2.0);
    
    printf(" test distance_entre_points: ");

    d = distance_entre_points(D, E);
    if(d == 1)
        printf("Pass \n");
    else 
        printf("Fail \n");
    
    printf(" test Produit_avec_un_reel_point: ");
    A = Produit_avec_un_reel_point(x, A);
    if(A.x == 3.0 && A.y == -9.0)
        printf("Pass \n");
    else 
        printf("Fail \n");
        
    
    printf(" test produit_scalaire: ");
    norme = produit_scalaire(V1, V2);
    if(norme == 8)
        printf("Pass \n");
    else 
        printf("Fail \n");
    
    return 0;
}