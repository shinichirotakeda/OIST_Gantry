#include <sstream>

#include "GeometryGantry.hh"
#include "AHG4MaterialManager.hh"

#include "GeometryCollimator.hh"
#include "GeometryCollimatorType1.hh"

#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4PVPlacement.hh"
#include "G4PVParameterised.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Trap.hh"
#include "G4SubtractionSolid.hh"
#include "G4UnionSolid.hh"
#include "G4RotationMatrix.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"

using namespace oistgantry;

G4LogicalVolume* GeometryGantry::Construct(std::string detname) {

  const bool surfaceCheck = true;

  char name[256];
  G4double margin = 0.1*mm;  

  AHG4MaterialManager* mmanager = AHG4MaterialManager::GetAHG4MaterialManager();
  AHG4Material* air = mmanager->instantiate("Vacuum");
  std::string matname;
  AHG4MaterialProperty* p;

  matname = "AHG4SGD.Si";
  p = mmanager->RetrieveProperty("Si");
  mmanager->registerMaterial(matname, *p);
  AHG4Material* si = mmanager->instantiate(matname);
  
  matname = "AHG4SGD.CdTe";
  p = mmanager->RetrieveProperty("CdTe");
  mmanager->registerMaterial(matname, *p);
  AHG4Material* cdte = mmanager->instantiate(matname);

  matname = "AHG4SGD.Aluminium";
  p = mmanager->RetrieveProperty("Aluminium");
  mmanager->registerMaterial(matname, *p);
  AHG4Material* aluminium = mmanager->instantiate(matname);

  matname = "AHG4SGD.Cu";
  p = mmanager->RetrieveProperty("Cu");
  mmanager->registerMaterial(matname, *p);
  AHG4Material* copper = mmanager->instantiate(matname);

  matname = "AHG4SGD.Alumina";
  p = mmanager->RetrieveProperty("Alumina");
  mmanager->registerMaterial(matname, *p);
  AHG4Material* alumina = mmanager->instantiate(matname);

  matname = "AHG4SGD.Beryllium";
  p = mmanager->RetrieveProperty("Beryllium");
  mmanager->registerMaterial(matname, *p);
  AHG4Material* beryllium = mmanager->instantiate(matname);

  
  matname = "AHG4SGD.Polyimide";
  p = mmanager->RetrieveProperty("Polyimide");
  mmanager->registerMaterial(matname, *p);
  AHG4Material* polyimide = mmanager->instantiate(matname);

  matname = "AHG4SGD.FR4";
  p = mmanager->RetrieveProperty("FR4");
  mmanager->registerMaterial(matname, *p);
  AHG4Material* fr4 = mmanager->instantiate(matname);

  matname = "AHG4SGD.Delrin";
  p = mmanager->RetrieveProperty("Delrin");
  mmanager->registerMaterial(matname, *p);
  AHG4Material* delrin = mmanager->instantiate(matname);
  
  // Local World //////////////////////
  G4double LocalWorld_xSize = 1000.0*mm;
  G4double LocalWorld_ySize = 1000.0*mm;
  G4double LocalWorld_zSize = 1000.0*mm;
  G4VSolid* LocalWorld_Solid = new G4Box("LocalWorld_Solid", LocalWorld_xSize*0.5, LocalWorld_ySize*0.5, LocalWorld_zSize*0.5);
  G4LogicalVolume* LocalWorld_Logical = new G4LogicalVolume(LocalWorld_Solid, air, "LocalWorld_Logical");


 //======= CdTe-Double-sided Strip Ditectors  ======

  //CdTe Strip
  G4double CdTe_DSD_xSize = 36.5*mm;
  G4double CdTe_DSD_ySize = 36.5*mm;
  G4double CdTe_DSD_zSize = 0.75*mm;
  G4VSolid* CdTe_DSD = new G4Box("CdTe_DSD", CdTe_DSD_xSize*0.5, CdTe_DSD_ySize*0.5, CdTe_DSD_zSize*0.5);
  G4LogicalVolume* CdTe_DSD_Logical = new G4LogicalVolume(CdTe_DSD, cdte, "CdTe_DSD_Logical");

  //FEC Holder
  G4double FECHolder_xSize = 168.0*mm;
  G4double FECHolder_ySize = 87.0*mm;
  G4double FECHolder_zSize = 1.8*mm;
  G4VSolid* FECHolder = new G4Box("FECHolder", FECHolder_xSize*0.5, FECHolder_ySize*0.5, FECHolder_zSize*0.5);
  G4LogicalVolume* FECHolder_Logical = new G4LogicalVolume(FECHolder, aluminium, "FECHolder_Logical");
  
  // Ceramic Spacer /////////////////////////////////
  G4double Ceramic_Spacer_xSize = 128.0*mm;
  G4double Ceramic_Spacer_ySize = 87.0*mm;
  G4double Ceramic_Spacer_zSize = 1.0*mm;
  G4VSolid* Ceramic_Spacer_Solid = new G4Box("Ceramic_Spacer_Solid", Ceramic_Spacer_xSize*0.5, Ceramic_Spacer_ySize*0.5, Ceramic_Spacer_zSize*0.5);
  G4LogicalVolume* Ceramic_Spacer_Logical = new G4LogicalVolume(Ceramic_Spacer_Solid, alumina, "Ceramic_Spacer_Logical");

  
  //FEC Kiban
  G4double FecKiban_zSize = 1.6*mm;
  G4double FecKibanBody_xSize = 128.0*mm;
  G4double FecKibanBody_ySize = 87.0*mm;
  G4double FecKibanBody_zSize = FecKiban_zSize;
  G4VSolid* FecKibanBody_Solid = new G4Box("FecKibanBody_Solid", FecKibanBody_xSize*0.5, FecKibanBody_ySize*0.5, FecKibanBody_zSize*0.5);
  G4double FecKibanHole1_xSize = 42.5*mm;
  G4double FecKibanHole1_ySize = 40.7*mm;
  G4double FecKibanHole1_zSize = FecKiban_zSize;
  G4double FecKibanHole1_xPos = 30.75*mm;
  G4double FecKibanHole1_yPos = 23.15*mm;
  G4double FecKibanHole1_zPos = 0.0*mm;
  G4VSolid* FecKibanHole1_Solid = new G4Box("FecKibanHole1_Solid", FecKibanHole1_xSize*0.5 + margin, FecKibanHole1_ySize*0.5 + margin, FecKibanHole1_zSize*0.5 + margin);
  G4VSolid* FecKiban_Solid = new G4SubtractionSolid("FecKiban", FecKibanBody_Solid, FecKibanHole1_Solid, 0, G4ThreeVector(FecKibanHole1_xPos, FecKibanHole1_yPos, FecKibanHole1_zPos));
  G4LogicalVolume* FecKiban_Logical = new G4LogicalVolume(FecKiban_Solid, fr4, "FecKiban_Logical");


  // ASIC /////////////////////////////
  G4double Asic_xSize = 6.5*mm;
  G4double Asic_ySize = 10.0*mm;
  G4double Asic_zSize = 0.6*mm;
  G4VSolid* Asic_Solid = new G4Box("Asic_Solid", Asic_xSize*0.5, Asic_ySize*0.5, Asic_zSize*0.5);
  G4LogicalVolume* Asic_Logical = new G4LogicalVolume(Asic_Solid, si, "Asic_Logical");


  //Detector Module 
  G4double DetectorModule_zSize = FECHolder_zSize + Ceramic_Spacer_zSize + FecKiban_zSize + Asic_zSize;
  G4double DetectorModuleBody_xSize = 168.0*mm;
  G4double DetectorModuleBody_ySize = 87.0*mm;
  G4double DetectorModuleBody_zSize = DetectorModule_zSize;
  G4VSolid* DetectorModuleBody_Solid = new G4Box("DetectorModuleBody_Solid", DetectorModuleBody_xSize*0.5, DetectorModuleBody_ySize*0.5, DetectorModuleBody_zSize*0.5);
  G4LogicalVolume* DetectorModule_Logical = new G4LogicalVolume(DetectorModuleBody_Solid, air, "DetectorModule_Logical");
  
  //Placement
  G4double FECHolder_xPos = 0.0*mm;
  G4double FECHolder_yPos = 0.0*mm;
  G4double FECHolder_zPos = -DetectorModule_zSize*0.5 + FECHolder_zSize*0.5;
  new G4PVPlacement(0, G4ThreeVector(FECHolder_xPos, FECHolder_yPos, FECHolder_zPos), FECHolder_Logical, "FECHolder", DetectorModule_Logical, false, 0, surfaceCheck);

  
  G4double Ceramic_Spacer_xPos = 0.0*mm;
  G4double Ceramic_Spacer_yPos = 0.0*mm;
  G4double Ceramic_Spacer_zPos = -DetectorModule_zSize*0.5 + FECHolder_zSize + Ceramic_Spacer_zSize*0.5;
  new G4PVPlacement(0, G4ThreeVector(Ceramic_Spacer_xPos, Ceramic_Spacer_yPos, Ceramic_Spacer_zPos), Ceramic_Spacer_Logical, "Ceramic_Spacer", DetectorModule_Logical, false, 0, surfaceCheck);

  
  G4double FecKiban_xPos = 0.0*mm;
  G4double FecKiban_yPos = 0.0*mm;
  G4double FecKiban_zPos = -DetectorModule_zSize*0.5 + FECHolder_zSize + Ceramic_Spacer_zSize + FecKiban_zSize*0.5;
  new G4PVPlacement(0, G4ThreeVector(FecKiban_xPos, FecKiban_yPos, FecKiban_zPos), FecKiban_Logical, "FecKiban", DetectorModule_Logical, false, 0, surfaceCheck);
  
  G4double CdTe_DSD_xPos = FecKibanHole1_xPos; //30.75*mm
  G4double CdTe_DSD_yPos = FecKibanHole1_yPos; //23.15*mm
  G4double CdTe_DSD_zPos = -DetectorModule_zSize*0.5 + FECHolder_zSize + Ceramic_Spacer_zSize + (FecKiban_zSize-CdTe_DSD_zSize) + CdTe_DSD_zSize*0.5;
  new G4PVPlacement(0, G4ThreeVector(CdTe_DSD_xPos, CdTe_DSD_yPos, CdTe_DSD_zPos), CdTe_DSD_Logical, "CdTe_DSD", DetectorModule_Logical, false, 0, surfaceCheck);


  for (int i = 0; i < 4; i++) {
    G4double asic_pitch = 7.9*mm;  
    G4double Asic_xPos = 19.0*mm + asic_pitch*i;
    G4double Asic_yPos = -6.5*mm;
    G4double Asic_zPos =  -DetectorModule_zSize*0.5 + FECHolder_zSize + Ceramic_Spacer_zSize + FecKiban_zSize + Asic_zSize*0.5;
    sprintf(name, "PsideAsic%02d", i);
    new G4PVPlacement(0, G4ThreeVector(Asic_xPos, Asic_yPos, Asic_zPos), Asic_Logical, name, DetectorModule_Logical, false, 0, surfaceCheck);
  }

  for (int i = 0; i < 4; i++) {

    G4double asic_pitch = 7.9*mm;  
    G4double Asic_xPos = 0.8*mm;
    G4double Asic_yPos = 9.8*mm + asic_pitch*i;
    G4double Asic_zPos =  -DetectorModule_zSize*0.5 + FECHolder_zSize + Ceramic_Spacer_zSize + FecKiban_zSize + Asic_zSize*0.5;
    G4ThreeVector pos = G4ThreeVector(Asic_xPos,Asic_yPos,Asic_zPos);
    G4RotationMatrix rot = G4RotationMatrix();
    rot.rotateZ(90.0*deg);
    sprintf(name, "NsideAsic%02d", i);
    new G4PVPlacement(G4Transform3D(rot,pos), Asic_Logical, name, DetectorModule_Logical, false, 0, surfaceCheck);
  }

  
  G4double DetectorModule_xPos = -(CdTe_DSD_xPos+1.25*mm);
  G4double DetectorModule_yPos = -CdTe_DSD_yPos-5.0*mm;
  G4double DetectorModule_zPos = -50.0*mm - ((FECHolder_zSize + Ceramic_Spacer_zSize + FecKiban_zSize) -DetectorModule_zSize*0.5);
  for (int i = 0; i < 8; i++) {    
    G4ThreeVector pos = G4ThreeVector(DetectorModule_xPos,DetectorModule_yPos,DetectorModule_zPos);
    G4RotationMatrix rot = G4RotationMatrix();
    rot.rotateX(-45.0*deg*i);
    pos.rotateX(-45.0*deg*i);
    sprintf(name, "DetectorModule%02d", i);
    new G4PVPlacement(G4Transform3D(rot,pos), DetectorModule_Logical, name, LocalWorld_Logical, false, 0, surfaceCheck);
  }


  // Support materials
  // EndRing
  G4double EndRing_Phimin = 80.0*mm;
  G4double EndRing_Phimax = 200*mm;
  G4double EndRing_zSize = 8.0*mm;
  G4VSolid* EndRing = new G4Tubs("EndRing", EndRing_Phimin*0.5,EndRing_Phimax*0.5,EndRing_zSize*0.5,0.0*deg,360.0*deg);
  G4LogicalVolume* EndRing_Logical = new G4LogicalVolume(EndRing, aluminium, "EndRing_Logical");

  G4double EndRing1_xPos = DetectorModule_xPos+FECHolder_xSize*0.5+EndRing_zSize*0.5;
  G4double EndRing1_yPos = 0.0*mm;
  G4double EndRing1_zPos = 0.0*mm;

  G4double EndRing2_xPos = DetectorModule_xPos-FECHolder_xSize*0.5-EndRing_zSize*0.5;
  G4double EndRing2_yPos = 0.0*mm;
  G4double EndRing2_zPos = 0.0*mm;

  G4RotationMatrix *endring_rot = new G4RotationMatrix();
  endring_rot->rotateY(90.0*deg);
  new G4PVPlacement(endring_rot, G4ThreeVector(EndRing1_xPos,EndRing1_yPos,EndRing1_zPos),EndRing_Logical, "EndRing1", LocalWorld_Logical, false, 0, surfaceCheck);
  new G4PVPlacement(endring_rot, G4ThreeVector(EndRing2_xPos,EndRing2_yPos,EndRing2_zPos),EndRing_Logical, "EndRing2", LocalWorld_Logical, false, 0, surfaceCheck);

  // EndRing Support (Cold Plate)
  G4double ColdPlate1_Phimin = 80.0*mm;
  G4double ColdPlate1_Phimax = 200*mm;
  G4double ColdPlate1_zSize = 10.0*mm;
  G4VSolid* ColdPlate1_Solid = new G4Tubs("ColdPlate1_Solid", ColdPlate1_Phimin*0.5,ColdPlate1_Phimax*0.5,ColdPlate1_zSize*0.5,0.0*deg,360.0*deg);
  G4LogicalVolume* ColdPlate1_Logical = new G4LogicalVolume(ColdPlate1_Solid, copper, "ColdPlate1_Logical");
  
  G4double ColdPlate2org_xSize = 120.0*mm;
  G4double ColdPlate2org_ySize = ColdPlate1_Phimax;
  G4double ColdPlate2org_zSize = ColdPlate1_zSize;
  G4VSolid* ColdPlate2org_Solid = new G4Box("ColdPlate2org_Solid", ColdPlate2org_xSize*0.5, ColdPlate2org_ySize*0.5, ColdPlate2org_zSize*0.5);

  G4double ColdPlate2_Hole_Phimin = 0.0*mm;
  G4double ColdPlate2_Hole_Phimax = 200*mm;
  G4double ColdPlate2_Hole_zSize = 10.0*mm + margin;
  G4VSolid* ColdPlate2_Hole_Solid = new G4Tubs("ColdPlate2_Hole_Solid", ColdPlate2_Hole_Phimin*0.5,ColdPlate2_Hole_Phimax*0.5,ColdPlate2_Hole_zSize*0.5,0.0*deg,360.0*deg);
  G4VSolid* ColdPlate2_Solid = new G4SubtractionSolid("ColdPlate2_Solid",ColdPlate2org_Solid,ColdPlate2_Hole_Solid,0,G4ThreeVector(ColdPlate2org_xSize*0.5,0,0));
  G4LogicalVolume* ColdPlate2_Logical = new G4LogicalVolume(ColdPlate2_Solid, copper, "ColdPlate2_Logical");


  G4double ColdPlate3_xSize = EndRing_zSize*2.0 + FECHolder_xSize;
  G4double ColdPlate3_ySize = ColdPlate1_Phimax;
  G4double ColdPlate3_zSize = 15.0*mm;
  G4VSolid* ColdPlate3_Solid = new G4Box("ColdPlate3_Solid", ColdPlate3_xSize*0.5, ColdPlate3_ySize*0.5, ColdPlate3_zSize*0.5);
  G4LogicalVolume* ColdPlate3_Logical = new G4LogicalVolume(ColdPlate3_Solid, copper, "ColdPlate3_Logical");
  
  G4double ColdPlate1_xPos = DetectorModule_xPos-FECHolder_xSize*0.5-EndRing_zSize - ColdPlate1_zSize*0.5;
  G4double ColdPlate1_yPos = 0.0*mm;
  G4double ColdPlate1_zPos = 0.0*mm;

  G4double ColdPlate2_xPos = DetectorModule_xPos-FECHolder_xSize*0.5-EndRing_zSize - ColdPlate1_zSize*0.5;
  G4double ColdPlate2_yPos = 0.0*mm;
  G4double ColdPlate2_zPos = -ColdPlate2org_xSize*0.5;

  G4double ColdPlate3_xPos = DetectorModule_xPos+FECHolder_xSize*0.5+EndRing_zSize - ColdPlate3_xSize*0.5;
  G4double ColdPlate3_yPos = 0.0*mm;
  G4double ColdPlate3_zPos = -ColdPlate2org_xSize + ColdPlate3_zSize*0.5;

  
  new G4PVPlacement(endring_rot, G4ThreeVector(ColdPlate1_xPos,ColdPlate1_yPos,ColdPlate1_zPos),ColdPlate1_Logical, "ColdPlate1", LocalWorld_Logical, false, 0, surfaceCheck);
  new G4PVPlacement(endring_rot, G4ThreeVector(ColdPlate2_xPos,ColdPlate2_yPos,ColdPlate2_zPos),ColdPlate2_Logical, "ColdPlate2", LocalWorld_Logical, false, 0, surfaceCheck);
  new G4PVPlacement(0, G4ThreeVector(ColdPlate3_xPos,ColdPlate3_yPos,ColdPlate3_zPos),ColdPlate3_Logical, "ColdPlate3", LocalWorld_Logical, false, 0, surfaceCheck);

  // Cold Plate Support (Delrin) & Base Frame

  // delrin support
  G4double ThermalCut_Phimin = 10.0*mm;
  G4double ThermalCut_Phimax = 20.0*mm;
  G4double ThermalCut_zSize = 20.0*mm;
  G4VSolid* ThermalCut = new G4Tubs("ThermalCut", ThermalCut_Phimin*0.5,ThermalCut_Phimax*0.5,ThermalCut_zSize*0.5,0.0*deg,360.0*deg);
  G4LogicalVolume* ThermalCut_Logical = new G4LogicalVolume(ThermalCut, delrin, "ThermalCut_Logical");

  for (int i = 0; i < 12; i++) {

    G4double offset_x = ColdPlate3_xPos-ColdPlate3_xSize*0.5 + ThermalCut_Phimax*0.5;
    G4double offset_y = ColdPlate3_yPos-ColdPlate3_ySize*0.5 +ThermalCut_Phimax*0.5;
    G4double pitch_x = (ColdPlate3_xSize-ThermalCut_Phimax)/3.;
    G4double pitch_y = (ColdPlate3_ySize-ThermalCut_Phimax)/3.;

    G4double ThermalCut_xPos;
    G4double ThermalCut_yPos;
    G4double ThermalCut_zPos=ColdPlate3_zPos-ColdPlate3_zSize*0.5-ThermalCut_zSize*0.5;
    
    if(i<=3){
      ThermalCut_xPos = offset_x+pitch_x*((G4double)i);
      ThermalCut_yPos = offset_y;
      sprintf(name, "ThermalCut%02d", i);
      new G4PVPlacement(0,G4ThreeVector(ThermalCut_xPos,ThermalCut_yPos,ThermalCut_zPos), ThermalCut_Logical, name, LocalWorld_Logical, false, 0, surfaceCheck);
    }else if(i<=6){
      ThermalCut_xPos = offset_x+pitch_x*3.;
      ThermalCut_yPos = offset_y+pitch_y*((G4double)(i-3));
      sprintf(name, "ThermalCut%02d", i);
      new G4PVPlacement(0,G4ThreeVector(ThermalCut_xPos,ThermalCut_yPos,ThermalCut_zPos), ThermalCut_Logical, name, LocalWorld_Logical, false, 0, surfaceCheck);
    }else if(i<=9){
      ThermalCut_xPos = offset_x+pitch_x*3.-pitch_x*((G4double)(i-6));
      ThermalCut_yPos = offset_y+pitch_y*3.;
      sprintf(name, "ThermalCut%02d", i);
      new G4PVPlacement(0,G4ThreeVector(ThermalCut_xPos,ThermalCut_yPos,ThermalCut_zPos), ThermalCut_Logical, name, LocalWorld_Logical, false, 0, surfaceCheck);
    }else if(i<=11){
      ThermalCut_xPos = offset_x+pitch_x*3.-pitch_x*3.;
      ThermalCut_yPos = offset_y+pitch_y*3.-pitch_y*((G4double)(i-9));
      sprintf(name, "ThermalCut%02d", i);
      new G4PVPlacement(0,G4ThreeVector(ThermalCut_xPos,ThermalCut_yPos,ThermalCut_zPos), ThermalCut_Logical, name, LocalWorld_Logical, false, 0, surfaceCheck);
    }
  }  

  // base Frame
  G4double BaseFrame_xSize = EndRing_zSize*2.0 + FECHolder_xSize + 100.0*mm;
  G4double BaseFrame_ySize = ColdPlate1_Phimax;
  G4double BaseFrame_zSize = 15.0*mm;
  G4VSolid* BaseFrame_Solid = new G4Box("BaseFrame_Solid", BaseFrame_xSize*0.5, BaseFrame_ySize*0.5, BaseFrame_zSize*0.5);
  G4LogicalVolume* BaseFrame_Logical = new G4LogicalVolume(BaseFrame_Solid, aluminium, "BaseFrame_Logical");

  G4double BaseFrame_xPos = DetectorModule_xPos+FECHolder_xSize*0.5+EndRing_zSize - BaseFrame_xSize*0.5;
  G4double BaseFrame_yPos = 0.0*mm;
  G4double BaseFrame_zPos = -ColdPlate2org_xSize - ThermalCut_zSize - BaseFrame_zSize*0.5;
  new G4PVPlacement(0, G4ThreeVector(BaseFrame_xPos,BaseFrame_yPos,BaseFrame_zPos),BaseFrame_Logical, "BaseFrame", LocalWorld_Logical, false, 0, surfaceCheck);


  // Flange & Housing
  G4double Housing_body_Phimin = 320.0*mm;
  G4double Housing_body_Phimax = 330.0*mm;
  G4double Housing_body_zSize = 320.0*mm;
  G4VSolid* Housing_body_Solid = new G4Tubs("Housing_body_Solid", Housing_body_Phimin*0.5,Housing_body_Phimax*0.5,Housing_body_zSize*0.5,0.0*deg,360.0*deg);
  G4LogicalVolume* Housing_body_Logical = new G4LogicalVolume(Housing_body_Solid, aluminium, "Housing_body_Logical");
  
  G4double Flange_org_Phimin = 0.0*mm;
  G4double Flange_org_Phimax = 360.0*mm;
  G4double Flange_org_zSize = 20.0*mm;
  G4VSolid* Flange_org_Solid = new G4Tubs("Flange_org_Solid", Flange_org_Phimin*0.5,Flange_org_Phimax*0.5,Flange_org_zSize*0.5,0.0*deg,360.0*deg);

  G4double Flange_Hole_Phimin = 0.0*mm;
  G4double Flange_Hole_Phimax = 80.0*mm;
  G4double Flange_Hole_zSize = Flange_org_zSize + margin;
  G4VSolid* Flange_Hole_Solid = new G4Tubs("Flange_Hole_Solid", Flange_Hole_Phimin*0.5,Flange_Hole_Phimax*0.5,Flange_Hole_zSize*0.5,0.0*deg,360.0*deg);


  G4double Flange_Hole_xPos = -50.0*mm;
  G4double Flange_Hole_yPos = 0.0*mm;
  G4double Flange_Hole_zPos = 0.0*mm;
  G4VSolid* Flange_Solid = new G4SubtractionSolid("Flange_Solid",Flange_org_Solid,Flange_Hole_Solid,0,G4ThreeVector(Flange_Hole_xPos,Flange_Hole_yPos, Flange_Hole_zPos));
  G4LogicalVolume* Flange_Logical = new G4LogicalVolume(Flange_Solid, aluminium, "Flange_Logical");


  G4double Flange1_xPos = BaseFrame_xPos - BaseFrame_xSize*0.5 - Flange_org_zSize*0.5 ;
  G4double Flange1_yPos = 0.0*mm;
  G4double Flange1_zPos = Flange_Hole_xPos;

  G4double Flange2_xPos = Flange1_xPos + Flange_org_zSize*0.5 + Housing_body_zSize + Flange_org_zSize*0.5;
  G4double Flange2_yPos = 0.0*mm;
  G4double Flange2_zPos = Flange_Hole_xPos;

  G4double Housing_body_xPos = Flange1_xPos + Flange_org_zSize*0.5 + Housing_body_zSize*0.5;
  G4double Housing_body_yPos = 0.0*mm;
  G4double Housing_body_zPos = Flange_Hole_xPos;
  
  G4RotationMatrix *flange_rot = new G4RotationMatrix();
  flange_rot->rotateY(-90.0*deg);
  new G4PVPlacement(flange_rot, G4ThreeVector(Flange1_xPos,Flange1_yPos,Flange1_zPos),Flange_Logical, "Flange1", LocalWorld_Logical, false, 0, surfaceCheck);
  new G4PVPlacement(flange_rot, G4ThreeVector(Flange2_xPos,Flange2_yPos,Flange2_zPos),Flange_Logical, "Flange2", LocalWorld_Logical, false, 0, surfaceCheck);
  new G4PVPlacement(flange_rot, G4ThreeVector(Housing_body_xPos,Housing_body_yPos,Housing_body_zPos),Housing_body_Logical, "Housing_body", LocalWorld_Logical, false, 0, surfaceCheck);

  // Pipe
  // Be Pipe
  G4double BePipe_Phimin = 78.0*mm;
  G4double BePipe_Phimax = 80.0*mm;
  G4double BePipe_zSize = 50.0*mm;
  G4VSolid* BePipe = new G4Tubs("BePipe", BePipe_Phimin*0.5,BePipe_Phimax*0.5,BePipe_zSize*0.5,0.0*deg,360.0*deg);
  G4LogicalVolume* BePipe_Logical = new G4LogicalVolume(BePipe, beryllium, "BePipe_Logical");

  G4double BePipe_xPos = 0.0*mm;
  G4double BePipe_yPos = 0.0*mm;
  G4double BePipe_zPos = 0.0*mm;
  new G4PVPlacement(endring_rot, G4ThreeVector(BePipe_xPos,BePipe_yPos,BePipe_zPos),BePipe_Logical, "BePipe", LocalWorld_Logical, false, 0, surfaceCheck);

  // Al pipes
  G4double AlPipe1_Phimin = 70.0*mm;
  G4double AlPipe1_Phimax = 80.0*mm;
  G4double AlPipe1_zSize = (-BePipe_zSize*0.5-(Flange1_xPos-Flange_org_zSize*0.5));
  G4VSolid* AlPipe1 = new G4Tubs("AlPipe1", AlPipe1_Phimin*0.5,AlPipe1_Phimax*0.5,AlPipe1_zSize*0.5,0.0*deg,360.0*deg);
  G4LogicalVolume* AlPipe1_Logical = new G4LogicalVolume(AlPipe1, aluminium, "AlPipe1_Logical");

  G4double AlPipe1_xPos = (Flange1_xPos-Flange_org_zSize*0.5)+AlPipe1_zSize*0.5;
  G4double AlPipe1_yPos = 0.0*mm;
  G4double AlPipe1_zPos = 0.0*mm;
  new G4PVPlacement(endring_rot, G4ThreeVector(AlPipe1_xPos,AlPipe1_yPos,AlPipe1_zPos),AlPipe1_Logical, "AlPipe1", LocalWorld_Logical, false, 0, surfaceCheck);

  
  G4double AlPipe2_Phimin = 70.0*mm;
  G4double AlPipe2_Phimax = 80.0*mm;
  G4double AlPipe2_zSize = Flange2_xPos+Flange_org_zSize*0.5 - BePipe_zSize*0.5;
  G4VSolid* AlPipe2 = new G4Tubs("AlPipe2", AlPipe2_Phimin*0.5,AlPipe2_Phimax*0.5,AlPipe2_zSize*0.5,0.0*deg,360.0*deg);
  G4LogicalVolume* AlPipe2_Logical = new G4LogicalVolume(AlPipe2, aluminium, "AlPipe2_Logical");

  G4double AlPipe2_xPos = (Flange2_xPos+Flange_org_zSize*0.5)-AlPipe2_zSize*0.5;
  G4double AlPipe2_yPos = 0.0*mm;
  G4double AlPipe2_zPos = 0.0*mm;
  new G4PVPlacement(endring_rot, G4ThreeVector(AlPipe2_xPos,AlPipe2_yPos,AlPipe2_zPos),AlPipe2_Logical, "AlPipe2", LocalWorld_Logical, false, 0, surfaceCheck);


  // small flange

  G4double SmallFlange_Phimin = 70.0*mm;
  G4double SmallFlange_Phimax = 120.0*mm;
  G4double SmallFlange_zSize = 10.0*mm;
  G4VSolid* SmallFlange = new G4Tubs("SmallFlange", SmallFlange_Phimin*0.5,SmallFlange_Phimax*0.5,SmallFlange_zSize*0.5,0.0*deg,360.0*deg);
  G4LogicalVolume* SmallFlange_Logical = new G4LogicalVolume(SmallFlange, aluminium, "SmallFlange_Logical");

  G4double SmallFlange1_xPos = (Flange1_xPos-Flange_org_zSize*0.5)-SmallFlange_zSize*0.5;
  G4double SmallFlange1_yPos = 0.0*mm;
  G4double SmallFlange1_zPos = 0.0*mm;
  new G4PVPlacement(endring_rot, G4ThreeVector(SmallFlange1_xPos,SmallFlange1_yPos,SmallFlange1_zPos),SmallFlange_Logical, "SmallFlange1", LocalWorld_Logical, false, 0, surfaceCheck);

  G4double SmallFlange2_xPos = (Flange2_xPos+Flange_org_zSize*0.5)+SmallFlange_zSize*0.5;
  G4double SmallFlange2_yPos = 0.0*mm;
  G4double SmallFlange2_zPos = 0.0*mm;
  new G4PVPlacement(endring_rot, G4ThreeVector(SmallFlange2_xPos,SmallFlange2_yPos,SmallFlange2_zPos),SmallFlange_Logical, "SmallFlange2", LocalWorld_Logical, false, 0, surfaceCheck);
  
  // Tadano Dodai
  G4double Dodai_Partsorg_xSize = Housing_body_Phimax*0.5 + 30.0*mm;
  G4double Dodai_Partsorg_ySize = Housing_body_Phimax;
  G4double Dodai_Partsorg_zSize = 20.0*mm;
  G4VSolid* Dodai_Partsorg_Solid = new G4Box("Dodai_Partsorg_Solid", Dodai_Partsorg_xSize*0.5, Dodai_Partsorg_ySize*0.5, Dodai_Partsorg_zSize*0.5);

  G4double Dodai_Parts_Hole_Phimin = 0.0*mm;
  G4double Dodai_Parts_Hole_Phimax = Housing_body_Phimax;
  G4double Dodai_Parts_Hole_zSize = 20.0*mm + margin;
  G4VSolid* Dodai_Parts_Hole_Solid = new G4Tubs("Dodai_Parts_Hole_Solid", Dodai_Parts_Hole_Phimin*0.5,Dodai_Parts_Hole_Phimax*0.5,Dodai_Parts_Hole_zSize*0.5,0.0*deg,360.0*deg);
  G4VSolid* Dodai_Parts_Solid = new G4SubtractionSolid("Dodai_Parts_Solid",Dodai_Partsorg_Solid,Dodai_Parts_Hole_Solid,0,G4ThreeVector(Dodai_Partsorg_xSize*0.5,0,0));
  G4LogicalVolume* Dodai_Parts_Logical = new G4LogicalVolume(Dodai_Parts_Solid, aluminium, "Dodai_Parts_Logical");

  G4double Dodai_Parts1_xPos = Housing_body_xPos - Housing_body_zSize*0.5 + Dodai_Partsorg_zSize*0.5 ;
  G4double Dodai_Parts1_yPos = 0.0*mm;
  G4double Dodai_Parts1_zPos = Flange_Hole_xPos - Dodai_Partsorg_xSize*0.5;

  G4double Dodai_Parts2_xPos = Housing_body_xPos + Housing_body_zSize*0.5 - Dodai_Partsorg_zSize*0.5 ;
  G4double Dodai_Parts2_yPos = 0.0*mm;
  G4double Dodai_Parts2_zPos = Flange_Hole_xPos - Dodai_Partsorg_xSize*0.5;

  
  new G4PVPlacement(endring_rot, G4ThreeVector(Dodai_Parts1_xPos,Dodai_Parts1_yPos,Dodai_Parts1_zPos),Dodai_Parts_Logical, "Dodai_Parts1", LocalWorld_Logical, false, 0, surfaceCheck);
  new G4PVPlacement(endring_rot, G4ThreeVector(Dodai_Parts2_xPos,Dodai_Parts2_yPos,Dodai_Parts2_zPos),Dodai_Parts_Logical, "Dodai_Parts2", LocalWorld_Logical, false, 0, surfaceCheck);

  // Tadano Ita
  G4double Ita_xSize = 500.0*mm;
  G4double Ita_ySize = 500.0*mm;
  G4double Ita_zSize = 15.0*mm;
  G4VSolid* Ita_Solid = new G4Box("Ita_Solid", Ita_xSize*0.5, Ita_ySize*0.5, Ita_zSize*0.5);
  G4LogicalVolume* Ita_Logical = new G4LogicalVolume(Ita_Solid, aluminium, "Ita_Logical");

  G4double Ita_xPos = Housing_body_xPos;
  G4double Ita_yPos = 0.0*mm;
  G4double Ita_zPos = Dodai_Parts2_zPos  - Dodai_Partsorg_xSize*0.5 - Ita_zSize*0.5;
  new G4PVPlacement(0, G4ThreeVector(Ita_xPos,Ita_yPos,Ita_zPos),Ita_Logical, "Ita", LocalWorld_Logical, false, 0, surfaceCheck);

  
  //VisAttributes

  G4VisAttributes* fecholder_Attributes = new G4VisAttributes(); 
  fecholder_Attributes->SetColor(1.0,1.0,1.0,0.2); //white
  fecholder_Attributes->SetForceSolid(true);
  FECHolder_Logical->SetVisAttributes(fecholder_Attributes);

  G4VisAttributes* ceramic_spacer_Attributes = new G4VisAttributes();
  ceramic_spacer_Attributes->SetColor(0.0,1.0,1.0,0.2); //cyan
  ceramic_spacer_Attributes->SetForceSolid(true);
  Ceramic_Spacer_Logical->SetVisAttributes(ceramic_spacer_Attributes);

  G4VisAttributes* feckiban_Attributes = new G4VisAttributes();
  feckiban_Attributes->SetColor(0.0,1.0,0.0,0.5); //green
  feckiban_Attributes->SetForceSolid(true);
  FecKiban_Logical->SetVisAttributes(feckiban_Attributes);

  G4VisAttributes* asic_Attributes = new G4VisAttributes();
  asic_Attributes->SetColor(1.0,1.0,0.0,0.5); //yellow
  asic_Attributes->SetForceSolid(true);
  Asic_Logical->SetVisAttributes(asic_Attributes);

  G4VisAttributes* cdtestrip_Attributes = new G4VisAttributes(G4Colour::Red());
  cdtestrip_Attributes->SetForceSolid(true);
  CdTe_DSD_Logical->SetVisAttributes(cdtestrip_Attributes);


  G4VisAttributes* DetectorModule_Attributes = new G4VisAttributes(); 
  DetectorModule_Attributes->SetColor(1.0,1.0,1.0,0.5); //white
  //  DetectorModule_Attributes->SetForceSolid(false);
  DetectorModule_Attributes->SetForceWireframe(true);
  DetectorModule_Logical->SetVisAttributes(DetectorModule_Attributes);

  
  G4VisAttributes* endring_Attributes = new G4VisAttributes(); 
  endring_Attributes->SetColor(1.0,1.0,1.0,0.2); //white
  //  endring_Attributes->SetForceSolid(true);
  endring_Attributes->SetForceWireframe(true);
  EndRing_Logical->SetVisAttributes(endring_Attributes);


  G4VisAttributes* part1_Attributes = new G4VisAttributes(); 
  part1_Attributes->SetColor(0.7,0.4,0.1,0.8); 
  part1_Attributes->SetForceSolid(true);
  //part1_Attributes->SetForceWireframe(true);
  ColdPlate1_Logical->SetVisAttributes(part1_Attributes);

  G4VisAttributes* part2_Attributes = new G4VisAttributes(); 
  part2_Attributes->SetColor(0.7,0.4,0.1,1.0); 
  part2_Attributes->SetForceSolid(true);
  // part2_Attributes->SetForceWireframe(true);
  ColdPlate2_Logical->SetVisAttributes(part2_Attributes);
  ColdPlate3_Logical->SetVisAttributes(part2_Attributes);


  G4VisAttributes* ThermalCut_Attributes = new G4VisAttributes(); 
  ThermalCut_Attributes->SetColor(1.0,1.0,1.0,0.5); //white
  ThermalCut_Attributes->SetForceSolid(true);
  //ThermalCut_Attributes->SetForceWireframe(true);
  ThermalCut_Logical->SetVisAttributes(ThermalCut_Attributes);


  G4VisAttributes* BaseFrame_Attributes = new G4VisAttributes(); 
  BaseFrame_Attributes->SetColor(1.0,1.0,1.0,0.5); //white
  BaseFrame_Attributes->SetForceSolid(true);
  //BaseFrame_Attributes->SetForceWireframe(true);
  BaseFrame_Logical->SetVisAttributes(BaseFrame_Attributes);


  G4VisAttributes* Flange_Attributes = new G4VisAttributes(); 
  Flange_Attributes->SetColor(1.0,1.0,1.0,0.2); //white
  Flange_Attributes->SetForceSolid(true);
  //Flange_Attributes->SetForceWireframe(true);
  Flange_Logical->SetVisAttributes(Flange_Attributes);


  G4VisAttributes* Housing_body_Attributes = new G4VisAttributes(); 
  Housing_body_Attributes->SetColor(1.0,1.0,1.0,0.2); //white
  Housing_body_Attributes->SetForceSolid(true);
  //Housing_body_Attributes->SetForceWireframe(true);
  Housing_body_Logical->SetVisAttributes(Housing_body_Attributes);


  G4VisAttributes* dodai_Attributes = new G4VisAttributes(); 
  dodai_Attributes->SetColor(1.0,1.0,1.0,0.2); //white
  //  dodai_Attributes->SetForceSolid(true);
  dodai_Attributes->SetForceWireframe(true);
  Dodai_Parts_Logical->SetVisAttributes(dodai_Attributes);
  Ita_Logical->SetVisAttributes(dodai_Attributes);


  G4VisAttributes* LocalWorld_Attributes = new G4VisAttributes(); 
  LocalWorld_Attributes->SetColor(1.0,1.0,1.0,0.0); //white
  LocalWorld_Attributes->SetForceSolid(true);
  //LocalWorld_Attributes->SetForceWireframe(true);
  LocalWorld_Logical->SetVisAttributes(LocalWorld_Attributes);

  G4VisAttributes* bepipe_Attributes = new G4VisAttributes(); 
  bepipe_Attributes->SetColor(1.0,1.0,1.0,0.5); 
  bepipe_Attributes->SetForceSolid(true);
  //bepipe_Attributes->SetForceWireframe(true);
  BePipe_Logical->SetVisAttributes(bepipe_Attributes);


  G4VisAttributes* alpipe_Attributes = new G4VisAttributes(); 
  alpipe_Attributes->SetColor(1.0,1.0,1.0,0.5); //white
  alpipe_Attributes->SetForceSolid(true);
  //alpipe_Attributes->SetForceWireframe(true);
  AlPipe1_Logical->SetVisAttributes(alpipe_Attributes);
  AlPipe2_Logical->SetVisAttributes(alpipe_Attributes);
  SmallFlange_Logical->SetVisAttributes(alpipe_Attributes);




  //======= Collimator  ======
  GeometryCollimator* Collimator_Geometry;
  if(detname == "Type1"){
    Collimator_Geometry = new GeometryCollimatorType1();
  }else{
    Collimator_Geometry = new GeometryCollimator();
  }

  Collimator_Geometry->Construct(LocalWorld_Logical);

  return LocalWorld_Logical;
}
