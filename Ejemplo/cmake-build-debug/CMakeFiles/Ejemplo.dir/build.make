# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/esteban/clion-2017.1.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/esteban/clion-2017.1.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/esteban/Ejemplo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/esteban/Ejemplo/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Ejemplo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Ejemplo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Ejemplo.dir/flags.make

CMakeFiles/Ejemplo.dir/main.cpp.o: CMakeFiles/Ejemplo.dir/flags.make
CMakeFiles/Ejemplo.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/esteban/Ejemplo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Ejemplo.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Ejemplo.dir/main.cpp.o -c /home/esteban/Ejemplo/main.cpp

CMakeFiles/Ejemplo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ejemplo.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/esteban/Ejemplo/main.cpp > CMakeFiles/Ejemplo.dir/main.cpp.i

CMakeFiles/Ejemplo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ejemplo.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/esteban/Ejemplo/main.cpp -o CMakeFiles/Ejemplo.dir/main.cpp.s

CMakeFiles/Ejemplo.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Ejemplo.dir/main.cpp.o.requires

CMakeFiles/Ejemplo.dir/main.cpp.o.provides: CMakeFiles/Ejemplo.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Ejemplo.dir/build.make CMakeFiles/Ejemplo.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Ejemplo.dir/main.cpp.o.provides

CMakeFiles/Ejemplo.dir/main.cpp.o.provides.build: CMakeFiles/Ejemplo.dir/main.cpp.o


# Object files for target Ejemplo
Ejemplo_OBJECTS = \
"CMakeFiles/Ejemplo.dir/main.cpp.o"

# External object files for target Ejemplo
Ejemplo_EXTERNAL_OBJECTS =

Ejemplo: CMakeFiles/Ejemplo.dir/main.cpp.o
Ejemplo: CMakeFiles/Ejemplo.dir/build.make
Ejemplo: CMakeFiles/Ejemplo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/esteban/Ejemplo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Ejemplo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Ejemplo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Ejemplo.dir/build: Ejemplo

.PHONY : CMakeFiles/Ejemplo.dir/build

CMakeFiles/Ejemplo.dir/requires: CMakeFiles/Ejemplo.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Ejemplo.dir/requires

CMakeFiles/Ejemplo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Ejemplo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Ejemplo.dir/clean

CMakeFiles/Ejemplo.dir/depend:
	cd /home/esteban/Ejemplo/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/esteban/Ejemplo /home/esteban/Ejemplo /home/esteban/Ejemplo/cmake-build-debug /home/esteban/Ejemplo/cmake-build-debug /home/esteban/Ejemplo/cmake-build-debug/CMakeFiles/Ejemplo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Ejemplo.dir/depend

