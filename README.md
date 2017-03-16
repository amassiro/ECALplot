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
    PlotCoefficients   /afs/cern.ch/user/k/kbelobor/public/ForShervin/p2_prediction_IL100.dat       IL100
    PlotCoefficients   /afs/cern.ch/user/k/kbelobor/public/ForShervin/p2_prediction_IL120.dat      IL120


    PlotCoefficients   p2_prediction_IL100_corr.dat           IL100corr
    PlotCoefficients   p2_prediction_IL100_corr_3rms.dat      IL100corrFilter3sigma
    PlotCoefficients   p2_prediction_IL100_corr_3rms_av.dat   IL100corrFilter3sigma

    PlotCoefficients   p2_prediction_IL75_corr_3rms_av.dat    IL75corrFilter3sigma

    cat laserTag_MC_80X_2017.dat | tr "P" " " > laserTag_MC_80X_2017_filter.dat
    then remove the first line
    PlotCoefficients   laserTag_MC_80X_2017_filter.dat    laserTag_MC_80X_2017_filter

    DeriveCoefficientsForSR   laserTag_MC_80X_2017_filter.dat    laserTag_MC_80X_2017_filter



Get from DB:

    cd CMSSW_8_0_26_patch1/src/
    git cms-init
    git clone git@github.com:ferriff/usercode.git
    git cms-merge-topic -u ferriff:ecal_calib_tools
    scramv1 b -j 5
    
    conddb_dumper -c frontier://FrontierProd/CMS_CONDITIONS -t EcalChannelStatus_v09_offline -O EcalChannelStatus
    conddb_dumper -t EcalChannelStatus_v09_offline -O EcalChannelStatus
    less dump_EcalChannelStatus__since_00280945_till_18446744073709551615.dat|awk '{print $5,$4}'>channel_status_160916_280945.dat
    

    
    PlotChannelStatus   dump_EcalChannelStatus__since_00285090_till_18446744073709551615.dat


    
Download from DB the laser tag:

    lava_db  -c  /afs/cern.ch/work/e/ecalmon/public/dropbox/MC_Tag/EcallaserTag_MC_80X_2017.db     -t EcalLaserAPDPNRatios_2017_mc
    

The IC in MC:

    /afs/cern.ch/user/r/ric/public/4rafael/dump_EcalIntercalibConstants__since_00000001_till_18446744073709551615.dat

    
    