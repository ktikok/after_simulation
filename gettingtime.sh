
name="copper"

echo ""
# for j in 5 10 20 30 50 70
for j in 5 10 30 50 70
do
    
    cat "/fcc/tikim/results/ele/${name}/e_${j}GeV_51th/log/0.log" | grep "000 ("
    # cat "/fcc/tikim/results/ele/${name}/e_${j}GeV_51th/log_e_${j}GeV_51th/0.log" | grep "000 ("

    
done
echo ""
for j in 5 10 30 50 70
# for j in 5 10 20 30 50 70
do
    
    ls -l "/fcc/tikim/results/ele/${name}/e_${j}GeV_51th/" |grep log
    
done
echo ""