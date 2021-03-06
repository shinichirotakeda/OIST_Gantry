#ifndef GeometryCollimator_HH
#define GeometryCollimator_HH

#include "globals.hh"
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"
class G4LogicalVolume;
class G4VPhysicalVolume;

namespace oistgantry {

class GeometryCollimator {

public:
  GeometryCollimator() {};
  virtual ~GeometryCollimator() {};
  
  virtual G4LogicalVolume* Construct(G4LogicalVolume* localworld);

private:

  void DefineMaterials() {};
  void SetupGeometry() {};
  
};

}

#endif

