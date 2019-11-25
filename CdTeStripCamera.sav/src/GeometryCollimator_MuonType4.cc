#include <sstream>

#include "GeometryCollimator_MuonType4.hh"

#include "AHG4MaterialManager.hh"

#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4PVPlacement.hh"
#include "G4PVParameterised.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Cons.hh"
#include "G4SubtractionSolid.hh"
#include "G4RotationMatrix.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"

#include "G4UnionSolid.hh"
#include "G4IntersectionSolid.hh"

using namespace cdtestripcamerageometry;

G4LogicalVolume* GeometryCollimator_MuonType4::Construct(G4ThreeVector *pos) {

  const bool surfaceCheck = false;
  G4double margin = 0.1*mm; 

  AHG4MaterialManager* mmanager = AHG4MaterialManager::GetAHG4MaterialManager();
  AHG4Material* air = mmanager->instantiate("Vacuum");	

  std::string matname;
  AHG4MaterialProperty* p;
  matname = "AHG4SGD.Tungsten";
  p = mmanager->RetrieveProperty("Tungsten");
  mmanager->registerMaterial(matname, *p);
  AHG4Material* tungsten = mmanager->instantiate(matname);


  // Collimator //////////////////////

  G4double Collimator_rmax = 38.0*mm;
  G4double Collimator_zSize = 8.0*mm;
  G4VSolid* Collimator_Solid = new G4Tubs("Collimator_Solid", 0, Collimator_rmax, Collimator_zSize*0.5,0.0*deg,360.0*deg);
  G4LogicalVolume* Collimator_Logical = new G4LogicalVolume(Collimator_Solid, tungsten, "Collimator_Logical");

  G4double PinholeCone_Rmin1 = 0.0*mm; 
  G4double PinholeCone_Rmax1 = 0.5*mm; 
  G4double PinholeCone_Rmin2 = 0.0*mm; 
  G4double PinholeCone_Rmax2 = 1.1*mm; 
  G4double PinholeCone_Dz = 4.0*mm; 
  G4double PinholeCone_SPhi = 0.0*deg;; 
  G4double PinholeCone_DPhi = 360.0*deg;; 
  G4VSolid* PinholeCone_up = new G4Cons("PinholeCone_up", PinholeCone_Rmin1,PinholeCone_Rmax1,PinholeCone_Rmin2,PinholeCone_Rmax2,PinholeCone_Dz,PinholeCone_SPhi,PinholeCone_DPhi);
  G4VSolid* PinholeCone_down = new G4Cons("PinholeCone_down", PinholeCone_Rmin1,PinholeCone_Rmax1,PinholeCone_Rmin2,PinholeCone_Rmax2,PinholeCone_Dz,PinholeCone_SPhi,PinholeCone_DPhi);

  G4RotationMatrix yRot180deg;
  yRot180deg.rotateY(180.*degree);
  G4ThreeVector  translation(0, 0, -2.0*PinholeCone_Dz);
  G4UnionSolid *Pinhole_shape = new G4UnionSolid("Pinhole_shape",PinholeCone_up,PinholeCone_down,&yRot180deg,translation);
  
  G4double box_xSize = 3.2*mm;
  G4double box_ySize = 3.2*mm;
  G4double box_zSize = 16.0*mm;
  G4VSolid* box_Solid = new G4Box("box_Solid", box_xSize*0.5, box_ySize*0.5, box_zSize*0.5);
  G4IntersectionSolid *Pinhole= new G4IntersectionSolid("Pinhole",box_Solid,Pinhole_shape,0,G4ThreeVector(0,0,PinholeCone_Dz));
  G4LogicalVolume* Pinhole_logical = new G4LogicalVolume(Pinhole, air, "Pinhole_Logical");

  G4ThreeVector p1(-6.54*mm,6.54*mm,0);
  G4ThreeVector p2(0,6.54*mm,0);
  G4ThreeVector p3(6.54*mm,6.54*mm,0);
  G4ThreeVector p4(-6.54*mm,0,0);
  G4ThreeVector p5(0,0,0);
  G4ThreeVector p6(6.54*mm,0,0);
  G4ThreeVector p7(-6.54*mm,-6.54*mm,0);
  G4ThreeVector p8(0,-6.54*mm,0);
  G4ThreeVector p9(6.54*mm,-6.54*mm,0);
  G4ThreeVector pf(0,0,100.*mm);
  G4ThreeVector zaxis(0,0,1);
  G4ThreeVector axis;

  axis = pf-p1;
  axis = axis.unit();
  G4RotationMatrix rot_p1;
  rot_p1.rotate(zaxis.angle(axis),zaxis.cross(axis));

  axis = pf-p2;
  axis = axis.unit();
  G4RotationMatrix rot_p2;
  rot_p2.rotate(zaxis.angle(axis),zaxis.cross(axis));

  axis = pf-p3;
  axis = axis.unit();
  G4RotationMatrix rot_p3;
  rot_p3.rotate(zaxis.angle(axis),zaxis.cross(axis));

  axis = pf-p4;
  axis = axis.unit();
  G4RotationMatrix rot_p4;
  rot_p4.rotate(zaxis.angle(axis),zaxis.cross(axis));

  axis= pf-p5;
  axis = axis.unit();
  G4RotationMatrix rot_p5;
  rot_p5.rotate(zaxis.angle(axis),zaxis.cross(axis));

  axis = pf-p6;
  axis = axis.unit();
  G4RotationMatrix rot_p6;
  rot_p6.rotate(zaxis.angle(axis),zaxis.cross(axis));

  axis = pf-p7;
  axis = axis.unit();
  G4RotationMatrix rot_p7;
  rot_p7.rotate(zaxis.angle(axis),zaxis.cross(axis));

  axis = pf-p8;
  axis = axis.unit();
  G4RotationMatrix rot_p8;
  rot_p8.rotate(zaxis.angle(axis),zaxis.cross(axis));

  axis = pf-p9;
  axis = axis.unit();
  G4RotationMatrix rot_p9;
  rot_p9.rotate(zaxis.angle(axis),zaxis.cross(axis));
  
  new G4PVPlacement(G4Transform3D(rot_p1, p1), Pinhole_logical, "PinholeCollimatorP1", Collimator_Logical, false, 0, surfaceCheck);
  new G4PVPlacement(G4Transform3D(rot_p2, p2), Pinhole_logical, "PinholeCollimatorP2", Collimator_Logical, false, 0, surfaceCheck);
  new G4PVPlacement(G4Transform3D(rot_p3, p3), Pinhole_logical, "PinholeCollimatorP3", Collimator_Logical, false, 0, surfaceCheck);
  new G4PVPlacement(G4Transform3D(rot_p4, p4), Pinhole_logical, "PinholeCollimatorP4", Collimator_Logical, false, 0, surfaceCheck);
  new G4PVPlacement(G4Transform3D(rot_p5, p5), Pinhole_logical, "PinholeCollimatorP5", Collimator_Logical, false, 0, surfaceCheck);
  new G4PVPlacement(G4Transform3D(rot_p6, p6), Pinhole_logical, "PinholeCollimatorP6", Collimator_Logical, false, 0, surfaceCheck);
  new G4PVPlacement(G4Transform3D(rot_p7, p7), Pinhole_logical, "PinholeCollimatorP7", Collimator_Logical, false, 0, surfaceCheck);
  new G4PVPlacement(G4Transform3D(rot_p8, p8), Pinhole_logical, "PinholeCollimatorP8", Collimator_Logical, false, 0, surfaceCheck);
  new G4PVPlacement(G4Transform3D(rot_p9, p9), Pinhole_logical, "PinholeCollimatorP9", Collimator_Logical, false, 0, surfaceCheck);
  

  G4VisAttributes* Pinhole_Attributes = new G4VisAttributes(G4Colour(1.0,1.0,1.0,1.0));
  Pinhole_Attributes->SetForceSolid(true);
  Pinhole_logical->SetVisAttributes(Pinhole_Attributes);
  
  G4VisAttributes* Collimator_Attributes = new G4VisAttributes(G4Colour::Red());
  Collimator_Attributes->SetForceSolid(true);
  Collimator_Logical->SetVisAttributes(Collimator_Attributes);
  
  pos->setX(0.);
  pos->setY(0.);
  pos->setZ(68.0*mm);
  return Collimator_Logical;
 
}
