

#   ------------------------------
#     dataset | from run | to run    pb-1
#   ----------+----------+--------
#    Run2016B |   272007 | 275376   5747.968
#    Run2016C |   275657 | 276283   2573.399
#    Run2016D |   276315 | 276811   4248.384
#    Run2016E |   276831 | 277420   4009.132
#    Run2016F |   277772 | 278808   3101.618
#    Run2016G |   278820 | 280385   7540.488
#    Run2016H |   280919 | 284044   2354.053
#   ------------------------------

# DATASET from Run        to Run
# Run2016A        271036  271658
# Run2016B        272007  275376
# Run2016C        275657  276283
# Run2016D        276315  276811
# Run2016E        276831  277420
# Run2016F        277772  278808
# Run2016G        278820  280385
# Run2016H        280919  284044


# from  https://twiki.cern.ch/twiki/bin/view/CMS/PdmV2016Analysis

# 
#  brilcalc lumi -b "STABLE BEAMS" -i filename --normtag /afs/cern.ch/user/l/lumipro/public/normtag_file/normtag_DATACERT.json 
# 


export PATH=$HOME/.local/bin:/afs/cern.ch/cms/lumi/brilconda-1.1.7/bin:$PATH

#  B
brilcalc lumi -b "STABLE BEAMS"  -u /pb --begin 272007 --end 275376         -i /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/Cert_271036-282092_13TeV_PromptReco_Collisions16_JSON.txt     --normtag /afs/cern.ch/user/l/lumipro/public/normtag_file/normtag_DATACERT.json 
# 5747.968
brilcalc lumi -b "STABLE BEAMS"  -u /pb --begin 272007 --end 275376         -i /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/ReReco/Final/Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt     --normtag /afs/cern.ch/user/l/lumipro/public/normtag_file/normtag_DATACERT.json 
# 5788.348
brilcalc lumi -b "STABLE BEAMS"  -u /pb --begin 272007 --end 275376         -i /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/ReReco/Final/Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt    
# 5444.711
brilcalc lumi -b "STABLE BEAMS"  -u /pb --begin 272007 --end 275376         -i /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/ReReco/Final/Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt     --normtag /afs/cern.ch/user/l/lumipro/public/normtag_file/normtag_BRIL.json
# 5981.764
brilcalc lumi -b "STABLE BEAMS"  -u /pb --begin 272007 --end 275376         -i /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/ReReco/Final/Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt     --normtag /afs/cern.ch/user/l/lumipro/public/Normtags/normtag_DATACERT.json
# 5788.348





#  C
brilcalc lumi -b "STABLE BEAMS"  -u /pb --begin 275657 --end 276283         -i /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/Cert_271036-282092_13TeV_PromptReco_Collisions16_JSON.txt     --normtag /afs/cern.ch/user/l/lumipro/public/normtag_file/normtag_DATACERT.json 
# 2573.399
brilcalc lumi -b "STABLE BEAMS"  -u /pb --begin 275657 --end 276283         -i /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/Cert_271036-282092_13TeV_PromptReco_Collisions16_JSON.txt     --normtag /afs/cern.ch/user/l/lumipro/public/normtag_file/normtag_BRIL.json 
# 2632.885
# 2632.885
brilcalc lumi -b "STABLE BEAMS"  -u /pb --begin 275657 --end 276283         -i /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/ReReco/Final/Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt     --normtag /afs/cern.ch/user/l/lumipro/public/Normtags/normtag_DATACERT.json 
# 2573.399



#  D
brilcalc lumi -b "STABLE BEAMS"  -u /pb --begin 276315 --end 276811         -i /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/Cert_271036-282092_13TeV_PromptReco_Collisions16_JSON.txt     --normtag /afs/cern.ch/user/l/lumipro/public/normtag_file/normtag_DATACERT.json 
# 4248.384
brilcalc lumi -b "STABLE BEAMS"  -u /pb --begin 276315 --end 276811         -i /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/ReReco/Final/Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt     --normtag /afs/cern.ch/user/l/lumipro/public/Normtags/normtag_DATACERT.json 
# 4248.384


#  E
brilcalc lumi -b "STABLE BEAMS"  -u /pb --begin 276831 --end 277420         -i /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/Cert_271036-282092_13TeV_PromptReco_Collisions16_JSON.txt     --normtag /afs/cern.ch/user/l/lumipro/public/normtag_file/normtag_DATACERT.json 
# 4009.132
brilcalc lumi -b "STABLE BEAMS"  -u /pb --begin 276831 --end 277420         -i /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/ReReco/Final/Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt     --normtag /afs/cern.ch/user/l/lumipro/public/Normtags/normtag_DATACERT.json 
# 4009.132


#  F
brilcalc lumi -b "STABLE BEAMS"  -u /pb --begin 277772 --end 278808         -i /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/Cert_271036-282092_13TeV_PromptReco_Collisions16_JSON.txt     --normtag /afs/cern.ch/user/l/lumipro/public/normtag_file/normtag_DATACERT.json 
# 3101.618
brilcalc lumi -b "STABLE BEAMS"  -u /pb --begin 277772 --end 278808         -i /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/ReReco/Final/Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt     --normtag /afs/cern.ch/user/l/lumipro/public/Normtags/normtag_DATACERT.json 



#  G
brilcalc lumi -b "STABLE BEAMS"  -u /pb --begin 278820 --end 280385         -i /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/Cert_271036-282092_13TeV_PromptReco_Collisions16_JSON.txt     --normtag /afs/cern.ch/user/l/lumipro/public/normtag_file/normtag_DATACERT.json 
# 7540.488
brilcalc lumi -b "STABLE BEAMS"  -u /pb --begin 278820 --end 280385         -i /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/ReReco/Final/Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt     --normtag /afs/cern.ch/user/l/lumipro/public/Normtags/normtag_DATACERT.json 



#  H
brilcalc lumi -b "STABLE BEAMS"  -u /pb --begin 280919 --end 284044         -i /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/Cert_271036-282092_13TeV_PromptReco_Collisions16_JSON.txt     --normtag /afs/cern.ch/user/l/lumipro/public/normtag_file/normtag_DATACERT.json 
# 2354.053
brilcalc lumi -b "STABLE BEAMS"  -u /pb --begin 280919 --end 284044         -i /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/ReReco/Final/Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt     --normtag /afs/cern.ch/user/l/lumipro/public/Normtags/normtag_DATACERT.json 









