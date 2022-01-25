#ifndef _CONTOUR_H_
#define _CONTOUR_H_

#include <stdio.h>
#include "types_macros.h"
#include "image.h"
#include "geom2d.h"

typedef enum {NORD, SUD, EST, OUEST} Orientation;

Orientation tourner_a_gauche(Orientation Orient);

Orientation tourner_a_droite(Orientation Orient);

Point trouver_pixel_depart(Image I);

void affiche_pos(Point position);

Orientation nouvelle_orientation(Image I, Point Pix, Orientation Orient);

Point avancer( Orientation Orient, Point Pos);

void calcul_contour(Image I);





#endif