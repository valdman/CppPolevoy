# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_SOURCE_DIR = /Users/boris/ClionProjects/polevoy/valdman_b_s

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/boris/ClionProjects/polevoy/valdman_b_s/cmake-build-debug

# Include any dependencies generated for this target.
include prj/nod/CMakeFiles/nod.dir/depend.make

# Include the progress variables for this target.
include prj/nod/CMakeFiles/nod.dir/progress.make

# Include the compile flags for this target's objects.
include prj/nod/CMakeFiles/nod.dir/flags.make

prj/nod/CMakeFiles/nod.dir/nod.cpp.o: prj/nod/CMakeFiles/nod.dir/flags.make
prj/nod/CMakeFiles/nod.dir/nod.cpp.o: ../prj/nod/nod.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/boris/ClionProjects/polevoy/valdman_b_s/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object prj/nod/CMakeFiles/nod.dir/nod.cpp.o"
	cd /Users/boris/ClionProjects/polevoy/valdman_b_s/cmake-build-debug/prj/nod && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/nod.dir/nod.cpp.o -c /Users/boris/ClionProjects/polevoy/valdman_b_s/prj/nod/nod.cpp

prj/nod/CMakeFiles/nod.dir/nod.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nod.dir/nod.cpp.i"
	cd /Users/boris/ClionProjects/polevoy/valdman_b_s/cmake-build-debug/prj/nod && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/boris/ClionProjects/polevoy/valdman_b_s/prj/nod/nod.cpp > CMakeFiles/nod.dir/nod.cpp.i

prj/nod/CMakeFiles/nod.dir/nod.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nod.dir/nod.cpp.s"
	cd /Users/boris/ClionProjects/polevoy/valdman_b_s/cmake-build-debug/prj/nod && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/boris/ClionProjects/polevoy/valdman_b_s/prj/nod/nod.cpp -o CMakeFiles/nod.dir/nod.cpp.s

prj/nod/CMakeFiles/nod.dir/nod.cpp.o.requires:

.PHONY : prj/nod/CMakeFiles/nod.dir/nod.cpp.o.requires

prj/nod/CMakeFiles/nod.dir/nod.cpp.o.provides: prj/nod/CMakeFiles/nod.dir/nod.cpp.o.requires
	$(MAKE) -f prj/nod/CMakeFiles/nod.dir/build.make prj/nod/CMakeFiles/nod.dir/nod.cpp.o.provides.build
.PHONY : prj/nod/CMakeFiles/nod.dir/nod.cpp.o.provides

prj/nod/CMakeFiles/nod.dir/nod.cpp.o.provides.build: prj/nod/CMakeFiles/nod.dir/nod.cpp.o


# Object files for target nod
nod_OBJECTS = \
"CMakeFiles/nod.dir/nod.cpp.o"

# External object files for target nod
nod_EXTERNAL_OBJECTS =

prj/nod/nod: prj/nod/CMakeFiles/nod.dir/nod.cpp.o
prj/nod/nod: prj/nod/CMakeFiles/nod.dir/build.make
prj/nod/nod: prj/nod/CMakeFiles/nod.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/boris/ClionProjects/polevoy/valdman_b_s/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable nod"
	cd /Users/boris/ClionProjects/polevoy/valdman_b_s/cmake-build-debug/prj/nod && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nod.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
prj/nod/CMakeFiles/nod.dir/build: prj/nod/nod

.PHONY : prj/nod/CMakeFiles/nod.dir/build

prj/nod/CMakeFiles/nod.dir/requires: prj/nod/CMakeFiles/nod.dir/nod.cpp.o.requires

.PHONY : prj/nod/CMakeFiles/nod.dir/requires

prj/nod/CMakeFiles/nod.dir/clean:
	cd /Users/boris/ClionProjects/polevoy/valdman_b_s/cmake-build-debug/prj/nod && $(CMAKE_COMMAND) -P CMakeFiles/nod.dir/cmake_clean.cmake
.PHONY : prj/nod/CMakeFiles/nod.dir/clean

prj/nod/CMakeFiles/nod.dir/depend:
	cd /Users/boris/ClionProjects/polevoy/valdman_b_s/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/boris/ClionProjects/polevoy/valdman_b_s /Users/boris/ClionProjects/polevoy/valdman_b_s/prj/nod /Users/boris/ClionProjects/polevoy/valdman_b_s/cmake-build-debug /Users/boris/ClionProjects/polevoy/valdman_b_s/cmake-build-debug/prj/nod /Users/boris/ClionProjects/polevoy/valdman_b_s/cmake-build-debug/prj/nod/CMakeFiles/nod.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : prj/nod/CMakeFiles/nod.dir/depend
