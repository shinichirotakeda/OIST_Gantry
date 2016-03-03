#!/usr/bin/env ruby

#require 'cslib'
require 'comptonsoft/basic'
include ComptonSoft

require 'oISTapp'
include OISTapp


#hittreefiles = Dir.glob( "hittree.root" )
#comptreefile = ARGV[0]

hittreefiles = Dir.glob("ht*.root")
imagefile = "image.root"

detector_config = "../database/detector_configuration.xml"

anl = ANL::ANLApp.new
anl.chain :CSHitCollection
anl.chain :ConstructDetector
anl.chain :ReadHitTree
anl.chain :OISTDetectorImage
anl.chain :SaveData

anl.set_parameters :ConstructDetector, {
  detector_configuration: detector_config,
}

anl.set_parameters :ReadHitTree, {
  file_list: hittreefiles,
}

anl.set_parameters :OISTDetectorImage, {
  energy_min: 25.0,
  energy_max: 30.0,
}

anl.set_parameters :SaveData, {
  output: imagefile,
}

anl.run(-1, 10000)

