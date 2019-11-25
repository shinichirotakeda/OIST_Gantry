#ifndef GeometryCollimator_MuonType2_HH
#define GeometryCollimator_MuonType2_HH

#include "globals.hh"
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"
#include "GeometryCollimator.hh"

class G4LogicalVolume;
class G4VPhysicalVolume;

namespace cdtestripcamerageometry {

  class GeometryCollimator_MuonType2 : public GeometryCollimator{
    
  public:
    GeometryCollimator_MuonType2() {};
    virtual ~GeometryCollimator_MuonType2() {};
    
    G4LogicalVolume* Construct(G4ThreeVector *pos);
    
  private:
    
    void DefineMaterials() {};
    void SetupGeometry() {};
    
  };
  
}

#endif

