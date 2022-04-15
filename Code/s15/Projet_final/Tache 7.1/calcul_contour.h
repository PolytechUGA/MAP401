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

// Fonction qui prend en argument une orientation et modifie cette orientation vers la gauche
Orientation tourner_a_gauche(Orientation Orient);


// Fonction qui prend en argument une orientation et modifie cette orientation vers la droite
Orientation tourner_a_droite(Orientation Orient);

// Renvoie le premier pixel noir tel que celui-ci marque le debut d'un contour.
Point trouver_pixel_depart(Image I);

// Affiche les coordonnees du point donne en argument
void affiche_pos(Point position);

// Met a jour l'orientation d'un point en fonction des pixels gauche et droite devant lui.
Orientation nouvelle_orientation(Image I, Point Pix, Orientation Orient);

// Permet de faire avancer le robot en fonction de l'orientation dans laquelle il se trouve 
Point avancer( Orientation Orient, Point Pos);

// Renvoie une liste de point formant un contour de l'image I.
Liste_Point calcul_contour(Image I);

// Renvoie le nombre de segments dans une liste de points
int nombre_segment( Liste_Point L);

// Renvoie tous les pixels noir tels que le pixel nord est
// blanc (sert a former l'image de masque)
Liste_Point all_pixels_valides(Image I);

// Fonction qui prend une Image et renvoie le masque de celle-ci grâce aux fonctions définis précédement
Image cree_image_masque(Image I);

// Fonction qui calcul le contour et met à jour l'image de masque.
Liste_Point calcul_contour_I_masque(Image I, Image I_Masque, double i, double k);

// Renvoie la liste des contours de l'image I, en appelant la fonction ci-dessus
// pour mettre a jour l'image de masque au fur et a mesure.
Liste_Contour extraction_des_contours(Image I, Image I_Masque);

#endif