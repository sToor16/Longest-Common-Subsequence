# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /Users/toor/Desktop/Toor/lcs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/toor/Desktop/Toor/lcs/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lcs.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lcs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lcs.dir/flags.make

CMakeFiles/lcs.dir/main.cpp.o: CMakeFiles/lcs.dir/flags.make
CMakeFiles/lcs.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/toor/Desktop/Toor/lcs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lcs.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lcs.dir/main.cpp.o -c /Users/toor/Desktop/Toor/lcs/main.cpp

CMakeFiles/lcs.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lcs.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/toor/Desktop/Toor/lcs/main.cpp > CMakeFiles/lcs.dir/main.cpp.i

CMakeFiles/lcs.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lcs.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/toor/Desktop/Toor/lcs/main.cpp -o CMakeFiles/lcs.dir/main.cpp.s

CMakeFiles/lcs.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/lcs.dir/main.cpp.o.requires

CMakeFiles/lcs.dir/main.cpp.o.provides: CMakeFiles/lcs.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/lcs.dir/build.make CMakeFiles/lcs.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/lcs.dir/main.cpp.o.provides

CMakeFiles/lcs.dir/main.cpp.o.provides.build: CMakeFiles/lcs.dir/main.cpp.o


# Object files for target lcs
lcs_OBJECTS = \
"CMakeFiles/lcs.dir/main.cpp.o"

# External object files for target lcs
lcs_EXTERNAL_OBJECTS =

lcs: CMakeFiles/lcs.dir/main.cpp.o
lcs: CMakeFiles/lcs.dir/build.make
lcs: CMakeFiles/lcs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/toor/Desktop/Toor/lcs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lcs"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lcs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lcs.dir/build: lcs

.PHONY : CMakeFiles/lcs.dir/build

CMakeFiles/lcs.dir/requires: CMakeFiles/lcs.dir/main.cpp.o.requires

.PHONY : CMakeFiles/lcs.dir/requires

CMakeFiles/lcs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lcs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lcs.dir/clean

CMakeFiles/lcs.dir/depend:
	cd /Users/toor/Desktop/Toor/lcs/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/toor/Desktop/Toor/lcs /Users/toor/Desktop/Toor/lcs /Users/toor/Desktop/Toor/lcs/cmake-build-debug /Users/toor/Desktop/Toor/lcs/cmake-build-debug /Users/toor/Desktop/Toor/lcs/cmake-build-debug/CMakeFiles/lcs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lcs.dir/depend

