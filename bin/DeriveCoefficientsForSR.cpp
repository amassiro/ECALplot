
//---- std include ----
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <fstream> 

//---- ROOT
#include "TF1.h"
#include "TGraph.h"
#include "TString.h"
#include "TFile.h"
#include "TH2F.h"


//---- ECAL 
#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"
#include "DataFormats/EcalDetId/interface/EBDetId.h"
#include "DataFormats/EcalDetId/interface/EEDetId.h"
// #include "DataFormats/EcalDetId/interface/EcalSubdetector.h"

// #include "Calibration/Tools/interface/EcalRingCalibrationTools.h"
// #include "Geometry/CaloGeometry/interface/CaloSubdetectorGeometry.h"
// #include "Geometry/CaloGeometry/interface/CaloGeometry.h"
// #include "Geometry/Records/interface/CaloGeometryRecord.h"


short getRingIndex(DetId id) {
  if (id.det() != DetId::Ecal)
    return -1;
  
  if (id.subdetId() == EcalBarrel) {
    return EBDetId(id).ieta(); 
//     if(EBDetId(id).ieta()<0) 
//       return EBDetId(id).ieta() + 85; 
//     else 
//       return EBDetId(id).ieta() + 84; 
  }
  if (id.subdetId() == EcalEndcap) {
    
    EEDetId eid(id);
    
    short ix   = eid.ix();
    short iy   = eid.iy();
    short iz   = eid.zside();
    
    
    short endcapRingIndex = 51 - sqrt((ix-50) * (ix-50) + (iy-50) * (iy-50));  
    if (iz == 1) {
      endcapRingIndex = endcapRingIndex + 85;
    }
    else {
      endcapRingIndex = -85 - endcapRingIndex;
    }
    return endcapRingIndex;
  }
  return -1;
}





int main(int argc, char** argv) {
  
  std::cout << " Plot coefficients " << std::endl;
  
  std::vector<float> pulse;

   
  std::string output_file_tail = "";
  if (argc >=3) {
    std::cout << " Output file = " << argv[2] << std::endl;
    output_file_tail =  argv[2];
  }

  
  std::cout << " Input file = " << argv[1] << std::endl;
  
  std::ifstream file (argv[1]); 
  
  std::string buffer;
  unsigned int unum;
  float value;
  
  if(!file.is_open())
  {
    std::cerr << "** ERROR: Can't open '" << argv[1] << "' for input" << std::endl;
    return false;
  }

  
  
  TString nametemp;
  nametemp = Form ("values_SRatPF_%s.txt", output_file_tail.c_str());
  
  std::ofstream myfile;
  myfile.open (nametemp.Data());
  
//   0.35 GeV in EB 0.60 in EE
//   alpha 1.5 in EB, 1.16 in EE
  
  float adc2gev_EE = 0.60;
  float adc2gev_EB = 0.35;
  
  float alpha_EE = 1.6;
  float alpha_EB = 1.5;
  
  nametemp = Form ("testSummary_rings_%s.root", output_file_tail.c_str());
  TFile* fileOutSummary = new TFile (nametemp.Data(), "RECREATE");
  
  TH2F* h_EB  = new TH2F ("h_EB", "Ring",   360, 0.5, 360.5,  171, -85.5, 85.5); 
  TH2F* h_EE  = new TH2F ("h_EE", "Ring",   200, 0.5, 200.5,  100, 0.5, 100.5);

  TH2F* h_value_EB  = new TH2F ("h_value_EB", "Value",   360, 0.5, 360.5,  171, -85.5, 85.5); 
  TH2F* h_value_EE  = new TH2F ("h_value_EE", "Value",   200, 0.5, 200.5,  100, 0.5, 100.5);
  
  TH1F* h_value_all  = new TH1F ("h_value_all", "Value vs Ring",  250, -125, 125); 
  
  
  
//   EcalRingCalibrationTools toolForCalib;

  std::map < int, float > map_of_values;
  
  while(!file.eof()) {

    int detId = 0;
    
    pulse.clear();
    
    getline(file,buffer);
    if (buffer != ""){ ///---> save from empty line at the end!
      std::stringstream line( buffer );      
      
      line >> unum; 
      detId = unum;
      
      line >> value; 
      
      int ieta, iphi, ix, iy, iz, iring;
      
      if ( DetId(detId).subdetId() == 1) {
        ieta = EBDetId(detId).ieta();
        iphi = EBDetId(detId).iphi();
        ix = -99;
        iy = -99;
        iz = -99;
//         iring = toolForCalib.getRingIndex(detId);
        iring = getRingIndex(detId);
      }
      else {
        ieta = -99;
        iphi = -99;
        ix   = EEDetId(detId).ix();
        iy   = EEDetId(detId).iy();
        iz   = EEDetId(detId).zside();
//         iring = toolForCalib.getRingIndex(detId);
        iring = getRingIndex(detId);
      }
      
      
      if (value>10) {
        std::cout << " problem: " << iphi << ", " << ieta << ", " << ix << ", " << iy << ", " << iz << " ::: " << value << std::endl; 
      }
      else {
        if (ieta != -99) {
//           myfile << " " << iphi << " " << ieta << "     " << adc2gev_EB * pow(1./value, alpha_EB) << std::endl;
          map_of_values[iring] = adc2gev_EB * pow(1./value, alpha_EB);
//           myfile << " " << iring << "     " << adc2gev_EB * pow(1./value, alpha_EB) << std::endl;
        }
        else {
//           myfile << " " << ix << " " << iy << " " << iz << "     " <<  adc2gev_EE * pow(1./value, alpha_EE) << std::endl;
          map_of_values[iring] = adc2gev_EE * pow(1./value, alpha_EE);
//           myfile << " " << iring  << "     " <<  adc2gev_EE * pow(1./value, alpha_EE) << std::endl;
        }
      }
      
      
      if (ieta != -99) {
        h_EB  -> Fill (iphi, ieta, iring);
      }
      else {
        h_EE  -> Fill (iz < 0 ? ix : ix+100, iy, iring);      
      }
      
      
      if (ieta != -99) {
        h_value_EB  -> Fill (iphi, ieta,  map_of_values[iring]);
      }
      else {
        h_value_EE  -> Fill (iz < 0 ? ix : ix+100, iy,  map_of_values[iring]);      
      }
            
    }
  }
  
  
  
  for (std::map<int,float>::iterator it = map_of_values.begin(); it != map_of_values.end(); it++) {
    myfile << " " <<  it->first  << "     " << it->second << std::endl;
    h_value_all  -> Fill (it->first, it->second);
  }
  
  myfile.close(); 
  
  
  
  fileOutSummary->cd();
  
  h_EB -> GetXaxis() -> SetTitle("iphi");
  h_EB -> GetYaxis() -> SetTitle("ieta");
  
  h_EE -> GetXaxis() -> SetTitle("X");
  h_EE -> GetYaxis() -> SetTitle("Y");
  
  h_EB  -> Write();
  h_EE  -> Write();
  

  h_value_EB -> GetXaxis() -> SetTitle("iphi");
  h_value_EB -> GetYaxis() -> SetTitle("ieta");
  
  h_value_EE -> GetXaxis() -> SetTitle("X");
  h_value_EE -> GetYaxis() -> SetTitle("Y");
  
  h_value_EB  -> Write();
  h_value_EE  -> Write();
  

  h_value_all -> GetXaxis() -> SetTitle("Ring");
  h_value_all -> GetYaxis() -> SetTitle("Value");
  h_value_all  -> Write();
  

  fileOutSummary->Close();
  
  
  std::cout << std::endl;
  
}


  