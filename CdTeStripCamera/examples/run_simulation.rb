#! /usr/bin/env ruby
require 'comptonsoft/basic'

require 'cdTeStripCameraGeometry'
include CdTeStripCameraGeometry


def run_simulation(num, random)

  energy = 30.0 # keV
  posx = 0.049 #cm
  posy = 0.0 #cm
  posz = 16.8 #cm

  dirx = 0.0
  diry = 0.0
  dirz = -1.0
  thetamax = 0.0
  output = "ht_ene#{energy}_posx#{posx}cm_posy#{posy}cm_poz#{posz}cm_seed#{random}.root"
    
  sim = ComptonSoft::Simulation.new
  sim.output = output
  sim.random_seed = random
  sim.verbose = 1

  sim.detector_config = "database/detector_configuration.xml"
  sim.simulation_param = "database/simulation_parameters.xml"
  sim.analysis_param = "database/analysis_parameters.xml"

  sim.set_physics(hadron_hp: false, cut_value: 0.001)

  sim.set_geometry :CdTeStripCameraMainGeometry, {
    "Collimator Name" => "MuonType3",
  }
  
  sim.set_primary_generator :PointSourcePrimaryGen, {
    particle: "gamma",
    photon_index: 0.0,
    energy_min: energy,
    energy_max: energy,
    position: vec(posx, posy, posz),
    direction: vec(dirx, diry, dirz),
    theta_min: 0.0,
    theta_max: thetamax,
  }

  sim.run(num)
end

### main ###

num = 100
run_id = 0
random = run_id
run_simulation(num, random)
