# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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
CMAKE_COMMAND = "/Applications/CMake 2.8-4.app/Contents/bin/cmake"

# The command to remove a file.
RM = "/Applications/CMake 2.8-4.app/Contents/bin/cmake" -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = "/Applications/CMake 2.8-4.app/Contents/bin/ccmake"

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ntustison/Desktop/Source

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ntustison/Desktop/Source/bin

# Utility rule file for Continuous.

CMakeFiles/Continuous:
	"/Applications/CMake 2.8-4.app/Contents/bin/ctest" -D Continuous

Continuous: CMakeFiles/Continuous
Continuous: CMakeFiles/Continuous.dir/build.make
.PHONY : Continuous

# Rule to build all files generated by this target.
CMakeFiles/Continuous.dir/build: Continuous
.PHONY : CMakeFiles/Continuous.dir/build

CMakeFiles/Continuous.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Continuous.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Continuous.dir/clean

CMakeFiles/Continuous.dir/depend:
	cd /Users/ntustison/Desktop/Source/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ntustison/Desktop/Source /Users/ntustison/Desktop/Source /Users/ntustison/Desktop/Source/bin /Users/ntustison/Desktop/Source/bin /Users/ntustison/Desktop/Source/bin/CMakeFiles/Continuous.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Continuous.dir/depend

