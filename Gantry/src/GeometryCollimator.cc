#include <sstream>

#include "GeometryCollimator.hh"

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

using namespace oistgantry;

G4LogicalVolume* GeometryCollimator::Construct(G4ThreeVector *pos) {

  const bool surfaceCheck = false;
  G4double margin = 0.1*mm; 

  AHG4MaterialManager* mmanager = AHG4MaterialManager::GetAHG4MaterialManager();
  AHG4Material* air = mmanager->instantiate("Vacuum");	
 
  // Null Collimator //////////////////////
  G4double Collimator_xSize = 10.0*mm;
  G4double Collimator_ySize = 10.0*mm;
  G4double Collimator_zSize = 10.0*mm;
  G4VSolid* Collimator_Solid = new G4Box("Collimator_Solid", Collimator_xSize*0.5, Collimator_ySize*0.5, Collimator_zSize*0.5);
  G4LogicalVolume* Collimator_Logical = new G4LogicalVolume(Collimator_Solid, air, "Collimator_Logical");

  G4VisAttributes* Collimator_Attributes = new G4VisAttributes(0.0,G4Colour::Red());
  Collimator_Attributes->SetForceSolid(surfaceCheck);
  Collimator_Logical->SetVisAttributes(Collimator_Attributes);
  
  pos->setX(0.);
  pos->setY(0.);
  pos->setZ(0.0*mm);
  return Collimator_Logical;
 
}
