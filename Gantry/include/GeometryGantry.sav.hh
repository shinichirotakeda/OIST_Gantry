#ifndef GeometryGantry_HH
#define GeometryGantry_HH

#include "globals.hh"

class G4LogicalVolume;
class G4VPhysicalVolume;

namespace oistgantry  {

class GeometryGantry {

public:
  GeometryGantry() {};
  virtual ~GeometryGantry() {};
  
  G4LogicalVolume* Construct(std::string detname);

private:
  void DefineMaterials() {};
  void SetupGeometry() {};

};

}

#endif


