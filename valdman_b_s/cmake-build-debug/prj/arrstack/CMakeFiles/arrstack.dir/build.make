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
include prj/arrstack/CMakeFiles/arrstack.dir/depend.make

# Include the progress variables for this target.
include prj/arrstack/CMakeFiles/arrstack.dir/progress.make

# Include the compile flags for this target's objects.
include prj/arrstack/CMakeFiles/arrstack.dir/flags.make

prj/arrstack/CMakeFiles/arrstack.dir/main.cpp.o: prj/arrstack/CMakeFiles/arrstack.dir/flags.make
prj/arrstack/CMakeFiles/arrstack.dir/main.cpp.o: ../prj/arrstack/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/boris/ClionProjects/polevoy/valdman_b_s/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object prj/arrstack/CMakeFiles/arrstack.dir/main.cpp.o"
	cd /Users/boris/ClionProjects/polevoy/valdman_b_s/cmake-build-debug/prj/arrstack && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arrstack.dir/main.cpp.o -c /Users/boris/ClionProjects/polevoy/valdman_b_s/prj/arrstack/main.cpp

prj/arrstack/CMakeFiles/arrstack.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arrstack.dir/main.cpp.i"
	cd /Users/boris/ClionProjects/polevoy/valdman_b_s/cmake-build-debug/prj/arrstack && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/boris/ClionProjects/polevoy/valdman_b_s/prj/arrstack/main.cpp > CMakeFiles/arrstack.dir/main.cpp.i

prj/arrstack/CMakeFiles/arrstack.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arrstack.dir/main.cpp.s"
	cd /Users/boris/ClionProjects/polevoy/valdman_b_s/cmake-build-debug/prj/arrstack && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/boris/ClionProjects/polevoy/valdman_b_s/prj/arrstack/main.cpp -o CMakeFiles/arrstack.dir/main.cpp.s

prj/arrstack/CMakeFiles/arrstack.dir/main.cpp.o.requires:

.PHONY : prj/arrstack/CMakeFiles/arrstack.dir/main.cpp.o.requires

prj/arrstack/CMakeFiles/arrstack.dir/main.cpp.o.provides: prj/arrstack/CMakeFiles/arrstack.dir/main.cpp.o.requires
	$(MAKE) -f prj/arrstack/CMakeFiles/arrstack.dir/build.make prj/arrstack/CMakeFiles/arrstack.dir/main.cpp.o.provides.build
.PHONY : prj/arrstack/CMakeFiles/arrstack.dir/main.cpp.o.provides

prj/arrstack/CMakeFiles/arrstack.dir/main.cpp.o.provides.build: prj/arrstack/CMakeFiles/arrstack.dir/main.cpp.o


prj/arrstack/CMakeFiles/arrstack.dir/arrstack.cpp.o: prj/arrstack/CMakeFiles/arrstack.dir/flags.make
prj/arrstack/CMakeFiles/arrstack.dir/arrstack.cpp.o: ../prj/arrstack/arrstack.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/boris/ClionProjects/polevoy/valdman_b_s/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object prj/arrstack/CMakeFiles/arrstack.dir/arrstack.cpp.o"
	cd /Users/boris/ClionProjects/polevoy/valdman_b_s/cmake-build-debug/prj/arrstack && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arrstack.dir/arrstack.cpp.o -c /Users/boris/ClionProjects/polevoy/valdman_b_s/prj/arrstack/arrstack.cpp

prj/arrstack/CMakeFiles/arrstack.dir/arrstack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arrstack.dir/arrstack.cpp.i"
	cd /Users/boris/ClionProjects/polevoy/valdman_b_s/cmake-build-debug/prj/arrstack && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/boris/ClionProjects/polevoy/valdman_b_s/prj/arrstack/arrstack.cpp > CMakeFiles/arrstack.dir/arrstack.cpp.i

prj/arrstack/CMakeFiles/arrstack.dir/arrstack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arrstack.dir/arrstack.cpp.s"
	cd /Users/boris/ClionProjects/polevoy/valdman_b_s/cmake-build-debug/prj/arrstack && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/boris/ClionProjects/polevoy/valdman_b_s/prj/arrstack/arrstack.cpp -o CMakeFiles/arrstack.dir/arrstack.cpp.s

prj/arrstack/CMakeFiles/arrstack.dir/arrstack.cpp.o.requires:

.PHONY : prj/arrstack/CMakeFiles/arrstack.dir/arrstack.cpp.o.requires

prj/arrstack/CMakeFiles/arrstack.dir/arrstack.cpp.o.provides: prj/arrstack/CMakeFiles/arrstack.dir/arrstack.cpp.o.requires
	$(MAKE) -f prj/arrstack/CMakeFiles/arrstack.dir/build.make prj/arrstack/CMakeFiles/arrstack.dir/arrstack.cpp.o.provides.build
.PHONY : prj/arrstack/CMakeFiles/arrstack.dir/arrstack.cpp.o.provides

prj/arrstack/CMakeFiles/arrstack.dir/arrstack.cpp.o.provides.build: prj/arrstack/CMakeFiles/arrstack.dir/arrstack.cpp.o


# Object files for target arrstack
arrstack_OBJECTS = \
"CMakeFiles/arrstack.dir/main.cpp.o" \
"CMakeFiles/arrstack.dir/arrstack.cpp.o"

# External object files for target arrstack
arrstack_EXTERNAL_OBJECTS =

prj/arrstack/arrstack: prj/arrstack/CMakeFiles/arrstack.dir/main.cpp.o
prj/arrstack/arrstack: prj/arrstack/CMakeFiles/arrstack.dir/arrstack.cpp.o
prj/arrstack/arrstack: prj/arrstack/CMakeFiles/arrstack.dir/build.make
prj/arrstack/arrstack: prj/arrstack/CMakeFiles/arrstack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/boris/ClionProjects/polevoy/valdman_b_s/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable arrstack"
	cd /Users/boris/ClionProjects/polevoy/valdman_b_s/cmake-build-debug/prj/arrstack && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/arrstack.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
prj/arrstack/CMakeFiles/arrstack.dir/build: prj/arrstack/arrstack

.PHONY : prj/arrstack/CMakeFiles/arrstack.dir/build

prj/arrstack/CMakeFiles/arrstack.dir/requires: prj/arrstack/CMakeFiles/arrstack.dir/main.cpp.o.requires
prj/arrstack/CMakeFiles/arrstack.dir/requires: prj/arrstack/CMakeFiles/arrstack.dir/arrstack.cpp.o.requires

.PHONY : prj/arrstack/CMakeFiles/arrstack.dir/requires

prj/arrstack/CMakeFiles/arrstack.dir/clean:
	cd /Users/boris/ClionProjects/polevoy/valdman_b_s/cmake-build-debug/prj/arrstack && $(CMAKE_COMMAND) -P CMakeFiles/arrstack.dir/cmake_clean.cmake
.PHONY : prj/arrstack/CMakeFiles/arrstack.dir/clean

prj/arrstack/CMakeFiles/arrstack.dir/depend:
	cd /Users/boris/ClionProjects/polevoy/valdman_b_s/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/boris/ClionProjects/polevoy/valdman_b_s /Users/boris/ClionProjects/polevoy/valdman_b_s/prj/arrstack /Users/boris/ClionProjects/polevoy/valdman_b_s/cmake-build-debug /Users/boris/ClionProjects/polevoy/valdman_b_s/cmake-build-debug/prj/arrstack /Users/boris/ClionProjects/polevoy/valdman_b_s/cmake-build-debug/prj/arrstack/CMakeFiles/arrstack.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : prj/arrstack/CMakeFiles/arrstack.dir/depend
