#ifndef _LISTE_CONTOUR_BEZIER_H_
#define _LISTE_CONTOUR_BEZIER_H_

#include <stdio.h>
#include <stdlib.h>
#include "types_macros.h"
#include "image.h"
#include "geom2d.h"
#include "listes_chainees_points.h"
#include "listes_chainees_bezier.h"
#include "courbe_bezier.h"

typedef struct Cellule_Liste_Contour_bezier_
{
    Liste_Bezier3 contour_bezier;
    struct Cellule_Liste_Contour_bezier_ *suiv;
} Cellule_Liste_Contour_bezier;


typedef struct Liste_Contour_bezier_
{
   unsigned int nb_contour_bezier ;
   Cellule_Liste_Contour_bezier *first ;
   Cellule_Liste_Contour_bezier *last ;
} Liste_Contour_bezier;

Cellule_Liste_Contour_bezier *creer_element_liste_Contour_bezier(Liste_Bezier3 v);

Liste_Contour_bezier creer_liste_Contour_bezier_vide();

Liste_Contour_bezier ajouter_element_liste_Contour_bezier(Liste_Contour_bezier L, Liste_Bezier3 e);

Liste_Contour_bezier supprimer_liste_Contour_bezier(Liste_Contour_bezier L);

Liste_Contour_bezier concatener_liste_Contour_bezier(Liste_Contour_bezier L1, Liste_Contour_bezier L2);

int taille_liste_contours_bezier (Liste_Contour_bezier L);

#endif