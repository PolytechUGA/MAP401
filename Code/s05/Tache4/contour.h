#ifndef _CONTOUR_H_
#define _CONTOUR_H_

#include <stdio.h>
#include <stdlib.h>
#include "types_macros.h"
#include "image.h"
#include "geom2d.h"


#define STROKE 0
#define FILL 1

typedef enum {NORD,  EST, SUD, OUEST} Orientation;

Orientation tourner_a_gauche(Orientation Orient);

Orientation tourner_a_droite(Orientation Orient);

Point trouver_pixel_depart(Image I);

void affiche_pos(Point position);

Orientation nouvelle_orientation(Image I, Point Pix, Orientation Orient);

Point avancer( Orientation Orient, Point Pos);

// unsigned int DIM_MAX = 1000;
// typedef Point TabPoints[1000];
// typedef struct Contour_{
//     unsigned int np; // nombre dans la sequence
//     TabPoints tab;   // tableau pour stocker les points 
// }Contour;

//
//Point set_point(double x, double y)
// {
//     Point P = {x,y}; 
//     return P;
// }

typedef struct Cellule_Liste_Point_
{
    Point data;
    struct Cellule_Liste_Point_ *suiv;
} Cellule_Liste_Point ;

typedef struct Liste_Point_
{
    unsigned int taille ;
    Cellule_Liste_Point *first ; 
    Cellule_Liste_Point *last ; 
} Liste_Point;

typedef Liste_Point Contour; 

typedef struct Tableau_Point_
{
    unsigned int taille ; 
    Point *tab; 
} Tableau_Point ;

Liste_Point calcul_contour(Image I);

Cellule_Liste_Point *creer_element_liste_Point(Point v);

Liste_Point creer_liste_Point_vide();

Liste_Point ajouter_element_liste_Point(Liste_Point L, Point e);

Liste_Point supprimer_liste_Point(Liste_Point L);

Liste_Point concatener_liste_Point(Liste_Point L1, Liste_Point L2);

Tableau_Point sequence_points_liste_vers_tableau(Liste_Point L);

void ecrire_contour(Liste_Point L);

void ecrire_contour_fichier( Liste_Point L, FILE *f);

int nombre_segment( Liste_Point L);

void ecriture_fichier_EPS(FILE *f, int mode, Image Image, Liste_Point L);

#endif