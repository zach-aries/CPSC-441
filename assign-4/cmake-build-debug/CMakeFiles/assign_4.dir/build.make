# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/assign_4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/assign_4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/assign_4.dir/flags.make

CMakeFiles/assign_4.dir/main.cpp.o: CMakeFiles/assign_4.dir/flags.make
CMakeFiles/assign_4.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zacharyaries/Documents/GitHub/CPSC-441/assign-4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/assign_4.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/assign_4.dir/main.cpp.o -c /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-4/main.cpp

CMakeFiles/assign_4.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assign_4.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-4/main.cpp > CMakeFiles/assign_4.dir/main.cpp.i

CMakeFiles/assign_4.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assign_4.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-4/main.cpp -o CMakeFiles/assign_4.dir/main.cpp.s

CMakeFiles/assign_4.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/assign_4.dir/main.cpp.o.requires

CMakeFiles/assign_4.dir/main.cpp.o.provides: CMakeFiles/assign_4.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/assign_4.dir/build.make CMakeFiles/assign_4.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/assign_4.dir/main.cpp.o.provides

CMakeFiles/assign_4.dir/main.cpp.o.provides.build: CMakeFiles/assign_4.dir/main.cpp.o


CMakeFiles/assign_4.dir/src/binary_tree.cpp.o: CMakeFiles/assign_4.dir/flags.make
CMakeFiles/assign_4.dir/src/binary_tree.cpp.o: ../src/binary_tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zacharyaries/Documents/GitHub/CPSC-441/assign-4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/assign_4.dir/src/binary_tree.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/assign_4.dir/src/binary_tree.cpp.o -c /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-4/src/binary_tree.cpp

CMakeFiles/assign_4.dir/src/binary_tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assign_4.dir/src/binary_tree.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-4/src/binary_tree.cpp > CMakeFiles/assign_4.dir/src/binary_tree.cpp.i

CMakeFiles/assign_4.dir/src/binary_tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assign_4.dir/src/binary_tree.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-4/src/binary_tree.cpp -o CMakeFiles/assign_4.dir/src/binary_tree.cpp.s

CMakeFiles/assign_4.dir/src/binary_tree.cpp.o.requires:

.PHONY : CMakeFiles/assign_4.dir/src/binary_tree.cpp.o.requires

CMakeFiles/assign_4.dir/src/binary_tree.cpp.o.provides: CMakeFiles/assign_4.dir/src/binary_tree.cpp.o.requires
	$(MAKE) -f CMakeFiles/assign_4.dir/build.make CMakeFiles/assign_4.dir/src/binary_tree.cpp.o.provides.build
.PHONY : CMakeFiles/assign_4.dir/src/binary_tree.cpp.o.provides

CMakeFiles/assign_4.dir/src/binary_tree.cpp.o.provides.build: CMakeFiles/assign_4.dir/src/binary_tree.cpp.o


CMakeFiles/assign_4.dir/src/tree_processor.cpp.o: CMakeFiles/assign_4.dir/flags.make
CMakeFiles/assign_4.dir/src/tree_processor.cpp.o: ../src/tree_processor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zacharyaries/Documents/GitHub/CPSC-441/assign-4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/assign_4.dir/src/tree_processor.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/assign_4.dir/src/tree_processor.cpp.o -c /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-4/src/tree_processor.cpp

CMakeFiles/assign_4.dir/src/tree_processor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assign_4.dir/src/tree_processor.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-4/src/tree_processor.cpp > CMakeFiles/assign_4.dir/src/tree_processor.cpp.i

CMakeFiles/assign_4.dir/src/tree_processor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assign_4.dir/src/tree_processor.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-4/src/tree_processor.cpp -o CMakeFiles/assign_4.dir/src/tree_processor.cpp.s

CMakeFiles/assign_4.dir/src/tree_processor.cpp.o.requires:

.PHONY : CMakeFiles/assign_4.dir/src/tree_processor.cpp.o.requires

CMakeFiles/assign_4.dir/src/tree_processor.cpp.o.provides: CMakeFiles/assign_4.dir/src/tree_processor.cpp.o.requires
	$(MAKE) -f CMakeFiles/assign_4.dir/build.make CMakeFiles/assign_4.dir/src/tree_processor.cpp.o.provides.build
.PHONY : CMakeFiles/assign_4.dir/src/tree_processor.cpp.o.provides

CMakeFiles/assign_4.dir/src/tree_processor.cpp.o.provides.build: CMakeFiles/assign_4.dir/src/tree_processor.cpp.o


# Object files for target assign_4
assign_4_OBJECTS = \
"CMakeFiles/assign_4.dir/main.cpp.o" \
"CMakeFiles/assign_4.dir/src/binary_tree.cpp.o" \
"CMakeFiles/assign_4.dir/src/tree_processor.cpp.o"

# External object files for target assign_4
assign_4_EXTERNAL_OBJECTS =

assign_4: CMakeFiles/assign_4.dir/main.cpp.o
assign_4: CMakeFiles/assign_4.dir/src/binary_tree.cpp.o
assign_4: CMakeFiles/assign_4.dir/src/tree_processor.cpp.o
assign_4: CMakeFiles/assign_4.dir/build.make
assign_4: CMakeFiles/assign_4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zacharyaries/Documents/GitHub/CPSC-441/assign-4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable assign_4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/assign_4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/assign_4.dir/build: assign_4

.PHONY : CMakeFiles/assign_4.dir/build

CMakeFiles/assign_4.dir/requires: CMakeFiles/assign_4.dir/main.cpp.o.requires
CMakeFiles/assign_4.dir/requires: CMakeFiles/assign_4.dir/src/binary_tree.cpp.o.requires
CMakeFiles/assign_4.dir/requires: CMakeFiles/assign_4.dir/src/tree_processor.cpp.o.requires

.PHONY : CMakeFiles/assign_4.dir/requires

CMakeFiles/assign_4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/assign_4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/assign_4.dir/clean

CMakeFiles/assign_4.dir/depend:
	cd /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-4 /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-4 /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-4/cmake-build-debug /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-4/cmake-build-debug /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-4/cmake-build-debug/CMakeFiles/assign_4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/assign_4.dir/depend

