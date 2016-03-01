%module oISTGantryGeometry
%{

#include "GantryMainGeometry.hh"
#include "class_list_anlGeant4.hh"

%}

%import "anlGeant4.i"

namespace oistgantry {

  class GantryMainGeometry : public anlgeant4::VANLGeometry
  {
  public:
   GantryMainGeometry() {}
   virtual ~GantryMainGeometry() {}
   
  };
  
}

