#ifndef _DOUGLAS_PEUCKER_H_
#define _DOUGLAS_PEUCKER_H_


#include "geom2d.h"
#include "listes_chainees_points.h"
#include "courbe_bezier.h"

Liste_Point algo_Douglas_Peucker(Liste_Point C, int j1, int j2, double d);

Liste_Point simplification_douglas_peucker_bezier2(Tableau_Point CONT, int j1, int j2, int d);


#endif 