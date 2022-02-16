#############################################################################
# Fichier Makefile 
# UE MAP401 - DLST - UGA - 2020/2021
#############################################################################
# utilisation des variables internes $@ $< $^ $*
# $@ : correspond au nom de la cible
# $< : correspond au nom de la premiere dependance
# $^ : correspond � toutes les d�pendances
# $* : correspond au nom du fichier sans extension 
#       (dans les regles generiques uniquement)
#############################################################################
# information sur la regle executee avec la commande @echo
# (une commande commancant par @ n'est pas affichee a l'ecran)
#############################################################################


#############################################################################
# definition des variables locales
#############################################################################

# compilateur C
CC = clang

# chemin d'acces aux librairies (interfaces)
INCDIR = .

# chemin d'acces aux librairies (binaires)
LIBDIR = .

# options pour l'�dition des liens
LDOPTS = -L$(LIBDIR) -lm

# options pour la recherche des fichiers .o et .h
INCLUDEOPTS = -I$(INCDIR)

# options de compilation
COMPILOPTS = -g -Wall $(INCLUDEOPTS)

# liste des executables
EXECUTABLES = distance_pts_seg ecrire_liste_contours


#############################################################################
# definition des regles
#############################################################################

########################################################
# la r�gle par d�faut
all : $(EXECUTABLES)

########################################################
# regle generique : 
#  remplace les regles de compilation separee de la forme
#	module.o : module.c module.h
#		$(CC) -c $(COMPILOPTS) module.c
%.o : %.c %.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module "$*
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

########################################################
# regles explicites de compilation separee de modules
# n'ayant pas de fichier .h ET/OU dependant d'autres modules
image.o : image.c image.h types_macros.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module image"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<


geom2d.o : geom2d.c geom2d.h 
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module geom2d"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<


calcul_contour.o : calcul_contour.c calcul_contour.h types_macros.h image.h geom2d.h listes_chainees_points.h listes_chainees_contours.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module calcul_contour"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

listes_chainees_points.o : listes_chainees_points.c listes_chainees_points.h types_macros.h image.h geom2d.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module listes_chainees_points"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

listes_chainees_contours.o : listes_chainees_contours.c listes_chainees_contours.h listes_chainees_points.h types_macros.h image.h geom2d.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module listes_chainees_contours"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

sortie_EPS.o : sortie_EPS.c sortie_EPS.h types_macros.h image.h calcul_contour.h listes_chainees_points.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module sortie_EPS"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

ecriture_contours.o : ecriture_contours.c ecriture_contours.h types_macros.h image.h geom2d.h listes_chainees_points.h listes_chainees_contours.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module ecriture_contours"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

ecrire_liste_contours.o : ecrire_liste_contours.c calcul_contour.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module ecrire_liste_contours"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<
########################################################
# regles explicites de creation des executables

distance_pts_seg.o : distance_pts_seg.c geom2d.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module distance_pts_seg"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

distance_pts_seg : distance_pts_seg.o geom2d.o

	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

ecrire_liste_contours : ecrire_liste_contours.o ecriture_contours.o image.o geom2d.o sortie_EPS.o listes_chainees_contours.o listes_chainees_points.o calcul_contour.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@


# regle pour "nettoyer" le r�pertoire
clean:
	rm -fR $(EXECUTABLES) *.o 
