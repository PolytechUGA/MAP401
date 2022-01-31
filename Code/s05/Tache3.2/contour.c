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
            return SUD;
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


void ecrire_contour_fichier( Liste_Point L, FILE *f){
    int nb_contours = 1;
    fprintf(f, "%d\n", nb_contours);
    fprintf(f, "%d\n\n", L.taille);
    Cellule_Liste_Point *tmp;
    for (tmp = L.first; tmp->suiv != NULL; tmp = tmp->suiv){
        fprintf(f, " %f %f\n", tmp->data.x, tmp->data.y);
    }
}

Cellule_Liste_Point *creer_element_liste_Point(Point v)
{
    Cellule_Liste_Point *el ;
    el = (Cellule_Liste_Point *)malloc(sizeof(Cellule_Liste_Point )); 
    if (el==NULL){
        fprintf (stderr , "creer_element_liste_Point : allocation impossible\n");
        exit (-1); 
    }
    el->data = v; 
    el->suiv = NULL; 
    return el ;
}

// } Liste Point ;

Liste_Point creer_liste_Point_vide()
{
    Liste_Point L = {0, NULL, NULL}; 
    return L ;
}

Liste_Point ajouter_element_liste_Point(Liste_Point L, Point e)
{
    Cellule_Liste_Point *el ;
    el = creer_element_liste_Point(e); 
    if (L.taille == 0)
    {
        L.first = L.last = el;
    }
    else
    {
        L.last->suiv = el; L.last = el;
    }
    L. taille++;
    return L ; 
}

Liste_Point supprimer_liste_Point(Liste_Point L)
{
    Cellule_Liste_Point *el=L.first ;
    while (el){
        Cellule_Liste_Point *suiv = el->suiv;
        free(el);
        el=suiv;
    }

    L.first =L.last =NULL; 
    L.taille = 0;
    return L ;
}

Liste_Point concatener_liste_Point(Liste_Point L1, Liste_Point L2)
{

    if (L1.taille == 0) return L2; 
    if (L2.taille == 0) return L1;
    L1.last->suiv = L2.first ;
    L1.last = L2.last ;  
    L1.taille += L2.taille ; 
    return L1;
}

Tableau_Point sequence_points_liste_vers_tableau(Liste_Point L)
{
    Tableau_Point T;
    T.taille = L.taille ;
    T.tab = malloc(sizeof(Point) * T.taille );
    if (T.tab==NULL)
    {
        fprintf(stderr, "sequence_points_liste_vers_tableau : ");
        fprintf(stderr , " allocation impossible\n");
        exit (-1);
    }
    int k = 0;
    Cellule_Liste_Point *el = L.first ;
    while (el)
    {
    T.tab[k] = el->data; k++;
    el = el->suiv;
    }
    return T;
}

void ecrire_contour(Liste_Point L)
{
    Tableau_Point TP = sequence_points_liste_vers_tableau(L);
    int k;
    int nP = TP.taille ;
    printf("%d points : [", nP); 
    for (k = 0; k < nP; k++)
    {
        Point P = TP.tab[k];
        printf(" (%5.1f,%5.1f)", P.x, P.y);
    }
    printf( " ] \n" ) ;
    free (TP.tab );
}

int nombre_segment( Liste_Point L){
    return L.taille-1;
}