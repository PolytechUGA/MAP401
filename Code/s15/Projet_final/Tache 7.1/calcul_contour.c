#include "calcul_contour.h"

Orientation tourner_a_gauche(Orientation Orient){
    switch (Orient){
    // On modifie l'orientation en fonction de celle de base
        case NORD:
            return OUEST;
        case EST:
            return NORD;
        case SUD:
            return EST;
        case OUEST:
            return SUD;
    }
}

Orientation tourner_a_droite(Orientation Orient){
    // On modifie l'orientation en fonction de celle de base
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
    for (int i = 1 ; i<= hauteur_image(I); i++){
        for (int k  = 1 ; k <= largeur_image(I); k++){
            // Pour chaque pixel de l'image
            if (i==1 && get_pixel_image(I, k, i)){
                // Si On est sur la première ligne, et qu'on troue un pixel noir, on le renvoie
                P = set_point(k,i);
                return P;
            }
            else if (get_pixel_image(I, k, i) == NOIR && get_pixel_image(I, k, i-1) == BLANC){
                // Si on trouve un pixel noir avec un pixel blanc au dessus on le renvoie
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
    if (pG == BLANC && pD==BLANC){
        //tourner d'un quart de tour vers la gauche
        return tourner_a_droite(Orient);
    }
    else if (pG == NOIR){
        //tourner d'un quart de tour sur la droite
        return tourner_a_gauche(Orient);
    }
    
    return Orient; // cas pG == BLANC && pD==NOIR
}

Point avancer( Orientation Orient, Point Pos){
    // Les coordonnées sont mis à jour en fonction de son orientation
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

Liste_Point calcul_contour(Image I){
    Point Pix, P_init, position;
    Liste_Point L = creer_liste_Point_vide();
    int Boucle;
    Orientation Orient = EST;
    Boucle = 1;
    Pix = trouver_pixel_depart(I);
    if (Pix.x == 0.0 && Pix.y == 0.0){
        printf("Image blanche\n");
        return L;
    }
    P_init = set_point(Pix.x-1, Pix.y - 1);
    position = P_init;

    while ( Boucle == 1){
        L = ajouter_element_liste_Point(L , position);
        position = avancer(Orient, position);
        Orient = nouvelle_orientation(I, position, Orient);
        if (Points_egaux(position, P_init) && Orient == EST){
            Boucle = 0;
        }
    }
    L = ajouter_element_liste_Point(L , position);
    return L;
}

int nombre_segment( Liste_Point L){
    return L.taille-1;
}

Liste_Point all_pixels_valides(Image I){
    Liste_Point L = creer_liste_Point_vide();
    for (double i = 1 ; i<= hauteur_image(I); i++){
        for (double k  = 1 ; k <= largeur_image(I); k++){
            if (i==1 && get_pixel_image(I, k, i) == NOIR){
                L = ajouter_element_liste_Point (L, set_point(k,i));
            }
            else if (get_pixel_image(I, k, i) == NOIR && get_pixel_image(I, k, i-1) == BLANC){
                L = ajouter_element_liste_Point (L, set_point(k,i));
            }
        }
    }
    return L;
}

Image cree_image_masque(Image I){
    Image I_masque   = creer_image(largeur_image (I), hauteur_image (I));
    Liste_Point L;
    L = all_pixels_valides(I);
    Cellule_Liste_Point *cel= L.first;
    set_pixel_image(I_masque, cel->data.x,cel->data.y, NOIR );
    while (cel->suiv!= NULL){
        cel = cel->suiv;
        set_pixel_image(I_masque, cel->data.x,cel->data.y, NOIR );
    }
    return I_masque;
}

Liste_Point calcul_contour_I_masque(Image I, Image I_Masque, double k, double i){
    Point Pix, P_init, position;
    Liste_Point L = creer_liste_Point_vide();
    int Boucle;
    Orientation Orient = EST;
    Boucle = 1;
    Pix = set_point (k, i);
    P_init = set_point(Pix.x-1, Pix.y-1);
    position = P_init;
    while ( Boucle == 1){
        L = ajouter_element_liste_Point(L , position);
        if (Orient == EST){
            set_pixel_image(I_Masque, position.x+1, position.y+1, BLANC);
        }
        position = avancer(Orient, position);
        Orient = nouvelle_orientation(I, position, Orient);
        if (Points_egaux(position, P_init) && Orient == EST){
            Boucle = 0;
        }
    }
    L = ajouter_element_liste_Point(L , position);
    return L;
}

Liste_Contour extraction_des_contours(Image I, Image I_Masque){
    Liste_Contour L_Contour = creer_liste_Contour_vide();
    Liste_Point L_Point = creer_liste_Point_vide();
    int l,h;
    h = hauteur_image(I);
    l = largeur_image(I);
    for (double i = 1 ; i<= h; i++){
        for (double k  = 1 ; k <= l; k++){
            if (get_pixel_image(I_Masque, k, i) == NOIR){
                L_Point = calcul_contour_I_masque(I, I_Masque, k, i);
                L_Contour = ajouter_element_liste_Contour(L_Contour, L_Point);
            }
        }
    }
    return L_Contour;
}
