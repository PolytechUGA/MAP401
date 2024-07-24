# Vectorisation et Simplification d'Image Bitmap

Ce projet implémente divers algorithmes pour la vectorisation et la simplification d'images bitmap. Il comprend plusieurs modules pour le traitement d'images, la gestion de géométrie en 2D, l'extraction de contours, et la simplification de contours à l'aide de segments ou de courbes de Bézier.

## Table des matières

- [Modules](#modules)
  - [Module Image](#module-image)
  - [Module Geom2d](#module-geom2d)
  - [Extraction de Contour](#extraction-de-contour)
  - [Sortie au format PostScript encapsulé](#sortie-au-format-postscript-encapsulé)
  - [Simplification de Contour](#simplification-de-contour)
- [Installation](#installation)
- [Usage](#usage)
  - [Exécuter les tests](#exécuter-les-tests)
- [Optimisations](#optimisations)
- [Auteurs](#auteurs)

## Modules

### Module Image

Ce module permet de manipuler des images bitmap. Les fonctionnalités incluent :

- Calcul du négatif d'une image.
- Affichage d'une image dans le terminal.
- Sauvegarde d'une image.

Pour tester ce module :
```bash
./test_image image.pbm
```

### Module Geom2d

Ce module gère la géométrie en 2D, incluant les types Point et Vecteur et des opérations sur ces types comme la somme, le produit scalaire, et la distance.

Pour tester ce module :

```bash
./test_geom
```

### Extraction de Contour

Ce module extrait les contours d'une image et les stocke dans une liste. Il inclut également un module pour écrire les contours extraits dans un fichier ou les afficher dans le terminal.

Pour tester l'extraction de contour :

```bash
./test_contour image.pbm image.txt
```

### Sortie au format PostScript encapsulé

Ce module permet de convertir une image bitmap en format EPS (Encapsulated PostScript) pour visualisation.

Pour tester ce module :

```bash
./test_EPS image.pbm image.EPS
```

### Simplification de Contour

Ce module contient deux méthodes de simplification de contour : par segments et par courbes de Bézier (degré 2 et 3).
Par Segments

Pour simplifier un contour par segments :

```bash
./simplification_par_segment image.pbm mode distance image.EPS
```
Par Courbes de Bézier

Pour simplifier un contour par courbes de Bézier de degré 2 :

```bash
./simplification_par_bezier2 image.pbm mode distance image.EPS
```

Pour simplifier un contour par courbes de Bézier de degré 3 :

```bash
./simplification_par_bezier3 image.pbm mode distance image.EPS
```
## Installation

Clonez le dépôt et compilez les programmes :

```bash
make
```

## Usage

Pour exécuter les programmes, utilisez les commandes mentionnées ci-dessus pour chaque module.

### Exécuter les tests

Des programmes de test sont inclus pour chaque module. Utilisez les commandes suivantes pour exécuter les tests :

```bash
./test_image image.pbm
./test_geom
./test_contour image.pbm image.txt
./test_EPS image.pbm image.EPS
./simplification_par_segment image.pbm mode distance image.EPS
./simplification_par_bezier2 image.pbm mode distance image.EPS
./simplification_par_bezier3 image.pbm mode distance image.EPS
```

## Optimisations

L'algorithme de simplification a été optimisé pour transformer la liste de contours en tableau avant l'appel récursif, réduisant ainsi les conversions répétées.

## Auteurs

- Tobias SAVARY
- Albin HORLAVILLE
