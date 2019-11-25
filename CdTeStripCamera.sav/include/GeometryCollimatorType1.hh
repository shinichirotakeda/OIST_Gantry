#ifndef GeometryCollimatorType1_HH
#define GeometryCollimatorType1_HH

#include "globals.hh"
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"
#include "GeometryCollimator.hh"

class G4LogicalVolume;
class G4VPhysicalVolume;

namespace cdtestripcamerageometry {

  class GeometryCollimatorType1 : public GeometryCollimator{
    
  public:
    GeometryCollimatorType1() {};
    virtual ~GeometryCollimatorType1() {};
    
    G4LogicalVolume* Construct(G4ThreeVector *pos);
    
  private:
    
    void DefineMaterials() {};
    void SetupGeometry() {};
    
  };
  
}

#endif

