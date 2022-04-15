#ifndef _ECRITURE_CONTOURS_H_
#define _ECRITURE_CONTOURS_H_

#include <stdio.h>
#include <stdlib.h>
#include "types_macros.h"
#include "image.h"
#include "geom2d.h"
#include "listes_chainees_points.h"
#include "listes_chainees_contours.h"

// ecrit dans le fichier rentrer en parametre les coordonnees de tout les points de la liste L.
void ecrire_liste_point_fichier( Liste_Point L, FILE *f);

// Ecrit dans le fichier rentrer en parametre les coordonnees de tout les points de tout les contours de la liste L.
void ecrire_contour_fichier_contours(Liste_Contour L, FILE *f);

// Affiche dans le terminal les coordonnees de tous les points d'un contour.
void ecrire_contour(Liste_Point L);

// Affiche à l'écran le nombre de ségments et le nombre de contours dans la liste L
void affichage_ecran (Liste_Contour L);
#endif