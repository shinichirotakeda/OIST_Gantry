#ifndef GeometryCollimatorType1PT_HH
#define GeometryCollimatorType1PT_HH

#include "globals.hh"
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"
#include "GeometryCollimator.hh"

class G4LogicalVolume;
class G4VPhysicalVolume;

namespace oistgantry {

  class GeometryCollimatorType1PT : public GeometryCollimator{
    
  public:
    GeometryCollimatorType1PT() {};
    virtual ~GeometryCollimatorType1PT() {};
    
    G4LogicalVolume* Construct(G4LogicalVolume* localworld);
    
  private:
    
    void DefineMaterials() {};
    void SetupGeometry() {};
    
  };
  
}

#endif

