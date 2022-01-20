# while :
# do
#     if [[ $(tail -1 0_pion/3000Events/110GeV_pi/110GeV_pi_nohup.out) = "Done" ]]; then
#         break
#         # if analysis is done, then, bring values to a text file.
#     else
#         sleep 5
#     fi  
# done

for j in 20 30 50 70 90 110
# for j in 5 10 20 30 50 70 90 110
do
    
    # root_name="${j}GeV_${i:0:-1}"
    # cat "/data4/tikim/dual-readout/install/0_pion/3000Events/${j}GeV_pi/${root_name}_nohup.out" | grep 'Sigma\|Mean\|StdDev' > "/data4/tikim/dual-readout/install/0_pion/3000Events/${j}GeV_pi/${j}GeV_pi_CSS_MS_Error.txt"
    cat "/fcc/tikim/HEP-FCC_dual-readout_001/dual-readout/install/ele/e_${j}GeV_51th/e_${j}GeV_51th_nohup.out" | grep 'Sigma\|Mean\|StdDev' > "/fcc/tikim/HEP-FCC_dual-readout_001/dual-readout/install/ele/${j}GeV_CSS_MS_Error.txt"
done