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
CMAKE_COMMAND = /opt/clion/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/adronov/git/neuro

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adronov/git/neuro/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/neuro.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/neuro.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/neuro.dir/flags.make

CMakeFiles/neuro.dir/main.cpp.o: CMakeFiles/neuro.dir/flags.make
CMakeFiles/neuro.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adronov/git/neuro/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/neuro.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/neuro.dir/main.cpp.o -c /home/adronov/git/neuro/main.cpp

CMakeFiles/neuro.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/neuro.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adronov/git/neuro/main.cpp > CMakeFiles/neuro.dir/main.cpp.i

CMakeFiles/neuro.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/neuro.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adronov/git/neuro/main.cpp -o CMakeFiles/neuro.dir/main.cpp.s

CMakeFiles/neuro.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/neuro.dir/main.cpp.o.requires

CMakeFiles/neuro.dir/main.cpp.o.provides: CMakeFiles/neuro.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/neuro.dir/build.make CMakeFiles/neuro.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/neuro.dir/main.cpp.o.provides

CMakeFiles/neuro.dir/main.cpp.o.provides.build: CMakeFiles/neuro.dir/main.cpp.o


CMakeFiles/neuro.dir/net.cpp.o: CMakeFiles/neuro.dir/flags.make
CMakeFiles/neuro.dir/net.cpp.o: ../net.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adronov/git/neuro/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/neuro.dir/net.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/neuro.dir/net.cpp.o -c /home/adronov/git/neuro/net.cpp

CMakeFiles/neuro.dir/net.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/neuro.dir/net.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adronov/git/neuro/net.cpp > CMakeFiles/neuro.dir/net.cpp.i

CMakeFiles/neuro.dir/net.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/neuro.dir/net.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adronov/git/neuro/net.cpp -o CMakeFiles/neuro.dir/net.cpp.s

CMakeFiles/neuro.dir/net.cpp.o.requires:

.PHONY : CMakeFiles/neuro.dir/net.cpp.o.requires

CMakeFiles/neuro.dir/net.cpp.o.provides: CMakeFiles/neuro.dir/net.cpp.o.requires
	$(MAKE) -f CMakeFiles/neuro.dir/build.make CMakeFiles/neuro.dir/net.cpp.o.provides.build
.PHONY : CMakeFiles/neuro.dir/net.cpp.o.provides

CMakeFiles/neuro.dir/net.cpp.o.provides.build: CMakeFiles/neuro.dir/net.cpp.o


# Object files for target neuro
neuro_OBJECTS = \
"CMakeFiles/neuro.dir/main.cpp.o" \
"CMakeFiles/neuro.dir/net.cpp.o"

# External object files for target neuro
neuro_EXTERNAL_OBJECTS =

neuro: CMakeFiles/neuro.dir/main.cpp.o
neuro: CMakeFiles/neuro.dir/net.cpp.o
neuro: CMakeFiles/neuro.dir/build.make
neuro: CMakeFiles/neuro.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adronov/git/neuro/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable neuro"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/neuro.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/neuro.dir/build: neuro

.PHONY : CMakeFiles/neuro.dir/build

CMakeFiles/neuro.dir/requires: CMakeFiles/neuro.dir/main.cpp.o.requires
CMakeFiles/neuro.dir/requires: CMakeFiles/neuro.dir/net.cpp.o.requires

.PHONY : CMakeFiles/neuro.dir/requires

CMakeFiles/neuro.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/neuro.dir/cmake_clean.cmake
.PHONY : CMakeFiles/neuro.dir/clean

CMakeFiles/neuro.dir/depend:
	cd /home/adronov/git/neuro/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adronov/git/neuro /home/adronov/git/neuro /home/adronov/git/neuro/cmake-build-debug /home/adronov/git/neuro/cmake-build-debug /home/adronov/git/neuro/cmake-build-debug/CMakeFiles/neuro.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/neuro.dir/depend

