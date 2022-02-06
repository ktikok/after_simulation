# source init_lcg.sh does not work by script. you should do it manually

#run the bellow command
# nohup ./1run_simulation.sh > 1_nohup.out & tail -f 1_nohup.out


#for i in "e-" "pi+"
for i in "e-"
# particle names(e-, pi+)
do
    run_beamOn="2"




    for j in 5
    # for j in 5 10 20 30 50 70 90 110
    # energy with the unit of GeV. I did alread for 20GeV
    do
        #x1=$((${j} - 10))
        
      
        #if [ "$i" = "e-" ]
        #then
        #
        #fi 
        
        #------------------------------------------------------------#
        # events number = beamon*queue. so change "/run/beamOn 10" when you simulate difrerent events number.
        # usually queue = 100, so, you may change beamOn 10 or 30.
        #------------------------------------------------------------#
                
        gun_particle=$i
        #gun_particle="pi+"
        gun_energy="$j GeV"
        # root_name="${j}GeV_${i:0:-1}"
        root_name="${i:0:-1}_${j}GeV_0th"
        results="/fcc/tikim/results/ele/lead/$root_name/"

        echo "starting submit for $gun_energy $gun_particle and the output will be $root_name.root"    
        echo ""
        
        # ctrl+shift+L >> select same words    


        # ---------------------------
        # theta : -0.03728991884
        # phi : 0.01745329252
        # y(cm) : -3.142302266
        # z(cm) : -4.716005797
        # ---------------------------
        echo "/DRsim/action/useHepMC False" > 1run.mac
        echo "/DRsim/action/useCalib True" >> 1run.mac
        echo "/vis/disable" >> 1run.mac
        echo "/run/numberOfThreads 1" >> 1run.mac
        echo "/run/initialize" >> 1run.mac
        echo "/run/verbose 1" >> 1run.mac
        echo "/DRsim/generator/randx 10" >> 1run.mac
        echo "/DRsim/generator/randy 10" >> 1run.mac
        echo "/DRsim/generator/theta -0.03728991884" >> 1run.mac
        echo "/DRsim/generator/phi 0.01745329252" >> 1run.mac
        echo "/DRsim/generator/y0 -3.142302266" >> 1run.mac
        echo "/DRsim/generator/z0 -4.716005797" >> 1run.mac
        echo "/gun/particle $i" >> 1run.mac
        echo "/gun/energy $j GeV" >> 1run.mac
        echo "/run/beamOn $run_beamOn" >> 1run.mac


        echo "#! /bin/sh" > 1run.sh
        echo "export PATH=/cvmfs/sft.cern.ch/lcg/contrib/CMake/3.14.2/Linux-x86_64/bin:\$PATH" >> 1run.sh
        echo "source /cvmfs/sft.cern.ch/lcg/contrib/gcc/8/x86_64-centos7/setup.sh" >> 1run.sh
        echo "source /cvmfs/sft.cern.ch/lcg/releases/LCG_96b/ROOT/6.18.04/x86_64-centos7-gcc8-opt/ROOT-env.sh" >> 1run.sh
        echo "source /cvmfs/geant4.cern.ch/geant4/10.5.p01/x86_64-centos7-gcc8-opt-MT/CMake-setup.sh" >> 1run.sh
        echo "export HEPMC_DIR=/cvmfs/sft.cern.ch/lcg/releases/LCG_96b/hepmc3/3.1.2/x86_64-centos7-gcc8-opt" >> 1run.sh
        echo "export FASTJET_DIR=/cvmfs/sft.cern.ch/lcg/releases/LCG_96b/fastjet/3.3.2/x86_64-centos7-gcc8-opt" >> 1run.sh
        echo "export PYTHIA_DIR=/cvmfs/sft.cern.ch/lcg/releases/LCG_96b/MCGenerators/pythia8/240/x86_64-centos7-gcc8-opt" >> 1run.sh
        echo "export PYTHIA8=/cvmfs/sft.cern.ch/lcg/releases/LCG_96b/MCGenerators/pythia8/240/x86_64-centos7-gcc8-opt" >> 1run.sh
        echo "export PYTHIA8DATA=/cvmfs/sft.cern.ch/lcg/releases/LCG_96b/MCGenerators/pythia8/240/x86_64-centos7-gcc8-opt/share/Pythia8/xmldoc" >> 1run.sh
        echo "export ROOT_INCLUDE_PATH=/cvmfs/sft.cern.ch/lcg/releases/LCG_96b/hepmc3/3.1.2/x86_64-centos7-gcc8-opt/include:\$ROOT_INCLUDE_PATH" >> 1run.sh
        echo "export LD_LIBRARY_PATH=\$LD_LIBRARY_PATH:\$HEPMC_DIR/lib64:\$FASTJET_DIR/lib:\$PYTHIA_DIR/lib:\$PWD/lib" >> 1run.sh
        echo "./bin/DRsim 1run.mac \$1 $results/root/$root_name" >> 1run.sh

        echo "universe = vanilla" > 1run.sub
        echo "executable = 1run.sh" >> 1run.sub
        echo "arguments = \$(ProcId)" >> 1run.sub
        echo "output = $results/log/\$(ProcId).out" >> 1run.sub
        echo "error = $results/log/\$(ProcId).err" >> 1run.sub
        echo "log = $results/log/\$(ProcId).log" >> 1run.sub
        echo "request_memory = 3 GB" >> 1run.sub
        echo "should_transfer_files = YES" >> 1run.sub
        echo "when_to_transfer_output = ON_EXIT" >> 1run.sub
        echo "transfer_input_files =./bin, ./lib, ./init.mac, ./1run.mac" >> 1run.sub
        echo "queue 500" >> 1run.sub



        #cat 0_SimulationShFile.sh
        mkdir "$results"
        mkdir "$results/log"
        mkdir "$results/root"
        condor_submit 1run.sub

        #break
        flag=`condor_q -all | grep "tikim98"`
        # #flag1=$(condor_q -all | grep "tikim ID")
        # #same command

        # echo $flag
        while [ "${flag:1:2}" == "ik" ]
        do 
            sleep 1m
            flag=`condor_q -all | grep "tikim98"`        

        done
        # #echo $((${j} - 10))
        # #break
        echo "Simulation is done"
        echo "preparing analysis"
        hadd "$results/$root_name.root" "$results/root/$root_name*.root"
        #./bin/analysis "$root_name" $((${j} - 10)) $((${j} + 10))
        
        # mv "$root_name.root" $results

        cp 1run.* $results
    done
    
done

