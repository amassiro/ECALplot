# ECALplot


Where:

    /afs/cern.ch/user/a/amassiro/work/ECAL/LocalReco/CMSSW_8_0_26_patch1/src/EcalValidation/ECALplot
    
    
Install:

    cmsrel CMSSW_8_0_26_patch1
    cd CMSSW_8_0_26_patch1/src/
    cmsenv
    mkdir EcalValidation
    cd EcalValidation
    git clone git@github.com:amassiro/ECALplot.git
    scramv1 b -j 5
    
    
Inputs:

    /afs/cern.ch/user/k/kbelobor/public/ForShervin/p2_prediction_IL*.dat
    
    
Run:

    PlotCoefficients   /afs/cern.ch/user/k/kbelobor/public/ForShervin/p2_prediction_IL90.dat       IL90
    PlotCoefficients   /afs/cern.ch/user/k/kbelobor/public/ForShervin/p2_prediction_IL120.dat      IL120

