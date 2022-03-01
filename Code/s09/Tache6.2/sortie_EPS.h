#ifndef _SORTIE_EPS_H_
#define _SORTIE_EPS_H_

#include "types_macros.h"
#include "image.h"
#include "listes_chainees_points.h"
#include "calcul_contour.h"
#include "geom2d.h"


void ecriture_fichier_EPS(FILE *f, int mode, Image Image, Liste_Point L);

void ecriture_fichier_EPS_tache5(FILE *f, int mode, Image Image, Liste_Contour L);


#endif