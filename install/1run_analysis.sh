# nohup ./0_MyScript.sh > 0_nohup.out & tail -f 0_nohup.out

#flag=`condor_q -all | grep "tikim ID"`
#
#while [ "${flag:1:2}" == "ik" ]
#do 
#    sleep 1m
#    flag=`condor_q -all | grep "tikim ID"`        
#done
#
#echo "preparing analysis"
#hadd "$root_name.root" ./*.root
##./bin/analysis "$root_name" $((${j} - 10)) $((${j} + 10))
#./bin/analysis "$root_name" $((${x1})) $((${x2}))
#mkdir ${root_name}
#mv log "./${root_name}/"
#cp 0_Simulation* "./${root_name}/"
#mkdir root
#mv "$root_name.root" "./${root_name}/"
#mv *.root ./root/
#mv root "./${root_name}/"
#mv *.png "./${root_name}/"
#echo "analysis and arranging directory is done for $i ${j}GeV"

#for j in 20 30 70 90 110

#do

#    mkdir /data4/tikim/dual-readout/install/0_pion/${j}GeV_pi/analysis; mv /data4/tikim/dual-readout/install/0_pion/${j}GeV_pi/*png /data4/tikim/dual-readout/install/0_pion/${j}GeV_pi/analysis

#done
# for i in "pi+"
for i in "e-"
# particle names(e-, pi+)
do
    for j in 20 5 10 30 50 70
    # for j in 10 20 30 50 70 90 110
    do
        if [ $j -eq 5 ]
        then
            x1=0
            x2=10
        fi

        if [ $j -eq 10 ]
        then
            x1=5
            x2=15
        fi

        if [ $j -eq 20 ]
        then
            x1=15
            x2=25
        fi

        if [ $j -eq 30 ]
        then
            x1=20
            x2=40
        fi

        if [ $j -eq 50 ]
        then
            x1=40
            x2=60
        fi

        if [ $j -eq 70 ]
        then
            x1=60
            x2=80
        fi

        if [ $j -eq 90 ]
        then
            x1=80
            x2=100
        fi

        if [ $j -eq 110 ]
        then
            x1=100
            x2=120
        fi
        # x1=$((${j} - 20))
        # x2=$((${j} + 20))
        root_name="e_${j}GeV_51th"
        # /fcc/tikim/HEP-FCC_dual-readout_001/dual-readout/install/e_5GeV_51th
        mkdir /fcc/tikim/HEP-FCC_dual-readout_001/dual-readout/install/e_${j}GeV_51th/old
        cp /fcc/tikim/HEP-FCC_dual-readout_001/dual-readout/install/e_${j}GeV_51th/*.png /fcc/tikim/HEP-FCC_dual-readout_001/dual-readout/install/e_${j}GeV_51th/old/
        nohup ./bin/analysis /fcc/tikim/HEP-FCC_dual-readout_001/dual-readout/install/e_${j}GeV_51th/$root_name $((${x1})) $((${x2})) > /fcc/tikim/HEP-FCC_dual-readout_001/dual-readout/install/e_${j}GeV_51th/${root_name}_nohup.out &
        # /data4/tikim/dual-readout/install/0_pion/3000Events/20GeV_pi
        # cat "/data4/tikim/dual-readout/install/0_pion/3000Events/${j}GeV_pi/${root_name}_nohup.out" | grep 'Sigma\|Mean\|StdDev' > "/data4/tikim/dual-readout/install/0_pion/3000Events/${j}GeV_pi/${j}GeV_pi_CSS_MS_Error.txt"
        # cat "/fcc/tikim/HEP-FCC_dual-readout_001/dual-readout/install/ele/e_5GeV_51th/sum_use_this/e_5GeV_51th_nohup.out" | grep 'Sigma\|Mean\|StdDev' > "/fcc/tikim/HEP-FCC_dual-readout_001/dual-readout/install/ele/5GeV/5GeV_CSS_MS_Error.txt"

    done
    
    # while :
    # do
    #     if [[ $(tail -1 0_pion/3000Events/110GeV_pi/110GeV_pi_nohup.out) = "Done" ]]; then
    #         break
    #         # if analysis is done, then, bring values to a text file.
    #     else
    #         sleep 5
    #     fi  
    # done
    
    # for j in 5 10 20 30 50 70 90 110
    # do
    #     if [ $j -eq 5 ]
    #     then
    #         x1=0
    #         x2=10
    #     fi

    #     if [ $j -eq 10 ]
    #     then
    #         x1=0
    #         x2=15
    #     fi

    #     if [ $j -eq 20 ]
    #     then
    #         x1=0
    #         x2=30
    #     fi

    #     if [ $j -eq 30 ]
    #     then
    #         x1=5
    #         x2=40
    #     fi

    #     if [ $j -eq 50 ]
    #     then
    #         x1=10
    #         x2=60
    #     fi

    #     if [ $j -eq 70 ]
    #     then
    #         x1=20
    #         x2=90
    #     fi

    #     if [ $j -eq 90 ]
    #     then
    #         x1=30
    #         x2=110
    #     fi

    #     if [ $j -eq 110 ]
    #     then
    #         x1=40
    #         x2=130
    #     fi
    #     # x1=$((${j} - 20))
    #     # x2=$((${j} + 20))
    #     root_name="${j}GeV_${i:0:-1}"
    #     cat "/data4/tikim/dual-readout/install/0_pion/3000Events/${j}GeV_pi/${root_name}_nohup.out" | grep 'Sigma\|Mean\|StdDev' > "/data4/tikim/dual-readout/install/0_pion/3000Events/${j}GeV_pi/${j}GeV_pi_CSS_MS_Error.txt"
    # done

done