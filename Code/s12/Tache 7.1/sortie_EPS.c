#include "sortie_EPS.h"

void ecriture_fichier_EPS(FILE *f, int mode, Image Image, Liste_Point L){
    fprintf( f, "%c!PS-Adobe-3.0 EPSF-3.0\n", '%');
    fprintf( f, "%c%cBoundingBox 0 0 %d %d \n",'%','%', largeur_image(Image), hauteur_image(Image));
    Point first_point = set_point(L.first->data.x, L.first->data.y);
    fprintf(f, "%f %f moveto ", first_point.x, hauteur_image(Image) - first_point.y);
    for (Cellule_Liste_Point *tmp = L.first; tmp != NULL; tmp = tmp->suiv){

        fprintf(f, "%f %f lineto \n", tmp->suiv->data.x, hauteur_image(Image) - tmp->suiv->data.y);
    }
    switch(mode){
        case STROKE:
            fprintf(f, "stroke\n");
            break;
        case FILL:
            fprintf(f, "fill\n");
            break;
    }
    fprintf(f, "showpage\n");
}





void ecriture_fichier_EPS_tache5(FILE *f, int mode, Image Image, Liste_Contour L){
    fprintf( f, "%c!PS-Adobe-3.0 EPSF-3.0\n", '%');
    fprintf( f, "%c%cBoundingBox 0 0 %d %d \n",'%','%', largeur_image(Image), hauteur_image(Image));
    for (Cellule_Liste_Contour *tmp_contour = L.first; tmp_contour != NULL ; tmp_contour = tmp_contour->suiv){
        Point first_point = set_point(tmp_contour->contour.first->data.x, tmp_contour->contour.first->data.y);
        fprintf(f, "%f %f moveto ", first_point.x, hauteur_image(Image) - first_point.y);
        for (Cellule_Liste_Point *tmp = tmp_contour->contour.first; tmp != NULL; tmp = tmp->suiv){
            fprintf(f, "%f %f lineto \n", tmp->suiv->data.x, hauteur_image(Image) - tmp->suiv->data.y);
        }
    }
    switch(mode){
        case STROKE:
            fprintf(f, "stroke\n");
            break;
        case FILL:
            fprintf(f, "fill\n");
            break;
    }
    fprintf(f, "showpage\n");
}



void ecriture_fichier_EPS_bezier3(FILE *f, int mode, Image Image, Liste_Contour_bezier L){
    fprintf( f, "%c!PS-Adobe-3.0 EPSF-3.0\n", '%');
    int h = hauteur_image(Image);
    fprintf( f, "%c%cBoundingBox 0 0 %d %d \n",'%','%', largeur_image(Image), hauteur_image(Image));
    
    for (Cellule_Liste_Contour_bezier *tmp_contour = L.first; tmp_contour != NULL ; tmp_contour = tmp_contour->suiv){
        Point first_point = set_point(tmp_contour->contour_bezier.first->B.C0.x, tmp_contour->contour_bezier.first->B.C0.y);
        fprintf(f, "%f %f moveto ", first_point.x, h - first_point.y);

        for( Cellule_Liste_Bezier3 *cel = tmp_contour->contour_bezier.first ; cel != NULL ; cel = cel->suiv ){
            fprintf(f, "%f %f %f %f %f %f curveto \n",  cel->B.C1.x, h - cel->B.C1.y, 
                                                        cel->B.C2.x,  h - cel->B.C2.y, 
                                                        cel->B.C3.x, h - cel->B.C3.y);
        }
    }
    switch(mode){
        case STROKE:
            fprintf(f, "stroke\n");
            break;
        case FILL:
            fprintf(f, "fill\n");
            break;
    }
    fprintf(f, "showpage\n");
}
