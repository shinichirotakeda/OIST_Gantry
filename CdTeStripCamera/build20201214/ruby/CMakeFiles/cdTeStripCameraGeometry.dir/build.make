# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.12.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.12.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/takeda/soft/OIST_Gantry/CdTeStripCamera

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/takeda/soft/OIST_Gantry/CdTeStripCamera/build20201214

# Include any dependencies generated for this target.
include ruby/CMakeFiles/cdTeStripCameraGeometry.dir/depend.make

# Include the progress variables for this target.
include ruby/CMakeFiles/cdTeStripCameraGeometry.dir/progress.make

# Include the compile flags for this target's objects.
include ruby/CMakeFiles/cdTeStripCameraGeometry.dir/flags.make

ruby/CMakeFiles/cdTeStripCameraGeometry.dir/CMakeFiles/cdTeStripCameraGeometry.dir/cdTeStripCameraGeometryRUBY_wrap.cxx.o: ruby/CMakeFiles/cdTeStripCameraGeometry.dir/flags.make
ruby/CMakeFiles/cdTeStripCameraGeometry.dir/CMakeFiles/cdTeStripCameraGeometry.dir/cdTeStripCameraGeometryRUBY_wrap.cxx.o: ruby/CMakeFiles/cdTeStripCameraGeometry.dir/cdTeStripCameraGeometryRUBY_wrap.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/takeda/soft/OIST_Gantry/CdTeStripCamera/build20201214/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ruby/CMakeFiles/cdTeStripCameraGeometry.dir/CMakeFiles/cdTeStripCameraGeometry.dir/cdTeStripCameraGeometryRUBY_wrap.cxx.o"
	cd /Users/takeda/soft/OIST_Gantry/CdTeStripCamera/build20201214/ruby && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cdTeStripCameraGeometry.dir/CMakeFiles/cdTeStripCameraGeometry.dir/cdTeStripCameraGeometryRUBY_wrap.cxx.o -c /Users/takeda/soft/OIST_Gantry/CdTeStripCamera/build20201214/ruby/CMakeFiles/cdTeStripCameraGeometry.dir/cdTeStripCameraGeometryRUBY_wrap.cxx

ruby/CMakeFiles/cdTeStripCameraGeometry.dir/CMakeFiles/cdTeStripCameraGeometry.dir/cdTeStripCameraGeometryRUBY_wrap.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cdTeStripCameraGeometry.dir/CMakeFiles/cdTeStripCameraGeometry.dir/cdTeStripCameraGeometryRUBY_wrap.cxx.i"
	cd /Users/takeda/soft/OIST_Gantry/CdTeStripCamera/build20201214/ruby && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/takeda/soft/OIST_Gantry/CdTeStripCamera/build20201214/ruby/CMakeFiles/cdTeStripCameraGeometry.dir/cdTeStripCameraGeometryRUBY_wrap.cxx > CMakeFiles/cdTeStripCameraGeometry.dir/CMakeFiles/cdTeStripCameraGeometry.dir/cdTeStripCameraGeometryRUBY_wrap.cxx.i

ruby/CMakeFiles/cdTeStripCameraGeometry.dir/CMakeFiles/cdTeStripCameraGeometry.dir/cdTeStripCameraGeometryRUBY_wrap.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cdTeStripCameraGeometry.dir/CMakeFiles/cdTeStripCameraGeometry.dir/cdTeStripCameraGeometryRUBY_wrap.cxx.s"
	cd /Users/takeda/soft/OIST_Gantry/CdTeStripCamera/build20201214/ruby && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/takeda/soft/OIST_Gantry/CdTeStripCamera/build20201214/ruby/CMakeFiles/cdTeStripCameraGeometry.dir/cdTeStripCameraGeometryRUBY_wrap.cxx -o CMakeFiles/cdTeStripCameraGeometry.dir/CMakeFiles/cdTeStripCameraGeometry.dir/cdTeStripCameraGeometryRUBY_wrap.cxx.s

# Object files for target cdTeStripCameraGeometry
cdTeStripCameraGeometry_OBJECTS = \
"CMakeFiles/cdTeStripCameraGeometry.dir/CMakeFiles/cdTeStripCameraGeometry.dir/cdTeStripCameraGeometryRUBY_wrap.cxx.o"

# External object files for target cdTeStripCameraGeometry
cdTeStripCameraGeometry_EXTERNAL_OBJECTS =

ruby/cdTeStripCameraGeometry.bundle: ruby/CMakeFiles/cdTeStripCameraGeometry.dir/CMakeFiles/cdTeStripCameraGeometry.dir/cdTeStripCameraGeometryRUBY_wrap.cxx.o
ruby/cdTeStripCameraGeometry.bundle: ruby/CMakeFiles/cdTeStripCameraGeometry.dir/build.make
ruby/cdTeStripCameraGeometry.bundle: libCdTeStripCameraGeometry.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/local/geant4/geant4.10.01.p02-install/lib/libG4Tree.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/local/geant4/geant4.10.01.p02-install/lib/libG4GMocren.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/local/geant4/geant4.10.01.p02-install/lib/libG4visHepRep.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/local/geant4/geant4.10.01.p02-install/lib/libG4RayTracer.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/local/geant4/geant4.10.01.p02-install/lib/libG4VRML.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/local/geant4/geant4.10.01.p02-install/lib/libG4interfaces.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/local/geant4/geant4.10.01.p02-install/lib/libG4persistency.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/local/geant4/geant4.10.01.p02-install/lib/libG4analysis.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/local/geant4/geant4.10.01.p02-install/lib/libG4error_propagation.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/local/geant4/geant4.10.01.p02-install/lib/libG4readout.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/local/geant4/geant4.10.01.p02-install/lib/libG4physicslists.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/local/geant4/geant4.10.01.p02-install/lib/libG4parmodels.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/local/geant4/geant4.10.01.p02-install/lib/libG4FR.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/X11R6/lib/libSM.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/X11R6/lib/libICE.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/X11R6/lib/libX11.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/X11R6/lib/libXext.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/local/geant4/geant4.10.01.p02-install/lib/libG4vis_management.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/local/geant4/geant4.10.01.p02-install/lib/libG4modeling.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/local/lib/libxerces-c.so
ruby/cdTeStripCameraGeometry.bundle: /usr/local/geant4/geant4.10.01.p02-install/lib/libG4run.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/local/geant4/geant4.10.01.p02-install/lib/libG4event.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/local/geant4/geant4.10.01.p02-install/lib/libG4tracking.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/local/geant4/geant4.10.01.p02-install/lib/libG4processes.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/lib/libexpat.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/local/geant4/geant4.10.01.p02-install/lib/libG4digits_hits.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/local/geant4/geant4.10.01.p02-install/lib/libG4track.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/local/geant4/geant4.10.01.p02-install/lib/libG4particles.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/local/geant4/geant4.10.01.p02-install/lib/libG4geometry.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/local/geant4/geant4.10.01.p02-install/lib/libG4materials.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/local/geant4/geant4.10.01.p02-install/lib/libG4graphics_reps.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/local/geant4/geant4.10.01.p02-install/lib/libG4intercoms.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/local/geant4/geant4.10.01.p02-install/lib/libG4global.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/local/geant4/geant4.10.01.p02-install/lib/libG4clhep.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/local/geant4/geant4.10.01.p02-install/lib/libG4zlib.dylib
ruby/cdTeStripCameraGeometry.bundle: /usr/local/geant4/geant4.10.01.p02-install/lib/libG4geomUSolids.dylib
ruby/cdTeStripCameraGeometry.bundle: ruby/CMakeFiles/cdTeStripCameraGeometry.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/takeda/soft/OIST_Gantry/CdTeStripCamera/build20201214/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared module cdTeStripCameraGeometry.bundle"
	cd /Users/takeda/soft/OIST_Gantry/CdTeStripCamera/build20201214/ruby && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cdTeStripCameraGeometry.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ruby/CMakeFiles/cdTeStripCameraGeometry.dir/build: ruby/cdTeStripCameraGeometry.bundle

.PHONY : ruby/CMakeFiles/cdTeStripCameraGeometry.dir/build

ruby/CMakeFiles/cdTeStripCameraGeometry.dir/clean:
	cd /Users/takeda/soft/OIST_Gantry/CdTeStripCamera/build20201214/ruby && $(CMAKE_COMMAND) -P CMakeFiles/cdTeStripCameraGeometry.dir/cmake_clean.cmake
.PHONY : ruby/CMakeFiles/cdTeStripCameraGeometry.dir/clean

ruby/CMakeFiles/cdTeStripCameraGeometry.dir/depend:
	cd /Users/takeda/soft/OIST_Gantry/CdTeStripCamera/build20201214 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/takeda/soft/OIST_Gantry/CdTeStripCamera /Users/takeda/soft/OIST_Gantry/CdTeStripCamera/ruby /Users/takeda/soft/OIST_Gantry/CdTeStripCamera/build20201214 /Users/takeda/soft/OIST_Gantry/CdTeStripCamera/build20201214/ruby /Users/takeda/soft/OIST_Gantry/CdTeStripCamera/build20201214/ruby/CMakeFiles/cdTeStripCameraGeometry.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ruby/CMakeFiles/cdTeStripCameraGeometry.dir/depend

