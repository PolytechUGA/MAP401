#!/bin/bash

# Initialisation des couleurs permettant l'affichage
vert='\033[92m'
jaune='\033[93m'
rouge='\033[91m'

neutre='\e[0;m'
lecture_tache=0
OUI="O"
NON="N"

# Chemins
ch_T_1="images/TACHE1/"
ch_T_3="images/TACHE3_4/"
ch_T_4=${ch_T_3}
ch_T_5="images/TACHE5/"
ch_T_6="images/TACHE6/"
ch_T_7="images/TACHE7/"
ch_T_8="images/TACHE8/"


ch_T_3_S="images/SORTIE_TACHE3/"
ch_T_4_S="images/SORTIE_TACHE4/"
ch_T_5_S="images/SORTIE_TACHE5/"
ch_T_6_S="images/SORTIE_TACHE6/"
ch_T_7_S="images/SORTIE_TACHE7/"
ch_T_8_S="images/SORTIE_TACHE8/"



echo -e "${jaune} Bonjour, ce scrit permet de faciliter l'éxecution des différents programmes réalisés ${neutre}"

while [ $lecture_tache -ne -1 ]
do
    echo -e "${rouge} Entrez le numéro de la tâche que vous voulez exécuter :"
    echo -e " Entrez -1 pour sortir${neutre}"
    read lecture_tache

    # Gestion de la Tache 1 
    if [ $lecture_tache -eq 1 ]
    then 
        echo -e "${jaune} Test de la Tâche1 sur le fichier caractere2.pbm : ${neutre}" 
        echo "${ch_T_1}caractere2.pbm"
        ./test_image "${ch_T_1}caractere2.pbm"
    
    
    # Gestion de la Tache 2
    elif [ $lecture_tache -eq 2 ]
    then 
        echo -e "${jaune} Test de la Tâche2 : ${neutre}"
        ./test_geom
    
    
    # Gestion de la Tache 3
    elif [ $lecture_tache -eq 3 ]
    then 
        echo -e "${jaune} Test de la Tâche3 : "
        echo -e " Exemple avec le fichier image_ex_poly.pbm :  ${neutre}" 
        echo ./test_contour ${ch_T_3}image_ex_poly.pbm ${ch_T_3_S}Tache3_image_ex_poly.txt
        # Exécution de l'exemple image_ex_poly
        ./test_contour ${ch_T_3}image_ex_poly.pbm ${ch_T_3_S}Tache3_image_ex_poly.txt

        echo -e "${rouge} Voulez-vous essayer sur une autre image ? (O/N)${neutre} "
        read lecture_new_image
        # Proposition à l'utilisateur de tester sur d'autres images
        while [ $lecture_new_image = $OUI ]
        do
            echo -e "${rouge} Entrez le nom de l'image (dans le dossier ${ch_T_3}):${neutre} "
            read name_image
            echo -e "${rouge} Entrez le nom du fichier de sortie (dans le dossier ${ch_T_3_S}):${neutre} "
            read name_f_out
            echo ./test_contour ${ch_T_3}${name_image} ${ch_T_3_S}Tache3_${name_f_out}
            ./test_contour ${ch_T_3}${name_image} ${ch_T_3_S}Tache3_${name_f_out}
            echo -e "${rouge} Voulez-vous essayer sur une autre image ? (O/N)${neutre} "
            read lecture_new_image
        done


    # Gestion de la Tache 4
    elif [ $lecture_tache -eq 4 ]
    then 
        echo -e "${jaune} Test de la Tâche4 : "
        echo -e " Exemple avec le fichier chat.pbm : " 
        # Exécution de l'exemple chat avec le mode remplissage
        echo -e " Sortie: Tache4_chat_1.EPS   Mode : 1 (remplissage)${neutre} "
        echo ./test_EPS ${ch_T_4}chat.pbm ${ch_T_4_S}Tache4_chat_1.EPS 1
        ./test_EPS ${ch_T_4}chat.pbm ${ch_T_4_S}Tache4_chat_1.EPS 1
        
        echo -e "${jaune} Affichage de l'image produite avec gv ${neutre}"
        gv ${ch_T_4_S}Tache4_chat_1.EPS
        
        # Exécution de l'exemple chat avec le mode contour
        echo -e "${jaune} Sortie: Tache4_chat_0.EPS   Mode: 0 (contour)${neutre}"
        echo ./test_EPS ${ch_T_4}chat.pbm ${ch_T_4_S}Tache4_chat_0.EPS 0
        ./test_EPS ${ch_T_4}chat.pbm ${ch_T_4_S}Tache4_chat_0.EPS 0
        
        echo -e "${jaune} Affichage de l'image produite avec gv ${neutre}"
        gv ${ch_T_4_S}Tache4_chat_0.EPS
        
        echo -e "${rouge} Voulez-vous essayer sur une autre image ? (O/N)${neutre} "
        read lecture_new_image
        # Proposition à l'utilisateur de tester sur d'autres images
        while [ $lecture_new_image = $OUI ]
        do
            echo -e "${rouge} Entrez le nom de l'image (dans le dossier ${ch_T_4}):${neutre} "
            read name_image
            echo -e "${rouge} Entrez le nom du fichier de sortie.EPS (dans le dossier ${ch_T_4_S}):${neutre} "
            read name_f_out
            echo -e "${rouge} Entrez le mode (0=Contour ou 1=Remplissage):${neutre} "
            read mode
            echo ./test_EPS ${ch_T_4}${name_image} ${ch_T_4_S}Tache4_${name_f_out} ${mode}
            ./test_EPS ${ch_T_4}${name_image} ${ch_T_4_S}Tache4_${name_f_out} ${mode}
            echo -e "${jaune} Affichage de l'image produite avec gv ${neutre}"
            gv ${ch_T_4_S}Tache4_${name_f_out}
            echo -e "${rouge} Voulez-vous essayer sur une autre image ? (O/N)${neutre} "
            read lecture_new_image
        done


    # Gestion de la Tache 5
    elif [ $lecture_tache -eq 5 ]
    then
        echo -e "${jaune} Vous avez demander la Tâche 5 : ${neutre}"
        echo -e "${jaune} La Tâche 5.1 renvoie la liste des points dans le fichier txt${neutre}"
        echo -e "${jaune} La Tâche 5.2 ecrit un fichier EPS pour les arguments donnés${neutre}"
        echo -e "${rouge} Voulez-vous la Tâche 5.1 ou 5.2 (Envoyez 1 ou 2 par SMS au 72500 vous avez 5 min pour jouer ;) )${neutre} "
        read numero_tache
        while [ ${numero_tache} -ne 1 -a ${numero_tache} -ne 2 ]
        do
            echo -e "${jaune} Le numéro de tâche que vous avez entré est inccorect.${neutre}"
            echo -e "${rouge} Entrez un nouveau numéro de tâche (1 Pour 5.1 et 2 pour 5.2)${neutre} "
            read numero_tache
        done

        if [ ${numero_tache} -eq 1 ]
        then 
            echo -e "${jaune} Test de la Tâche5.1 : "
            echo -e " Exemple avec le fichier Charlot.pbm : " 
            # Exécution de l'exemple charlot.pbm
            echo -e " Sortie: Tache5.1_Charlot.txt  ${neutre} "
            echo ./ecrire_liste_contours ${ch_T_5}Charlot.pbm ${ch_T_5_S}Tache5.1_Charlot.txt
            ./ecrire_liste_contours ${ch_T_5}Charlot.pbm ${ch_T_5_S}Tache5.1_Charlot.txt
            echo -e "${rouge} Voulez-vous essayer sur une autre image ? (O/N)${neutre} "
            read lecture_new_image
            # Proposition à l'utilisateur de tester sur d'autres images
            while [ $lecture_new_image = $OUI ]
            do
                echo -e "${rouge} Entrez le nom de l'image (dans le dossier ${ch_T_5}):${neutre} "
                read name_image
                echo -e "${rouge} Entrez le nom du fichier de sortie.txt (dans le dossier ${ch_T_5_S}):${neutre} "
                read name_f_out
                echo ./ecrire_liste_contours ${ch_T_5}${name_image} ${ch_T_5_S}Tache5.1_${name_f_out}
                ./ecrire_liste_contours ${ch_T_5}${name_image} ${ch_T_5_S}Tache5.1_${name_f_out}
                echo -e "${rouge} Voulez-vous essayer sur une autre image ? (O/N)${neutre} "
                read lecture_new_image
            done

        else 
            echo -e "${jaune} Test de la Tâche5.2 : "
            echo -e " Exemple avec le fichier Charlot.pbm : "
            echo -e " Sortie: Tache5.2_Charlot_1.EPS   Mode : 1 (remplissage)${neutre} "
            # Exécution de l'exemple charlot.pbm en mode remplissage
            echo ./ecrire_liste_contours ${ch_T_5}Charlot.pbm ${ch_T_5_S}Tache5.2_Charlot_1.EPS 1
            ./ecrire_liste_contours ${ch_T_5}Charlot.pbm ${ch_T_5_S}Tache5.2_Charlot_1.EPS 1
            
            echo -e "${jaune} Affichage de l'image produite avec gv ${neutre}"
            gv ${ch_T_5_S}Tache5.2_Charlot_1.EPS

            echo -e " Sortie: Tache5.2_Charlot_0.EPS   Mode : 0 (Contours)${neutre} "
            # Exécution de l'exemple charlot.pbm en mode remplissage
            echo ./ecrire_liste_contours ${ch_T_5}Charlot.pbm ${ch_T_5_S}Tache5.2_Charlot_0.EPS 0
            ./ecrire_liste_contours ${ch_T_5}Charlot.pbm ${ch_T_5_S}Tache5.2_Charlot_0.EPS 0
            
            echo -e "${jaune} Affichage de l'image produite avec gv ${neutre}"
            gv ${ch_T_5_S}Tache5.2_Charlot_0.EPS
            
            echo -e "${rouge} Voulez-vous essayer sur une autre image ? (O/N)${neutre} "
            read lecture_new_image
            # Proposition à l'utilisateur de tester sur d'autres images
            while [ $lecture_new_image = $OUI ]
            do
                echo -e "${rouge} Entrez le nom de l'image (dans le dossier ${ch_T_5}):${neutre} "
                read name_image
                echo -e "${rouge} Entrez le nom du fichier de sortie.EPS (dans le dossier ${ch_T_5_S}):${neutre} "
                read name_f_out
                echo -e "${rouge} Entrez le mode (0=Contour ou 1=Remplissage):${neutre} "
                read mode
                echo ./ecrire_liste_contours ${ch_T_5}${name_image} ${ch_T_5_S}Tache5.2_${name_f_out} ${mode}
                ./ecrire_liste_contours ${ch_T_5}${name_image} ${ch_T_5_S}Tache5.2_${name_f_out} ${mode}
                echo -e "${jaune} Affichage de l'image produite avec gv ${neutre}"
                gv ${ch_T_5_S}Tache5.2_${name_f_out}
                echo -e "${rouge} Voulez-vous essayer sur une autre image ? (O/N)${neutre} "
                read lecture_new_image
            done
        fi

    # Gestion de la Tache 6
    elif [ $lecture_tache -eq 6 ]
    then
        echo -e "${jaune} Vous avez demander la Tâche 6 : ${neutre}"
        echo -e "${jaune} La Tâche 6.1 pemet de Calculer la distance entre un point P et un segment AB${neutre}"
        echo -e "${jaune} La Tâche 6.2 fait la simplification par segments d'une image pbm selon une disance d${neutre}" 
        echo -e "${rouge} Voulez-vous la Tâche 6.1 ou 6.2 (Envoyez 1 ou 2 par SMS au 72500 vous avez 5 min pour jouer ;) )${neutre} "
        read numero_tache
        while [ ${numero_tache} -ne 1 -a ${numero_tache} -ne 2 ]
        do
            echo -e "${jaune} Le numéro de tâche que vous avez entré est inccorect.${neutre}"
            echo -e "${rouge} Entrez un nouveau numéro de tâche (1 Pour 6.1 et 2 pour 6.2)${neutre} "
            read numero_tache
        done

        if [ ${numero_tache} -eq 1 ]
        then 
            new_distance=${OUI}
            while [ $new_distance = ${OUI} ]
            do
                echo -e "${jaune} Test de la Tâche6.1 : ${neutre}"
                echo ./distance_pts_seg
                ./distance_pts_seg
                echo -e "${rouge} Voulez-vous essayer avec de nouveaux points ? (O/N)${neutre} "
                read new_distance
            done
        else 
            echo -e "${jaune} Test de la Tâche6.2 : "
            echo -e " Exemple avec le fichier cheval.pbm : "
            echo -e " Sortie: Tache6.2_cheval_d1_m0.EPS  Distance : 1 Mode : 0 (Contours)${neutre} "
            # Exécution de l'exemple cheval.pbm en mode Concours avec distance de 1
            echo ./simplification_par_segment ${ch_T_6}cheval.pbm 1 0 ${ch_T_6_S}Tache6.2_cheval_d1_m0.EPS
            ./simplification_par_segment ${ch_T_6}cheval.pbm 1 0 ${ch_T_6_S}Tache6.2_cheval_d1_m0.EPS
            
            echo -e "${jaune} Affichage de l'image produite avec gv ${neutre}"
            gv ${ch_T_6_S}Tache6.2_cheval_d1_m0.EPS


            echo -e " Sortie: Tache6.2_cheval_d2_m0.EPS  Distance : 2 Mode : 0 (Contours)${neutre} "
            # Exécution de l'exemple cheval.pbm en mode Concours avec distance de 2
            echo ./simplification_par_segment ${ch_T_6}cheval.pbm 2 0 ${ch_T_6_S}Tache6.2_cheval_d2_m0.EPS
            ./simplification_par_segment ${ch_T_6}cheval.pbm 2 0 ${ch_T_6_S}Tache6.2_cheval_d2_m0.EPS
            
            echo -e "${jaune} Affichage de l'image produite avec gv ${neutre}"
            gv ${ch_T_6_S}Tache6.2_cheval_d2_m0.EPS


            echo -e " Sortie: Tache6.2_cheval_d1_m1.EPS  Distance : 1 Mode : 1 (Remplissage)${neutre} "
            # Exécution de l'exemple cheval.pbm en mode Remplissage avec distance de 1
            echo ./simplification_par_segment ${ch_T_6}cheval.pbm 1 1 ${ch_T_6_S}Tache6.2_cheval_d1_m1.EPS
            ./simplification_par_segment ${ch_T_6}cheval.pbm 1 1 ${ch_T_6_S}Tache6.2_cheval_d1_m1.EPS
            
            echo -e "${jaune} Affichage de l'image produite avec gv ${neutre}"
            gv ${ch_T_6_S}Tache6.2_cheval_d1_m1.EPS


            echo -e " Sortie: Tache6.2_Charlot_d2_m1.EPS  Distance : 2 Mode : 1 (Remplissage))${neutre} "
            # Exécution de l'exemple cheval.pbm en mode Remplissage avec distance de 2
            echo ./simplification_par_segment ${ch_T_6}cheval.pbm 2 1 ${ch_T_6_S}Tache6.2_cheval_d2_m1.EPS
            ./simplification_par_segment ${ch_T_6}cheval.pbm 2 1 ${ch_T_6_S}Tache6.2_cheval_d2_m1.EPS
            
            echo -e "${jaune} Affichage de l'image produite avec gv ${neutre}"
            gv ${ch_T_6_S}Tache6.2_cheval_d2_m1.EPS

            echo -e "${rouge} Voulez-vous essayer sur une autre image ? (O/N)${neutre} "
            read lecture_new_image
            # Proposition à l'utilisateur de tester sur d'autres images
            while [ $lecture_new_image = $OUI ]
            do
                echo -e "${rouge} Entrez le nom de l'image (dans le dossier ${ch_T_6}):${neutre} "
                read name_image
                echo -e "${rouge} Entrez le nom du fichier de sortie.EPS (dans le dossier ${ch_T_6_S}):${neutre} "
                read name_f_out
                echo -e "${rouge} Entrez le mode (0=Contour ou 1=Remplissage):${neutre} "
                read mode
                echo -e "${rouge} Entrez la distance d:${neutre} "
                read distance
                echo ./simplification_par_segment ${ch_T_6}${name_image} ${distance} ${mode} ${ch_T_6_S}Tache6.2_${name_f_out}
                ./simplification_par_segment ${ch_T_6}${name_image} ${distance} ${mode} ${ch_T_6_S}Tache6.2_${name_f_out}
                
                echo -e "${jaune} Affichage de l'image produite avec gv ${neutre}"
                gv ${ch_T_6_S}Tache6.2_${name_f_out}
                echo -e "${rouge} Voulez-vous essayer sur une autre image ? (O/N)${neutre} "
                read lecture_new_image
            done
            
        fi


    # Gestion de la Tache 7
    elif [ $lecture_tache -eq 7 ]
    then
        echo -e "${jaune} Vous avez demander la Tâche 7 : ${neutre}"
        echo -e "${jaune} La Tâche 7.1 fait la simplification par bézier2 d'une image pbm selon une disance d${neutre}"
        echo -e "${jaune} La Tâche 7.2 fait la simplification par bézier3 d'une image pbm selon une disance d${neutre}" 
        echo -e "${rouge} Voulez-vous la Tâche 7.1 ou 7.2 (Envoyez 1 ou 2 par SMS au 72500 vous avez 5 min pour jouer ;) )${neutre} "
        read numero_tache
        while [ ${numero_tache} -ne 1 -a ${numero_tache} -ne 2 ]
        do
            echo -e "${jaune} Le numéro de tâche que vous avez entré est inccorect.${neutre}"
            echo -e "${rouge} Entrez un nouveau numéro de tâche (1 Pour 7.1 et 2 pour 7.2)${neutre} "
            read numero_tache
        done

        if [ ${numero_tache} -eq 1 ]
        then 

            echo -e "${jaune} Test de la Tâche7.1 : "
            echo -e " Exemple avec le fichier deux-des-pleins.pbm : "
            echo -e " Sortie: Tache7.1_deux-des-pleins_d1_m0.EPS  Distance : 1 Mode : 0 (Contours)${neutre} "
            # Exécution de l'exemple deux-des-pleins.pbm en mode Concours avec distance de 1
            echo ./simplification_par_bezier2 ${ch_T_7}deux-des-pleins.pbm 1 0 ${ch_T_7_S}Tache7.1_deux-des-pleins_d1_m0.EPS
            ./simplification_par_bezier2 ${ch_T_7}deux-des-pleins.pbm 1 0 ${ch_T_7_S}Tache7.1_deux-des-pleins_d1_m0.EPS
            
            # ./simplification_par_bezier2 images/TACHE7/Asterix3.pbm 2 0 images/SORTIE_TACHE7/Asterix3_d2_m0.EPS
            echo -e "${jaune} Affichage de l'image produite avec gv ${neutre}"
            gv ${ch_T_7_S}Tache7.1_deux-des-pleins_d1_m0.EPS


            echo -e " Sortie: Tache7.1_deux-des-pleins_d2_m0.EPS  Distance : 2 Mode : 0 (Contours)${neutre} "
            # Exécution de l'exemple deux-des-pleins.pbm en mode Concours avec distance de 2
            echo ./simplification_par_bezier2 ${ch_T_7}deux-des-pleins.pbm 2 0 ${ch_T_7_S}Tache7.1_deux-des-pleins_d2_m0.EPS
            ./simplification_par_bezier2 ${ch_T_7}deux-des-pleins.pbm 2 0 ${ch_T_7_S}Tache7.1_deux-des-pleins_d2_m0.EPS
            echo -e "${jaune} Affichage de l'image produite avec gv ${neutre}"
            gv ${ch_T_7_S}Tache7.1_deux-des-pleins_d2_m0.EPS


            echo -e " Sortie: Tache7.1_deux-des-pleins_d1_m1.EPS  Distance : 1 Mode : 1 (Remplissage)${neutre} "
            # Exécution de l'exemple cheval.pbm en mode Remplissage avec distance de 1
            echo ./simplification_par_bezier2 ${ch_T_7}deux-des-pleins.pbm 1 1 ${ch_T_7_S}Tache7.1_deux-des-pleins_d1_m1.EPS
            ./simplification_par_bezier2 ${ch_T_7}deux-des-pleins.pbm 1 1 ${ch_T_7_S}Tache7.1_deux-des-pleins_d1_m1.EPS
            echo -e "${jaune} Affichage de l'image produite avec gv ${neutre}"
            gv ${ch_T_7_S}Tache7.1_deux-des-pleins_d1_m1.EPS


            echo -e " Sortie: Tache7.1_deux-des-pleins_d2_m1.EPS  Distance : 2 Mode : 1 (Remplissage))${neutre} "
            # Exécution de l'exemple deux-des-pleins.pbm en mode Remplissage avec distance de 2
            echo ./simplification_par_bezier2 ${ch_T_7}deux-des-pleins.pbm 2 1 ${ch_T_7_S}Tache7.1_deux-des-pleins_d2_m1.EPS
            ./simplification_par_bezier2 ${ch_T_7}deux-des-pleins.pbm 2 1 ${ch_T_7_S}Tache7.1_deux-des-pleins_d2_m1.EPS
            
            echo -e "${jaune} Affichage de l'image produite avec gv ${neutre}"
            gv ${ch_T_7_S}Tache7.1_deux-des-pleins_d2_m1.EPS


            echo -e "${rouge} Voulez-vous essayer sur une autre image ? (O/N)${neutre} "
            read lecture_new_image
            # Proposition à l'utilisateur de tester sur d'autres images
            while [ $lecture_new_image = $OUI ]
            do
                echo -e "${rouge} Entrez le nom de l'image (dans le dossier ${ch_T_7}):${neutre} "
                read name_image
                echo -e "${rouge} Entrez le nom du fichier de sortie.EPS (dans le dossier ${ch_T_7_S}):${neutre} "
                read name_f_out
                echo -e "${rouge} Entrez le mode (0=Contour ou 1=Remplissage):${neutre} "
                read mode
                echo -e "${rouge} Entrez la distance d:${neutre} "
                read distance
                echo ./simplification_par_bezier2 ${ch_T_7}${name_image} ${distance} ${mode} ${ch_T_7_S}Tache7.1_${name_f_out}
                ./simplification_par_bezier2 ${ch_T_7}${name_image} ${distance} ${mode} ${ch_T_7_S}Tache7.1_${name_f_out}
                
                echo -e "${jaune} Affichage de l'image produite avec gv ${neutre}"
                gv ${ch_T_7_S}Tache7.1_${name_f_out}
                echo -e "${rouge} Voulez-vous essayer sur une autre image ? (O/N)${neutre} "
                read lecture_new_image
            done



        else
            echo -e "${jaune} Test de la Tâche7.1 : "
            echo -e " Exemple avec le fichier deux-des-pleins.pbm : "
            echo -e " Sortie: Tache7.1_deux-des-pleins_d1_m0.EPS  Distance : 1 Mode : 0 (Contours)${neutre} "
            # Exécution de l'exemple deux-des-pleins.pbm en mode Concours avec distance de 1
            echo ./simplification_par_bezier3 ${ch_T_7}deux-des-pleins.pbm 1 0 ${ch_T_7_S}Tache7.2_deux-des-pleins_d1_m0.EPS
            ./simplification_par_bezier3 ${ch_T_7}deux-des-pleins.pbm 1 0 ${ch_T_7_S}Tache7.2_deux-des-pleins_d1_m0.EPS
            
            # ./simplification_par_bezier2 images/TACHE7/Asterix3.pbm 2 0 images/SORTIE_TACHE7/Asterix3_d2_m0.EPS
            echo -e "${jaune} Affichage de l'image produite avec gv ${neutre}"
            gv ${ch_T_7_S}Tache7.2_deux-des-pleins_d1_m0.EPS


            echo -e " Sortie: Tache7.1_deux-des-pleins_d2_m0.EPS  Distance : 2 Mode : 0 (Contours)${neutre} "
            # Exécution de l'exemple deux-des-pleins.pbm en mode Concours avec distance de 2
            echo ./simplification_par_bezier3 ${ch_T_7}deux-des-pleins.pbm 2 0 ${ch_T_7_S}Tache7.2_deux-des-pleins_d2_m0.EPS
            ./simplification_par_bezier3 ${ch_T_7}deux-des-pleins.pbm 2 0 ${ch_T_7_S}Tache7.2_deux-des-pleins_d2_m0.EPS
            echo -e "${jaune} Affichage de l'image produite avec gv ${neutre}"
            gv ${ch_T_7_S}Tache7.2_deux-des-pleins_d2_m0.EPS


            echo -e " Sortie: Tache7.1_deux-des-pleins_d1_m1.EPS  Distance : 1 Mode : 1 (Remplissage)${neutre} "
            # Exécution de l'exemple cheval.pbm en mode Remplissage avec distance de 1
            echo ./simplification_par_bezier3 ${ch_T_7}deux-des-pleins.pbm 1 1 ${ch_T_7_S}Tache7.2_deux-des-pleins_d1_m1.EPS
            ./simplification_par_bezier3 ${ch_T_7}deux-des-pleins.pbm 1 1 ${ch_T_7_S}Tache7.2_deux-des-pleins_d1_m1.EPS
            echo -e "${jaune} Affichage de l'image produite avec gv ${neutre}"
            gv ${ch_T_7_S}Tache7.2_deux-des-pleins_d1_m1.EPS


            echo -e " Sortie: Tache7.1_deux-des-pleins_d2_m1.EPS  Distance : 2 Mode : 1 (Remplissage))${neutre} "
            # Exécution de l'exemple deux-des-pleins.pbm en mode Remplissage avec distance de 2
            echo ./simplification_par_bezier3 ${ch_T_7}deux-des-pleins.pbm 2 1 ${ch_T_7_S}Tache7.2_deux-des-pleins_d2_m1.EPS
            ./simplification_par_bezier3 ${ch_T_7}deux-des-pleins.pbm 2 1 ${ch_T_7_S}Tache7.2_deux-des-pleins_d2_m1.EPS
            
            echo -e "${jaune} Affichage de l'image produite avec gv ${neutre}"
            gv ${ch_T_7_S}Tache7.2_deux-des-pleins_d2_m1.EPS


            echo -e "${rouge} Voulez-vous essayer sur une autre image ? (O/N)${neutre} "
            read lecture_new_image
            # Proposition à l'utilisateur de tester sur d'autres images
            while [ $lecture_new_image = $OUI ]
            do
                echo -e "${rouge} Entrez le nom de l'image (dans le dossier ${ch_T_7}):${neutre} "
                read name_image
                echo -e "${rouge} Entrez le nom du fichier de sortie.EPS (dans le dossier ${ch_T_7_S}):${neutre} "
                read name_f_out
                echo -e "${rouge} Entrez le mode (0=Contour ou 1=Remplissage):${neutre} "
                read mode
                echo -e "${rouge} Entrez la distance d:${neutre} "
                read distance
                echo ./simplification_par_bezier3 ${ch_T_7}${name_image} ${distance} ${mode} ${ch_T_7_S}Tache7.2_${name_f_out}
                ./simplification_par_bezier3 ${ch_T_7}${name_image} ${distance} ${mode} ${ch_T_7_S}Tache7.2_${name_f_out}
                
                echo -e "${jaune} Affichage de l'image produite avec gv ${neutre}"
                gv ${ch_T_7_S}Tache7.2_${name_f_out}
                echo -e "${rouge} Voulez-vous essayer sur une autre image ? (O/N)${neutre} "
                read lecture_new_image
            done

        fi

    

    elif [ $lecture_tache -eq -1 ]
    then 
        echo -e " ${vert} Bonne journée ;) ${neutre}"
        echo -e "${jaune} Fin Script ${neutre}"

    else 
        echo La variable que vous avez entrer ne correspond pas à un numéro de Tâche
    fi
done
