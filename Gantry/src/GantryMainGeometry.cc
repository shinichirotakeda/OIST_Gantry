#include "GantryMainGeometry.hh"
#include "GantryMainGeometryRealWorld.hh"

using namespace anl;
using namespace anlgeant4;
using namespace oistgantry;

ANLStatus GantryMainGeometry::mod_startup() {

  register_parameter(&m_CollimatorName, "Collimator Name");
  set_parameter_description("Collimator Type (Type1, Type2, Type3 ......) ");
  return AS_OK;

}

G4VUserDetectorConstruction* GantryMainGeometry::create() {
  G4VUserDetectorConstruction* theGeometry = new GantryMainGeometryRealWorld(m_CollimatorName);
  return theGeometry;
}
