#ifndef _SORTIE_EPS_H_
#define _SORTIE_EPS_H_

#include "types_macros.h"
#include "image.h"
#include "listes_chainees_points.h"
#include "calcul_contour.h"
#include "geom2d.h"
#include "liste_contour_bezier.h"


// écrit dans un fichier la sortie EPS pour la tâche 4. Cette fonction produit une sortie EPS d'un seul contour
// avec une liste de point
void ecriture_fichier_EPS(FILE *f, int mode, Image Image, Liste_Point L);

// écrit dans un fichier la sortie EPS pour la tâche 5. Cette fonction produit une sortie EPS de plusieurs contour
// avec une liste de contours
void ecriture_fichier_EPS_tache5(FILE *f, int mode, Image Image, Liste_Contour L);

// On a modifié la fonction ci-dessus pour qu'elle recoive une liste de liste de courbe
// et qu'elle écrive des courbes de bezier3 dans le fichier de sortie.
void ecriture_fichier_EPS_bezier3(FILE *f, int mode, Image Image, Liste_Contour_bezier L);


#endif