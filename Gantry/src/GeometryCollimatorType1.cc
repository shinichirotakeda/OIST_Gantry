#include <sstream>

#include "GeometryCollimatorType1.hh"

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
#include "G4Trd.hh"
#include "G4SubtractionSolid.hh"
#include "G4RotationMatrix.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"

#include "G4UnionSolid.hh"
#include "G4IntersectionSolid.hh"

using namespace oistgantry;

G4LogicalVolume* GeometryCollimatorType1::Construct(G4LogicalVolume* localworld) {

  const bool surfaceCheck = true;

  char name[256];
  G4double margin = 0.1*mm; 

  AHG4MaterialManager* mmanager = AHG4MaterialManager::GetAHG4MaterialManager();
  AHG4Material* air = mmanager->instantiate("Vacuum");	

  std::string matname;
  AHG4MaterialProperty* p;
  matname = "AHG4SGD.Tungsten";
  p = mmanager->RetrieveProperty("Tungsten");
  mmanager->registerMaterial(matname, *p);
  AHG4Material* tungsten = mmanager->instantiate(matname);


  matname = "AHG4SGD.Pb";
  p = mmanager->RetrieveProperty("Pb");
  mmanager->registerMaterial(matname, *p);
  AHG4Material* pb = mmanager->instantiate(matname);
  
  // Collimator //////////////////////

  G4double Collimator_surface_distance = 22.5*mm;
  G4double Collimator_segment_angle = 45.0*degree;
  G4double Collimator_zSize = 5.0*mm;
  G4double Collimator_xSize1 = 50.0*mm;
  G4double Collimator_xSize2 = Collimator_xSize1;
  G4double Collimator_ySize1 = 2.0*(Collimator_surface_distance+Collimator_zSize)*std::tan(Collimator_segment_angle*0.5);
  G4double Collimator_ySize2 = 2.0*Collimator_surface_distance*std::tan(Collimator_segment_angle*0.5);
  G4VSolid* Collimator_Solid = new G4Trd("Collimator_Solid", Collimator_xSize1*0.5, Collimator_xSize2*0.5, Collimator_ySize1*0.5, Collimator_ySize2*0.5, Collimator_zSize*0.5);
  
  G4double PinholeCone_Rmin1 = 0.0*mm; 
  G4double PinholeCone_Rmax1 = 0.1*mm; 
  G4double PinholeCone_Rmin2 = 0.0*mm; 
  G4double PinholeCone_Rmax2 = 1.1*mm; 
  G4double PinholeCone_Dz = 5.0*mm; 
  G4VSolid* PinholeCone_up = new G4Cons("PinholeCone_up", PinholeCone_Rmin1,PinholeCone_Rmax1,PinholeCone_Rmin2,PinholeCone_Rmax2, PinholeCone_Dz*0.5, 0.0*deg, 360.0*deg);
  G4VSolid* PinholeCone_down = new G4Cons("PinholeCone_down", PinholeCone_Rmin2,PinholeCone_Rmax2, PinholeCone_Rmin1,PinholeCone_Rmax1,PinholeCone_Dz*0.5, 0.0*deg, 360.0*deg);
  G4UnionSolid *Pinhole_shape = new G4UnionSolid("Pinhole_shape",PinholeCone_up,PinholeCone_down,0,G4ThreeVector(0, 0, -PinholeCone_Dz));
  
  G4double box_xSize = 2.0*PinholeCone_Rmax2;
  G4double box_ySize = 2.0*PinholeCone_Rmax2;
  G4double box_zSize = 2.0*PinholeCone_Dz;
  G4VSolid* box_Solid = new G4Box("box_Solid", box_xSize*0.5, box_ySize*0.5, box_zSize*0.5);
  G4IntersectionSolid *Pinhole= new G4IntersectionSolid("Pinhole",box_Solid,Pinhole_shape,0,G4ThreeVector(0,0,PinholeCone_Dz*0.5));


  G4double pinholepitch = 5.45*mm;
  G4ThreeVector p1(-pinholepitch,pinholepitch,0);
  G4ThreeVector p2(0,pinholepitch,0);
  G4ThreeVector p3(pinholepitch,pinholepitch,0);
  G4ThreeVector p4(-pinholepitch,0,0);
  G4ThreeVector p5(0,0,0);
  G4ThreeVector p6(pinholepitch,0,0);
  G4ThreeVector p7(-pinholepitch,-pinholepitch,0);
  G4ThreeVector p8(0,-pinholepitch,0);
  G4ThreeVector p9(pinholepitch,-pinholepitch,0);
  G4ThreeVector p10(-0.5*pinholepitch,1.5*pinholepitch,0);
  G4ThreeVector p11(0.5*pinholepitch,1.5*pinholepitch,0);
  G4ThreeVector p12(-1.5*pinholepitch,0.5*pinholepitch,0);
  G4ThreeVector p13(-0.5*pinholepitch,0.5*pinholepitch,0);
  G4ThreeVector p14(0.5*pinholepitch,0.5*pinholepitch,0);
  G4ThreeVector p15(1.5*pinholepitch,0.5*pinholepitch,0);
  G4ThreeVector p16(-1.5*pinholepitch,-0.5*pinholepitch,0);
  G4ThreeVector p17(-0.5*pinholepitch,-0.5*pinholepitch,0);
  G4ThreeVector p18(0.5*pinholepitch,-0.5*pinholepitch,0);
  G4ThreeVector p19(1.5*pinholepitch,-0.5*pinholepitch,0);
  G4ThreeVector p20(-0.5*pinholepitch,-1.5*pinholepitch,0);
  G4ThreeVector p21(0.5*pinholepitch,-1.5*pinholepitch,0);
  G4ThreeVector pf(0,0,25.*mm);
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

  axis = pf-p10;
  axis = axis.unit();
  G4RotationMatrix rot_p10;
  rot_p10.rotate(zaxis.angle(axis),zaxis.cross(axis));

  axis = pf-p11;
  axis = axis.unit();
  G4RotationMatrix rot_p11;
  rot_p11.rotate(zaxis.angle(axis),zaxis.cross(axis));

  axis = pf-p12;
  axis = axis.unit();
  G4RotationMatrix rot_p12;
  rot_p12.rotate(zaxis.angle(axis),zaxis.cross(axis));

  axis = pf-p13;
  axis = axis.unit();
  G4RotationMatrix rot_p13;
  rot_p13.rotate(zaxis.angle(axis),zaxis.cross(axis));

  axis = pf-p14;
  axis = axis.unit();
  G4RotationMatrix rot_p14;
  rot_p14.rotate(zaxis.angle(axis),zaxis.cross(axis));

  axis = pf-p15;
  axis = axis.unit();
  G4RotationMatrix rot_p15;
  rot_p15.rotate(zaxis.angle(axis),zaxis.cross(axis));

  axis = pf-p16;
  axis = axis.unit();
  G4RotationMatrix rot_p16;
  rot_p16.rotate(zaxis.angle(axis),zaxis.cross(axis));

  axis = pf-p17;
  axis = axis.unit();
  G4RotationMatrix rot_p17;
  rot_p17.rotate(zaxis.angle(axis),zaxis.cross(axis));

  axis = pf-p18;
  axis = axis.unit();
  G4RotationMatrix rot_p18;
  rot_p18.rotate(zaxis.angle(axis),zaxis.cross(axis));

  axis = pf-p19;
  axis = axis.unit();
  G4RotationMatrix rot_p19;
  rot_p19.rotate(zaxis.angle(axis),zaxis.cross(axis));

  axis = pf-p20;
  axis = axis.unit();
  G4RotationMatrix rot_p20;
  rot_p20.rotate(zaxis.angle(axis),zaxis.cross(axis));

  axis = pf-p21;
  axis = axis.unit();
  G4RotationMatrix rot_p21;
  rot_p21.rotate(zaxis.angle(axis),zaxis.cross(axis));

  
  G4SubtractionSolid *a1 = new G4SubtractionSolid("a1",Collimator_Solid,Pinhole,G4Transform3D(rot_p1, p1));
  G4SubtractionSolid *a2 = new G4SubtractionSolid("a2",a1,Pinhole,G4Transform3D(rot_p2, p2));
  G4SubtractionSolid *a3 = new G4SubtractionSolid("a3",a2,Pinhole,G4Transform3D(rot_p3, p3));
  G4SubtractionSolid *a4 = new G4SubtractionSolid("a4",a3,Pinhole,G4Transform3D(rot_p4, p4));
  G4SubtractionSolid *a5 = new G4SubtractionSolid("a5",a4,Pinhole,G4Transform3D(rot_p5, p5));
  G4SubtractionSolid *a6 = new G4SubtractionSolid("a6",a5,Pinhole,G4Transform3D(rot_p6, p6));
  G4SubtractionSolid *a7 = new G4SubtractionSolid("a7",a6,Pinhole,G4Transform3D(rot_p7, p7));
  G4SubtractionSolid *a8 = new G4SubtractionSolid("a8",a7,Pinhole,G4Transform3D(rot_p8, p8));
  G4SubtractionSolid *a9 = new G4SubtractionSolid("a9",a8,Pinhole,G4Transform3D(rot_p9, p9));
  G4SubtractionSolid *a10 = new G4SubtractionSolid("a10",a9,Pinhole,G4Transform3D(rot_p10, p10));
  G4SubtractionSolid *a11 = new G4SubtractionSolid("a11",a10,Pinhole,G4Transform3D(rot_p11, p11));
  G4SubtractionSolid *a12 = new G4SubtractionSolid("a12",a11,Pinhole,G4Transform3D(rot_p12, p12));
  G4SubtractionSolid *a13 = new G4SubtractionSolid("a13",a12,Pinhole,G4Transform3D(rot_p13, p13));
  G4SubtractionSolid *a14 = new G4SubtractionSolid("a14",a13,Pinhole,G4Transform3D(rot_p14, p14));
  G4SubtractionSolid *a15 = new G4SubtractionSolid("a15",a14,Pinhole,G4Transform3D(rot_p15, p15));
  G4SubtractionSolid *a16 = new G4SubtractionSolid("a16",a15,Pinhole,G4Transform3D(rot_p16, p16));
  G4SubtractionSolid *a17 = new G4SubtractionSolid("a17",a16,Pinhole,G4Transform3D(rot_p17, p17));
  G4SubtractionSolid *a18 = new G4SubtractionSolid("a18",a17,Pinhole,G4Transform3D(rot_p18, p18));
  G4SubtractionSolid *a19 = new G4SubtractionSolid("a19",a18,Pinhole,G4Transform3D(rot_p19, p19));
  G4SubtractionSolid *a20 = new G4SubtractionSolid("a20",a19,Pinhole,G4Transform3D(rot_p20, p20));
  G4SubtractionSolid *a21 = new G4SubtractionSolid("a21",a20,Pinhole,G4Transform3D(rot_p21, p21));
  
  //  G4LogicalVolume* Collimator_Logical = new G4LogicalVolume(a9, tungsten, "Collimator_Logical");
  G4LogicalVolume* Collimator_Logical = new G4LogicalVolume(a21, tungsten, "Collimator_Logical");


  G4double Collimator_xPos = 0.0*mm;
  G4double Collimator_yPos = 0.0*mm;
  G4double Collimator_zPos = -25.0*mm;
  for (int i = 0; i < 8; i++) {    
    G4ThreeVector pos = G4ThreeVector(Collimator_xPos,Collimator_yPos,Collimator_zPos);
    G4RotationMatrix rot = G4RotationMatrix();
    rot.rotateX(-45.0*deg*i);
    pos.rotateX(-45.0*deg*i);
    sprintf(name, "Collimator%02d", i);
    new G4PVPlacement(G4Transform3D(rot,pos), Collimator_Logical, name, localworld, false, 0, surfaceCheck);
  }
  

  // Pb Pipe //////////////////////

  G4double PbShield_surface_distance = 22.5*mm;
  G4double PbShield_segment_angle = 45.0*degree;
  G4double PbShield_zSize = 5.0*mm;
  G4double PbShield_xSize1 = 75.0*mm;
  G4double PbShield_xSize2 = PbShield_xSize1;
  G4double PbShield_ySize1 = 2.0*(PbShield_surface_distance+PbShield_zSize)*std::tan(PbShield_segment_angle*0.5);
  G4double PbShield_ySize2 = 2.0*PbShield_surface_distance*std::tan(PbShield_segment_angle*0.5);
  G4VSolid* PbShield_Solid = new G4Trd("PbShield_Solid", PbShield_xSize1*0.5, PbShield_xSize2*0.5, PbShield_ySize1*0.5, PbShield_ySize2*0.5, PbShield_zSize*0.5);
  G4LogicalVolume* PbShield_Logical = new G4LogicalVolume(PbShield_Solid, pb, "PbShield_Logical");


  G4double PbShield_xPos = Collimator_xPos + Collimator_xSize1*0.5 + PbShield_xSize1*0.5;
  G4double PbShield_yPos = 0.0*mm;
  G4double PbShield_zPos = -25.0*mm;
  for (int i = 0; i < 8; i++) {    
    G4ThreeVector pos = G4ThreeVector(PbShield_xPos,PbShield_yPos,PbShield_zPos);
    G4RotationMatrix rot = G4RotationMatrix();
    rot.rotateX(-45.0*deg*i);
    pos.rotateX(-45.0*deg*i);
    sprintf(name, "PbShield1_%02d", i);
    new G4PVPlacement(G4Transform3D(rot,pos), PbShield_Logical, name, localworld, false, 0, surfaceCheck);
  }


  PbShield_xPos = Collimator_xPos - Collimator_xSize1*0.5 - PbShield_xSize1*0.5;
  PbShield_yPos = 0.0*mm;
  PbShield_zPos = -25.0*mm;
  for (int i = 0; i < 8; i++) {    
    G4ThreeVector pos = G4ThreeVector(PbShield_xPos,PbShield_yPos,PbShield_zPos);
    G4RotationMatrix rot = G4RotationMatrix();
    rot.rotateX(-45.0*deg*i);
    pos.rotateX(-45.0*deg*i);
    sprintf(name, "PbShield2_%02d", i);
    new G4PVPlacement(G4Transform3D(rot,pos), PbShield_Logical, name, localworld, false, 0, surfaceCheck);
  }

 
  G4VisAttributes* Collimator_Attributes = new G4VisAttributes(G4Colour::Red());
  Collimator_Attributes->SetColor(1.0,0.0,1.0,0.5); //magenta
  Collimator_Attributes->SetForceSolid(true);
  //Collimator_Attributes->SetForceWireframe(true);
  Collimator_Logical->SetVisAttributes(Collimator_Attributes);

  G4VisAttributes* PbShield_Attributes = new G4VisAttributes(G4Colour::Red());
  PbShield_Attributes->SetColor(1.0,1.0,1.0,0.5);
  PbShield_Attributes->SetForceSolid(true);
  //PbShield_Attributes->SetForceWireframe(true);
  PbShield_Logical->SetVisAttributes(PbShield_Attributes);


  return localworld;
 
}
