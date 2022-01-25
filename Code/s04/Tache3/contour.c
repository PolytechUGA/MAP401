#include "contour.h"

Orientation tourner_a_gauche(Orientation Orient){
    switch (Orient){
        case NORD:
            return OUEST;
        case EST:
            return NORD;
        case SUD:
            return EST;
        case OUEST:
            return NORD;
    }
}

Orientation tourner_a_droite(Orientation Orient){
    switch(Orient){
        case NORD:
            return EST;
        case SUD:
            return OUEST;
        case EST:
            return SUD;
        case OUEST:
            return NORD;
    }
}

Point trouver_pixel_depart(Image I){
    Point P;
    // tab[x-1+L*(y-1)]
    for (int i = 1 ; i<= I.H; i++){
        for (int k  = 1 ; k <= I.L; k++){
            if (i==1 && I.tab[k-1+I.L*(i-1)] == NOIR){
                P = set_point(k,i);
                return P;
            }
            else if (I.tab[k-1+I.L*(i-1)] == NOIR && I.tab[k-1+I.L*(i-2)] == BLANC){
                P = set_point(k,i);
                return P;
            }
        }
    }
    return set_point(0.0,0.0);
}

void affiche_pos(Point position){
    printf("Position du point rouge: (%f, %f)\n", position.x, position.y);
}

Orientation nouvelle_orientation(Image I, Point Pix, Orientation Orient){
    Pixel pG, pD;
    switch (Orient){
        case NORD:
            pG = get_pixel_image(I, Pix.x, Pix.y);
            pD = get_pixel_image(I, Pix.x+1, Pix.y);
            break;
        case SUD:
            pG = get_pixel_image(I, Pix.x+1, Pix.y+1);
            pD = get_pixel_image(I, Pix.x, Pix.y+1);
            break;
        case OUEST:
            pG = get_pixel_image(I, Pix.x, Pix.y+1);
            pD = get_pixel_image(I, Pix.x, Pix.y);
            break;
        case EST:
            pG = get_pixel_image(I, Pix.x+1, Pix.y);
            pD = get_pixel_image(I, Pix.x+1, Pix.y+1);
            break;
    }

    if (pG == NOIR){
        //tourner d'un quart de tour vers la gauche
        return tourner_a_gauche(Orient);
    }
    else if (pD == BLANC){
        //tourner d'un quart de tour sur la droite
        return tourner_a_droite(Orient);
    }
    return Orient;
}

Point avancer( Orientation Orient, Point Pos){
    switch (Orient){
        case NORD:
            return set_point(Pos.x, Pos.y-1);
        case SUD:
            return set_point(Pos.x, Pos.y+1);
        case EST:
            return set_point(Pos.x+1, Pos.y);
        case OUEST:
            return set_point(Pos.x-1, Pos.y);
    }
}

void calcul_contour(Image I){
    Point Pix, P_init, position;
    int Boucle;
    Orientation Orient = EST;
    Boucle = 1;
    Pix = trouver_pixel_depart(I);
    if (Pix.x == 0.0 && Pix.y == 0.0){
        printf("Image blanche\n");
        return;
    }
    P_init = set_point(Pix.x-1, Pix.y - 1);
    position = P_init;

    while ( Boucle == 1){
        affiche_pos(position);
        position = avancer(Orient, position);
        Orient = nouvelle_orientation(I, position, Orient);
        if (Points_egaux(position, P_init) && Orient == EST)
            Boucle = 0;
    }
    affiche_pos(position);
}



