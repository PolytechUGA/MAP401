#ifndef _CALCUL_CONTOUR_H_
#define _CALCUL_CONTOUR_H_

#define STROKE 0
#define FILL 1


#include <stdio.h>
#include <stdlib.h>
#include "types_macros.h"
#include "image.h"
#include "geom2d.h"
#include "listes_chainees_points.h"
#include "listes_chainees_contours.h"
#include "ecriture_contours.h"

#define STROKE 0
#define FILL 1

typedef enum {NORD,  EST, SUD, OUEST} Orientation;

Orientation tourner_a_gauche(Orientation Orient);

Orientation tourner_a_droite(Orientation Orient);

Point trouver_pixel_depart(Image I);

void affiche_pos(Point position);

Orientation nouvelle_orientation(Image I, Point Pix, Orientation Orient);

Point avancer( Orientation Orient, Point Pos);

Liste_Point calcul_contour(Image I);

int nombre_segment( Liste_Point L);

Liste_Point all_pixels_valides(Image I);

Image cree_image_masque(Image I);

Liste_Point calcul_contour_I_masque(Image I, Image I_Masque, double i, double k);

// void ecriture_des_contours(Image I, Image I_Masque);

Liste_Contour extraction_des_contours(Image I, Image I_Masque);

#endif