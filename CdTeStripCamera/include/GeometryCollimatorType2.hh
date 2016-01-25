#ifndef GeometryCollimatorType2_HH
#define GeometryCollimatorType2_HH

#include "globals.hh"
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"
#include "GeometryCollimator.hh"

class G4LogicalVolume;
class G4VPhysicalVolume;

namespace cdtestripcamerageometry {

  class GeometryCollimatorType2 : public GeometryCollimator{
    
  public:
    GeometryCollimatorType2() {};
    virtual ~GeometryCollimatorType2() {};
    
    G4LogicalVolume* Construct(G4ThreeVector *pos);
    
  private:
    
    void DefineMaterials() {};
    void SetupGeometry() {};
    
  };
  
}

#endif

