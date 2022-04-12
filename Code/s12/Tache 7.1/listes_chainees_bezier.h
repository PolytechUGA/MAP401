#ifndef _LISTES_CHAINEES_BEZIER_H_
#define _LISTES_CHAINEES_BEZIER_H_

#include <stdio.h>
#include <stdlib.h>
#include "types_macros.h"
#include "image.h"
#include "geom2d.h"
#include "courbe_bezier.h"

// Cellule d'une liste chainee de courbe de Bezier comprenant une courbe de bezier
// et le pointeur vers la cellule suivante.
typedef struct Cellule_Liste_Bezier3_
{
    Bezier3 B;
    struct Cellule_Liste_Bezier3_ *suiv;
} Cellule_Liste_Bezier3;

// Liste chainee de courbe de bezier comprenant le nombre de courbe de bezier qu'elle abrite
// ainsi qu'un pointeur vers la premiere cellule de la liste et un second vers le dernier element de la liste
typedef struct Liste_Bezier3_
{
   unsigned int nb_Bezier3 ;
   Cellule_Liste_Bezier3 *first ;
   Cellule_Liste_Bezier3 *last ;
} Liste_Bezier3;

// Renvoie une cellule de liste chainee de courbe de bezier, a partir d'une courbe de bezier de degre 3.
Cellule_Liste_Bezier3 *creer_element_liste_Bezier3(Bezier3 v);

// Creer une liste chainee de courbe de bezier de degre 3 vide la renvoie.
Liste_Bezier3 creer_liste_Bezier3_vide();

// Recoie une courbe de bezier de degre 3, une courbe de bezier de degre 3 et revoie la courbe de 
// bezier de degre 3 a laquelle on a rajoute la courbe.
Liste_Bezier3 ajouter_element_liste_Bezier3(Liste_Bezier3 L, Bezier3 e);

// supprime tout les elements d'une liste chainee de courbe de bezier de degre 3 et la renvoie.
Liste_Bezier3 supprimer_liste_Bezier3(Liste_Bezier3 L);

// Concatene les deux listes chainees donnees en argument et renvoie le resultat.
Liste_Bezier3 concatener_liste_Bezier3(Liste_Bezier3 L1, Liste_Bezier3 L2);

// Renvoie le nombre de courbe de bezier de degre 3  stockee dans la liste.
int taille_liste_Bezier3 (Liste_Bezier3 L);

#endif