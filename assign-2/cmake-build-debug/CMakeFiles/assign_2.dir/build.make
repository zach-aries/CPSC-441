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
CMAKE_SOURCE_DIR = /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/assign_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/assign_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/assign_2.dir/flags.make

CMakeFiles/assign_2.dir/main.cpp.o: CMakeFiles/assign_2.dir/flags.make
CMakeFiles/assign_2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/assign_2.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/assign_2.dir/main.cpp.o -c /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2/main.cpp

CMakeFiles/assign_2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assign_2.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2/main.cpp > CMakeFiles/assign_2.dir/main.cpp.i

CMakeFiles/assign_2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assign_2.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2/main.cpp -o CMakeFiles/assign_2.dir/main.cpp.s

CMakeFiles/assign_2.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/assign_2.dir/main.cpp.o.requires

CMakeFiles/assign_2.dir/main.cpp.o.provides: CMakeFiles/assign_2.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/assign_2.dir/build.make CMakeFiles/assign_2.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/assign_2.dir/main.cpp.o.provides

CMakeFiles/assign_2.dir/main.cpp.o.provides.build: CMakeFiles/assign_2.dir/main.cpp.o


CMakeFiles/assign_2.dir/src/Debug.cpp.o: CMakeFiles/assign_2.dir/flags.make
CMakeFiles/assign_2.dir/src/Debug.cpp.o: ../src/Debug.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/assign_2.dir/src/Debug.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/assign_2.dir/src/Debug.cpp.o -c /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2/src/Debug.cpp

CMakeFiles/assign_2.dir/src/Debug.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assign_2.dir/src/Debug.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2/src/Debug.cpp > CMakeFiles/assign_2.dir/src/Debug.cpp.i

CMakeFiles/assign_2.dir/src/Debug.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assign_2.dir/src/Debug.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2/src/Debug.cpp -o CMakeFiles/assign_2.dir/src/Debug.cpp.s

CMakeFiles/assign_2.dir/src/Debug.cpp.o.requires:

.PHONY : CMakeFiles/assign_2.dir/src/Debug.cpp.o.requires

CMakeFiles/assign_2.dir/src/Debug.cpp.o.provides: CMakeFiles/assign_2.dir/src/Debug.cpp.o.requires
	$(MAKE) -f CMakeFiles/assign_2.dir/build.make CMakeFiles/assign_2.dir/src/Debug.cpp.o.provides.build
.PHONY : CMakeFiles/assign_2.dir/src/Debug.cpp.o.provides

CMakeFiles/assign_2.dir/src/Debug.cpp.o.provides.build: CMakeFiles/assign_2.dir/src/Debug.cpp.o


CMakeFiles/assign_2.dir/src/Server.cpp.o: CMakeFiles/assign_2.dir/flags.make
CMakeFiles/assign_2.dir/src/Server.cpp.o: ../src/Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/assign_2.dir/src/Server.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/assign_2.dir/src/Server.cpp.o -c /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2/src/Server.cpp

CMakeFiles/assign_2.dir/src/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assign_2.dir/src/Server.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2/src/Server.cpp > CMakeFiles/assign_2.dir/src/Server.cpp.i

CMakeFiles/assign_2.dir/src/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assign_2.dir/src/Server.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2/src/Server.cpp -o CMakeFiles/assign_2.dir/src/Server.cpp.s

CMakeFiles/assign_2.dir/src/Server.cpp.o.requires:

.PHONY : CMakeFiles/assign_2.dir/src/Server.cpp.o.requires

CMakeFiles/assign_2.dir/src/Server.cpp.o.provides: CMakeFiles/assign_2.dir/src/Server.cpp.o.requires
	$(MAKE) -f CMakeFiles/assign_2.dir/build.make CMakeFiles/assign_2.dir/src/Server.cpp.o.provides.build
.PHONY : CMakeFiles/assign_2.dir/src/Server.cpp.o.provides

CMakeFiles/assign_2.dir/src/Server.cpp.o.provides.build: CMakeFiles/assign_2.dir/src/Server.cpp.o


CMakeFiles/assign_2.dir/src/Client.cpp.o: CMakeFiles/assign_2.dir/flags.make
CMakeFiles/assign_2.dir/src/Client.cpp.o: ../src/Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/assign_2.dir/src/Client.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/assign_2.dir/src/Client.cpp.o -c /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2/src/Client.cpp

CMakeFiles/assign_2.dir/src/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assign_2.dir/src/Client.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2/src/Client.cpp > CMakeFiles/assign_2.dir/src/Client.cpp.i

CMakeFiles/assign_2.dir/src/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assign_2.dir/src/Client.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2/src/Client.cpp -o CMakeFiles/assign_2.dir/src/Client.cpp.s

CMakeFiles/assign_2.dir/src/Client.cpp.o.requires:

.PHONY : CMakeFiles/assign_2.dir/src/Client.cpp.o.requires

CMakeFiles/assign_2.dir/src/Client.cpp.o.provides: CMakeFiles/assign_2.dir/src/Client.cpp.o.requires
	$(MAKE) -f CMakeFiles/assign_2.dir/build.make CMakeFiles/assign_2.dir/src/Client.cpp.o.provides.build
.PHONY : CMakeFiles/assign_2.dir/src/Client.cpp.o.provides

CMakeFiles/assign_2.dir/src/Client.cpp.o.provides.build: CMakeFiles/assign_2.dir/src/Client.cpp.o


CMakeFiles/assign_2.dir/src/FileHelper.cpp.o: CMakeFiles/assign_2.dir/flags.make
CMakeFiles/assign_2.dir/src/FileHelper.cpp.o: ../src/FileHelper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/assign_2.dir/src/FileHelper.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/assign_2.dir/src/FileHelper.cpp.o -c /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2/src/FileHelper.cpp

CMakeFiles/assign_2.dir/src/FileHelper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assign_2.dir/src/FileHelper.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2/src/FileHelper.cpp > CMakeFiles/assign_2.dir/src/FileHelper.cpp.i

CMakeFiles/assign_2.dir/src/FileHelper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assign_2.dir/src/FileHelper.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2/src/FileHelper.cpp -o CMakeFiles/assign_2.dir/src/FileHelper.cpp.s

CMakeFiles/assign_2.dir/src/FileHelper.cpp.o.requires:

.PHONY : CMakeFiles/assign_2.dir/src/FileHelper.cpp.o.requires

CMakeFiles/assign_2.dir/src/FileHelper.cpp.o.provides: CMakeFiles/assign_2.dir/src/FileHelper.cpp.o.requires
	$(MAKE) -f CMakeFiles/assign_2.dir/build.make CMakeFiles/assign_2.dir/src/FileHelper.cpp.o.provides.build
.PHONY : CMakeFiles/assign_2.dir/src/FileHelper.cpp.o.provides

CMakeFiles/assign_2.dir/src/FileHelper.cpp.o.provides.build: CMakeFiles/assign_2.dir/src/FileHelper.cpp.o


CMakeFiles/assign_2.dir/src/Protocol.cpp.o: CMakeFiles/assign_2.dir/flags.make
CMakeFiles/assign_2.dir/src/Protocol.cpp.o: ../src/Protocol.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/assign_2.dir/src/Protocol.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/assign_2.dir/src/Protocol.cpp.o -c /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2/src/Protocol.cpp

CMakeFiles/assign_2.dir/src/Protocol.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assign_2.dir/src/Protocol.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2/src/Protocol.cpp > CMakeFiles/assign_2.dir/src/Protocol.cpp.i

CMakeFiles/assign_2.dir/src/Protocol.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assign_2.dir/src/Protocol.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2/src/Protocol.cpp -o CMakeFiles/assign_2.dir/src/Protocol.cpp.s

CMakeFiles/assign_2.dir/src/Protocol.cpp.o.requires:

.PHONY : CMakeFiles/assign_2.dir/src/Protocol.cpp.o.requires

CMakeFiles/assign_2.dir/src/Protocol.cpp.o.provides: CMakeFiles/assign_2.dir/src/Protocol.cpp.o.requires
	$(MAKE) -f CMakeFiles/assign_2.dir/build.make CMakeFiles/assign_2.dir/src/Protocol.cpp.o.provides.build
.PHONY : CMakeFiles/assign_2.dir/src/Protocol.cpp.o.provides

CMakeFiles/assign_2.dir/src/Protocol.cpp.o.provides.build: CMakeFiles/assign_2.dir/src/Protocol.cpp.o


# Object files for target assign_2
assign_2_OBJECTS = \
"CMakeFiles/assign_2.dir/main.cpp.o" \
"CMakeFiles/assign_2.dir/src/Debug.cpp.o" \
"CMakeFiles/assign_2.dir/src/Server.cpp.o" \
"CMakeFiles/assign_2.dir/src/Client.cpp.o" \
"CMakeFiles/assign_2.dir/src/FileHelper.cpp.o" \
"CMakeFiles/assign_2.dir/src/Protocol.cpp.o"

# External object files for target assign_2
assign_2_EXTERNAL_OBJECTS =

assign_2: CMakeFiles/assign_2.dir/main.cpp.o
assign_2: CMakeFiles/assign_2.dir/src/Debug.cpp.o
assign_2: CMakeFiles/assign_2.dir/src/Server.cpp.o
assign_2: CMakeFiles/assign_2.dir/src/Client.cpp.o
assign_2: CMakeFiles/assign_2.dir/src/FileHelper.cpp.o
assign_2: CMakeFiles/assign_2.dir/src/Protocol.cpp.o
assign_2: CMakeFiles/assign_2.dir/build.make
assign_2: CMakeFiles/assign_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable assign_2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/assign_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/assign_2.dir/build: assign_2

.PHONY : CMakeFiles/assign_2.dir/build

CMakeFiles/assign_2.dir/requires: CMakeFiles/assign_2.dir/main.cpp.o.requires
CMakeFiles/assign_2.dir/requires: CMakeFiles/assign_2.dir/src/Debug.cpp.o.requires
CMakeFiles/assign_2.dir/requires: CMakeFiles/assign_2.dir/src/Server.cpp.o.requires
CMakeFiles/assign_2.dir/requires: CMakeFiles/assign_2.dir/src/Client.cpp.o.requires
CMakeFiles/assign_2.dir/requires: CMakeFiles/assign_2.dir/src/FileHelper.cpp.o.requires
CMakeFiles/assign_2.dir/requires: CMakeFiles/assign_2.dir/src/Protocol.cpp.o.requires

.PHONY : CMakeFiles/assign_2.dir/requires

CMakeFiles/assign_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/assign_2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/assign_2.dir/clean

CMakeFiles/assign_2.dir/depend:
	cd /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2 /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2 /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2/cmake-build-debug /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2/cmake-build-debug /Users/zacharyaries/Documents/GitHub/CPSC-441/assign-2/cmake-build-debug/CMakeFiles/assign_2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/assign_2.dir/depend

