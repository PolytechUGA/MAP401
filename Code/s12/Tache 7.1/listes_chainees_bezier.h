#ifndef _LISTES_CHAINEES_BEZIER_H_
#define _LISTES_CHAINEES_BEZIER_H_

#include <stdio.h>
#include <stdlib.h>
#include "types_macros.h"
#include "image.h"
#include "geom2d.h"
#include "courbe_bezier.h"

typedef struct Cellule_Liste_Bezier3_
{
    Bezier3 B;
    struct Cellule_Liste_Bezier3_ *suiv;
} Cellule_Liste_Bezier3;


typedef struct Liste_Bezier3_
{
   unsigned int nb_Bezier3 ;
   Cellule_Liste_Bezier3 *first ;
   Cellule_Liste_Bezier3 *last ;
} Liste_Bezier3;

Cellule_Liste_Bezier3 *creer_element_liste_Bezier3(Bezier3 v);

Liste_Bezier3 creer_liste_Bezier3_vide();

Liste_Bezier3 ajouter_element_liste_Bezier3(Liste_Bezier3 L, Bezier3 e);


Liste_Bezier3 supprimer_liste_Bezier3(Liste_Bezier3 L);

Liste_Bezier3 concatener_liste_Bezier3(Liste_Bezier3 L1, Liste_Bezier3 L2);

int taille_liste_Bezier3 (Liste_Bezier3 L);

#endif