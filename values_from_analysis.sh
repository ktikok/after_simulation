# while :
# do
#     if [[ $(tail -1 0_pion/3000Events/110GeV_pi/110GeV_pi_nohup.out) = "Done" ]]; then
#         break
#         # if analysis is done, then, bring values to a text file.
#     else
#         sleep 5
#     fi  
# done

for j in 5 10 20 30 50 70
# for j in 20 30 50 70 90 110
# for j in 5 10 20 30 50 70 90 110
do
    
    # root_name="${j}GeV_${i:0:-1}"
    # cat "/data4/tikim/dual-readout/install/0_pion/3000Events/${j}GeV_pi/${root_name}_nohup.out" | grep 'Sigma\|Mean\|StdDev' > "/data4/tikim/dual-readout/install/0_pion/3000Events/${j}GeV_pi/${j}GeV_pi_CSS_MS_Error.txt"
    
    #//////////////////////////////////////////////////////////////////// change name
    cat "/fcc/tikim/results/ele/brass/e_${j}GeV_0th/e_${j}GeV_0th_nohup.out" | grep 'Sigma\|Mean\|StdDev' > "/fcc/tikim/results/ele/brass/${j}GeV_CSS_MS_Error.txt"
    #//////////////////////////////////////////////////////////////////// change name
    
    #    /fcc/tikim/results/ele/brass/e_5GeV_0th/e_5GeV_0th_nohup.out
done