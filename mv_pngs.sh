for j in 20 30 50 70
# for j in 20 30 50 70 90 110
# for j in 5 10 20 30 50 70 90 110
do
    
    # root_name="${j}GeV_${i:0:-1}"
    # cat "/data4/tikim/dual-readout/install/0_pion/3000Events/${j}GeV_pi/${root_name}_nohup.out" | grep 'Sigma\|Mean\|StdDev' > "/data4/tikim/dual-readout/install/0_pion/3000Events/${j}GeV_pi/${j}GeV_pi_CSS_MS_Error.txt"
    mkdir "/fcc/tikim/results/ele/tungsten/e_${j}GeV_0th/${j}pngs"
    mv /fcc/tikim/results/ele/tungsten/e_${j}GeV_0th/*.png /fcc/tikim/results/ele/tungsten/e_${j}GeV_0th/${j}pngs
    
done