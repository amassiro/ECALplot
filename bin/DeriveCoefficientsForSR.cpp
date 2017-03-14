
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
  
  while(!file.eof()) {

    int detId = 0;
    
    pulse.clear();
    
    getline(file,buffer);
    if (buffer != ""){ ///---> save from empty line at the end!
      std::stringstream line( buffer );      
      
      line >> unum; 
      detId = unum;
      
      line >> value; 
      
      int ieta, iphi, ix, iy, iz;
      
      if ( DetId(detId).subdetId() == 1) {
        ieta = EBDetId(detId).ieta();
        iphi = EBDetId(detId).iphi();
        ix = -99;
        iy = -99;
        iz = -99;
      }
      else {
        ieta = -99;
        iphi = -99;
        ix   = EEDetId(detId).ix();
        iy   = EEDetId(detId).iy();
        iz   = EEDetId(detId).zside();
      }
      
      
      if (value>10) {
        std::cout << " problem: " << iphi << ", " << ieta << ", " << ix << ", " << iy << ", " << iz << " ::: " << value << std::endl; 
      }
      else {
        if (ieta != -99) {
          
        }
        else {
          myfile << " " << ix << " " << iy << " " << iz << "     " << value << std::endl;
        }
      }
    }
  }
  
  
  myfile.close(); 
  
  
  std::cout << std::endl;
  
}



  