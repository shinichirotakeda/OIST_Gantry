

void calforconf(){

  gROOT->Reset();

  int id = 7;
  
  double orgposx = -1.25;
  double orgposy = -5.0 - 1.25;
  double orgposz = -48.0-0.75/2.;
  double angle = -TMath::Pi()/180.*(45.*id); 

  TVector3 orgvec(orgposx,orgposy,orgposz);
  TVector3 vec = orgvec;
  vec.RotateX(angle);
  std::cout<< vec.X() << " " << vec.Y() << " " << vec.Z() << std::endl;

  TVector3 vx(1.0,0.0,0.0);
  TVector3 vy(0.0,1.0,0.0);
  vx.RotateX(angle);
  std::cout<< vx.X() << " " << vx.Y() << " " << vx.Z() << std::endl;
  vy.RotateX(angle);
  std::cout<< vy.X() << " " << vy.Y() << " " << vy.Z() << std::endl; 

  
}
