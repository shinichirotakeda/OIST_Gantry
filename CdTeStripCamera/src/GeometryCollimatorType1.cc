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
#include "G4SubtractionSolid.hh"
#include "G4RotationMatrix.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"

using namespace cdtestripcamerageometry;

G4LogicalVolume* GeometryCollimatorType1::Construct(G4ThreeVector *pos) {

  const bool surfaceCheck = false;
  G4double margin = 0.1*mm; 

  AHG4MaterialManager* mmanager = AHG4MaterialManager::GetAHG4MaterialManager();
  AHG4Material* air = mmanager->instantiate("Vacuum");	
 
  // Collimator //////////////////////
  G4double pRmin = 0.0*mm;
  G4double pRmax = 5.0*mm;
  G4double pDz = 10.0*mm;
  G4double pSphi = 0.*degree;
  G4double pDphi = 360.*degree;
  G4VSolid* Collimator_Solid = new G4Tubs("Collimator_Solid", pRmin,pRmax,pDz*0.5,pSphi,pDphi);
  G4LogicalVolume* Collimator_Logical = new G4LogicalVolume(Collimator_Solid, air, "Collimator_Logical");

  G4VisAttributes* Collimator_Attributes = new G4VisAttributes(G4Colour::Red());
  Collimator_Attributes->SetForceSolid(surfaceCheck);
  Collimator_Logical->SetVisAttributes(Collimator_Attributes);
  
  pos->setX(0.);
  pos->setY(0.);
  pos->setZ(42.5*mm);
  return Collimator_Logical;
 
}
