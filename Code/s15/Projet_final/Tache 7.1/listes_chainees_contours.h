#ifndef _LISTES_CHAINEES_CONTOUR_H_
#define _LISTES_CHAINEES_CONTOUR_H_

#include <stdio.h>
#include <stdlib.h>
#include "types_macros.h"
#include "image.h"
#include "geom2d.h"
#include "listes_chainees_points.h"

// Module gérant les listes chainées de contours

typedef struct Cellule_Liste_Contour_
{
    Contour contour;
    struct Cellule_Liste_Contour_ *suiv;
} Cellule_Liste_Contour;


typedef struct Liste_Contour_
{
   unsigned int nb_contour ;
   Cellule_Liste_Contour *first ;
   Cellule_Liste_Contour *last ;
} Liste_Contour;

Cellule_Liste_Contour *creer_element_liste_Contour(Contour v);

Liste_Contour creer_liste_Contour_vide();

Liste_Contour ajouter_element_liste_Contour(Liste_Contour L, Contour e);

Liste_Contour supprimer_liste_Contour(Liste_Contour L);

Liste_Contour concatener_liste_Contour(Liste_Contour L1, Liste_Contour L2);

// Renvoie le nombre de contour dans la listes
int taille_liste_contours (Liste_Contour L);

#endif