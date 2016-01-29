#include <sstream>

#include "GeometryCdTeStripCamera.hh"
#include "AHG4MaterialManager.hh"

#include "GeometryCollimator.hh"
#include "GeometryCollimatorType1.hh"
#include "GeometryCollimatorType2.hh"
#include "GeometryCollimator_MuonType1.hh"
#include "GeometryCollimator_MuonType2.hh"
#include "GeometryCollimator_MuonType3.hh"
#include "GeometryCollimator_MuonType4.hh"

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
#include "G4RotationMatrix.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"

using namespace cdtestripcamerageometry;

G4LogicalVolume* GeometryCdTeStripCamera::Construct(std::string detname) {

  const bool surfaceCheck = false;
  G4double margin = 0.1*mm;  

  AHG4MaterialManager* mmanager = AHG4MaterialManager::GetAHG4MaterialManager();
  AHG4Material* air = mmanager->instantiate("Vacuum");
  std::string matname;
  AHG4MaterialProperty* p;

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

  
  // Local World //////////////////////
  G4double LocalWorld_xSize = 500.0*mm;
  G4double LocalWorld_ySize = 500.0*mm;
  G4double LocalWorld_zSize = 500.0*mm;
  G4VSolid* LocalWorld_Solid = new G4Box("LocalWorld_Solid", LocalWorld_xSize*0.5, LocalWorld_ySize*0.5, LocalWorld_zSize*0.5);
  G4LogicalVolume* LocalWorld_Logical = new G4LogicalVolume(LocalWorld_Solid, air, "LocalWorld_Logical");


 //======= CdTe-Double-sided Strip Ditector  ======
  G4double CdTe_DSD_xSize = 34.0*mm;
  G4double CdTe_DSD_ySize = 34.0*mm;
  G4double CdTe_DSD_zSize = 0.75*mm;
  G4VSolid* CdTe_DSD = new G4Box("CdTe_DSD", CdTe_DSD_xSize*0.5, CdTe_DSD_ySize*0.5, CdTe_DSD_zSize*0.5);
  G4LogicalVolume* CdTe_DSD_Logical = new G4LogicalVolume(CdTe_DSD, cdte, "CdTe_DSD_Logical");
  
  G4double CdTe_DSD_xPos = 0.0*mm;
  G4double CdTe_DSD_yPos = 0.0*mm;
  G4double CdTe_DSD_zPos = 0.0*mm;
  new G4PVPlacement(0, G4ThreeVector(CdTe_DSD_xPos, CdTe_DSD_yPos, CdTe_DSD_zPos), CdTe_DSD_Logical, "CdTe_DSD", LocalWorld_Logical, false, 0, surfaceCheck);

  G4VisAttributes* cdtestrip_Attributes = new G4VisAttributes(G4Colour::Blue());
  cdtestrip_Attributes->SetForceSolid(surfaceCheck);
  CdTe_DSD_Logical->SetVisAttributes(cdtestrip_Attributes);
  
  //======= Collimator  ======

  GeometryCollimator* Collimator_Geometry;
  if(detname == "Type1"){
    Collimator_Geometry = new GeometryCollimatorType1();
  }else if(detname == "Type2"){
    Collimator_Geometry = new GeometryCollimatorType2();
  }else if(detname == "MuonType1"){
    Collimator_Geometry = new GeometryCollimator_MuonType1();
  }else if(detname == "MuonType2"){
    Collimator_Geometry = new GeometryCollimator_MuonType2();
  }else if(detname == "MuonType3"){
    Collimator_Geometry = new GeometryCollimator_MuonType3();
  }else if(detname == "MuonType4"){
    Collimator_Geometry = new GeometryCollimator_MuonType4();
  }else{
    Collimator_Geometry = new GeometryCollimator();
  }

  G4ThreeVector Collimator_postion = G4ThreeVector(0,0,0);  
  G4LogicalVolume* Collimator_Logical = Collimator_Geometry->Construct(&Collimator_postion);
  new G4PVPlacement(0, Collimator_postion, Collimator_Logical, "Collimator", LocalWorld_Logical, false, 0, surfaceCheck);

  return LocalWorld_Logical;
}
