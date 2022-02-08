#ifndef _ECRITURE_CONTOURS_H_
#define _ECRITURE_CONTOURS_H_

#include <stdio.h>
#include <stdlib.h>
#include "types_macros.h"
#include "image.h"
#include "geom2d.h"
#include "listes_chainees_points.h"
#include "listes_chainees_contours.h"

void ecrire_liste_point_fichier( Liste_Point L, FILE *f);

void ecrire_contour_fichier_contours(Liste_Contour L, FILE *f);

void ecrire_contour(Liste_Point L);

void affichage_ecran (Liste_Contour L);
#endif