void test(){

  gROOT->Reset();
  TFile *fin = new TFile("image.root");
  TDirectoryFile* din = (TDirectoryFile*)fin->Get("OISTDetectorImage");
  TH2 *hin = (TH2 *)din->Get("image_ecut_0100");

  int xbin = hin->GetXaxis()->GetNbins();
  int ybin = hin->GetYaxis()->GetNbins();

  ofstream fout("out.txt");
  
  for(int i=1;i<=xbin;i++){
    for(int j=1;j<=ybin;j++){
      fout<< i << " " << j << " " << hin->GetBinContent(i,j) << std::endl; 
    }
  }


  fout.close();
  hin->Draw("colz");
  
   
}

