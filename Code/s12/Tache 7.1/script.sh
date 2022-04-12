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
        echo To Do

    # Gestion de la Tache 6
    elif [ $lecture_tache -eq 6 ]
    then
        echo To Do

    # Gestion de la Tache 7
    elif [ $lecture_tache -eq 7 ]
    then
        echo To Do
    else 
        echo La variable que vous avez entrer ne correspond pas à un numéro de Tâche
    fi


    # echo -e "${rouge}entrez le numéro de la tâche que vous voulez exécuter :"
    # echo -e "Entrez -1 pour sortir${neutre}"
    # read lecture_tache
done
echo -e "${jaune} Bonne journée${neutre} ${vert} ;) ${neutre}"
echo -e "${jaune} Fin Script ${neutre}"
