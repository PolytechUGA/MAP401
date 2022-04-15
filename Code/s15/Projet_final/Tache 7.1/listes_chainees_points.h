#ifndef _LISTES_CHAINEES_POINTS_H_
#define _LISTES_CHAINEES_POINTS_H_

#include <stdio.h>
#include <stdlib.h>
#include "types_macros.h"
#include "image.h"
#include "geom2d.h"

// Module gérant des listes chainées de points

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

Cellule_Liste_Point *creer_element_liste_Point(Point v);

Liste_Point creer_liste_Point_vide();

Liste_Point ajouter_element_liste_Point(Liste_Point L, Point e);

Liste_Point supprimer_liste_Point(Liste_Point L);

Liste_Point concatener_liste_Point(Liste_Point L1, Liste_Point L2);

// Transforme une liste chainée de points en un tableau de points
Tableau_Point sequence_points_liste_vers_tableau(Liste_Point L);

// Renvoie le nombre de segments dans une liste de points
int nombre_segment( Liste_Point L);

#endif