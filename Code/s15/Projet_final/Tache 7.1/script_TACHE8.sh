#!/bin/bash

ch_T_8="images/TACHE8.2/"
ch_T_8_S="images/SORTIE_TACHE8.2/"
rouge='\033[91m'
neutre='\e[0;m'
for images in ${ch_T_8}*
do
    for d in 0 0.5 1 2 4 8 16
    do
        echo -e " ${rouge}./simplification_par_segment ${images} ${d} 1 ${images}_d${d}_m1_seg.EPS ${neutre}"
        ./simplification_par_segment ${images} ${d} 1 ${images}_d${d}_m1_seg.EPS
        echo -e " ${rouge}./simplification_par_bezier2 ${images} ${d} 1 ${images}_d${d}_m1_bez2.EPS${neutre}"
        ./simplification_par_bezier2 ${images} ${d} 1 ${images}_d${d}_m1_bez1.EPS
        echo -e " ${rouge}./simplification_par_bezier3 ${images} ${d} 1 ${images}_d${d}_m1_bez3.EPS${neutre}"
        ./simplification_par_bezier3 ${images} ${d} 1 ${images}_d${d}_m1_bez2.EPS
    done 
done

for var in 1 2 4 8
do 
    gv ${ch_T_8}Asterix3.pbm_d${var}_m1_seg.EPS
    gv ${ch_T_8}Asterix3.pbm_d${var}_m1_bez1.EPS
    gv ${ch_T_8}Asterix3.pbm_d${var}_m1_bez2.EPS
done