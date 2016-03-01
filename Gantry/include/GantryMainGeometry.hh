#ifndef GantryMainGeometry_H
#define GantryMainGeometry_H 1

#include "VANLGeometry.hh"

class G4VUserDetectorConstruction;

namespace oistgantry {

class GantryMainGeometry : public anlgeant4::VANLGeometry
{
  DEFINE_ANL_MODULE(GantryMainGeometry, 1.0);

public:
  GantryMainGeometry() {}
  virtual ~GantryMainGeometry() {}
  
  anl::ANLStatus mod_startup();

  G4VUserDetectorConstruction* create();

private:
  std::string m_CollimatorName;

};

}

#endif /* GantryMainGeometry_H */
