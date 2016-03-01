#include "GantryMainGeometryRealWorld.hh"

#include "GeometryGantry.hh"

#include "AHG4MaterialManager.hh"
#include "AHG4MaterialProperty.hh"
//#include "AHG4MaterialSampler.hh"

#include "globals.hh"
#include "G4Element.hh"
#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"
#include "G4LogicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4PVPlacement.hh"
#include "G4PVParameterised.hh"
#include "G4SDManager.hh"
#include "G4UserLimits.hh"

#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;
using namespace oistgantry;

GantryMainGeometryRealWorld::GantryMainGeometryRealWorld(std::string detname)
  : constructed(false) , World_Logical(0) , World_Physical(0) , m_CollimatorName(detname){
}

G4VPhysicalVolume* GantryMainGeometryRealWorld::Construct() {
  Initialize();
  return World_Physical;
}

void GantryMainGeometryRealWorld::Initialize() {
  if (!constructed) { 
      constructed = true;
      DefineMaterials();
      SetupGeometry();
    }
}

void GantryMainGeometryRealWorld::SetupGeometry() {

  AHG4MaterialManager* mmanager = AHG4MaterialManager::GetAHG4MaterialManager();
  AHG4Material* air = mmanager->instantiate("Vacuum");

  // World ///////////////////////
  G4double World_xSize = 1500.0*mm;
  G4double World_ySize = 1500.0*mm;
  G4double World_zSize = 1500.0*mm;
  G4Box* World_Solid = new G4Box("World_Solid", World_xSize*0.5, World_ySize*0.5, World_zSize*0.5);
  World_Logical = new G4LogicalVolume(World_Solid, air, "World_Logical"); 
  World_Physical = new G4PVPlacement(0, G4ThreeVector(), World_Logical, "World_Physical", 0, false, 0);


  // Gantry
  G4double Gantry_xPos = 0.0*mm;
  G4double Gantry_yPos = 0.0*mm;
  G4double Gantry_zPos = 0.0*mm;

  GeometryGantry* Gantry_Geometry = new GeometryGantry();
  G4LogicalVolume* Gantry_Logical = Gantry_Geometry->Construct(m_CollimatorName);
  new G4PVPlacement(0, G4ThreeVector(Gantry_xPos,Gantry_yPos,Gantry_zPos), Gantry_Logical, "Gantry", World_Logical, false, 0);


  
}
