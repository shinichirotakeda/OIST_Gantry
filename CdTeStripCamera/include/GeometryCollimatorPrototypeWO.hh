#ifndef GeometryCollimatorPrototypeWO_HH
#define GeometryCollimatorPrototypeWO_HH

#include "globals.hh"
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"
#include "GeometryCollimator.hh"

class G4LogicalVolume;
class G4VPhysicalVolume;

namespace cdtestripcamerageometry {

  class GeometryCollimatorPrototypeWO : public GeometryCollimator{
    
  public:
    GeometryCollimatorPrototypeWO() {};
    virtual ~GeometryCollimatorPrototypeWO() {};
    
    G4LogicalVolume* Construct(G4ThreeVector *pos);
    
  private:
    
    void DefineMaterials() {};
    void SetupGeometry() {};
    
  };
  
}

#endif

