#ifndef _DOUGLAS_PEUCKER_H_
#define _DOUGLAS_PEUCKER_H_

#include "listes_chainees_bezier.h"
#include "geom2d.h"
#include "listes_chainees_points.h"
#include "courbe_bezier.h"
#include "liste_contour_bezier.h"

Liste_Point algo_Douglas_Peucker(Liste_Point C, int j1, int j2, double d);

Liste_Bezier3 simplification_douglas_peucker_bezier2(Tableau_Point CONT, int j1, int j2, double d);
// Ajouts :
// Ajout d'un nouveau type Courbe de bezier pour garder le même algorithme avec les listes chainées de courbes de bezier.  
// On a supprimé la partie qui retire le dernier élément de la liste 1 au moment de la concaténation, qui n'avait plus de sens ici.

// Fonction similaire à celle ci-dessus mais on a retiré la convertion de Bézier 2 en Bézier 3 et on a transformé les types 
// pour les adapter au Bézier 3.
Liste_Bezier3 simplification_douglas_peucker_bezier3(Tableau_Point CONT, int j1, int j2, double d);


#endif 