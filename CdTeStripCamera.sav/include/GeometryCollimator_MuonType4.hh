#ifndef GeometryCollimator_MuonType4_HH
#define GeometryCollimator_MuonType4_HH

#include "globals.hh"
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"
#include "GeometryCollimator.hh"

class G4LogicalVolume;
class G4VPhysicalVolume;

namespace cdtestripcamerageometry {

  class GeometryCollimator_MuonType4 : public GeometryCollimator{
    
  public:
    GeometryCollimator_MuonType4() {};
    virtual ~GeometryCollimator_MuonType4() {};
    
    G4LogicalVolume* Construct(G4ThreeVector *pos);
    
  private:
    
    void DefineMaterials() {};
    void SetupGeometry() {};
    
  };
  
}

#endif

