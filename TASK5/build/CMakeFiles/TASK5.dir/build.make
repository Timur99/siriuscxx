# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\b_C++\cmake\cmake\cmake-3.25.0-rc3-windows-x86_64\bin\cmake.exe

# The command to remove a file.
RM = C:\b_C++\cmake\cmake\cmake-3.25.0-rc3-windows-x86_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\siriuscxx\TASK5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\siriuscxx\TASK5\build

# Include any dependencies generated for this target.
include CMakeFiles/TASK5.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TASK5.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TASK5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TASK5.dir/flags.make

CMakeFiles/TASK5.dir/list/main.cpp.obj: CMakeFiles/TASK5.dir/flags.make
CMakeFiles/TASK5.dir/list/main.cpp.obj: C:/siriuscxx/TASK5/list/main.cpp
CMakeFiles/TASK5.dir/list/main.cpp.obj: CMakeFiles/TASK5.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\siriuscxx\TASK5\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TASK5.dir/list/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TASK5.dir/list/main.cpp.obj -MF CMakeFiles\TASK5.dir\list\main.cpp.obj.d -o CMakeFiles\TASK5.dir\list\main.cpp.obj -c C:\siriuscxx\TASK5\list\main.cpp

CMakeFiles/TASK5.dir/list/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TASK5.dir/list/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\siriuscxx\TASK5\list\main.cpp > CMakeFiles\TASK5.dir\list\main.cpp.i

CMakeFiles/TASK5.dir/list/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TASK5.dir/list/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\siriuscxx\TASK5\list\main.cpp -o CMakeFiles\TASK5.dir\list\main.cpp.s

# Object files for target TASK5
TASK5_OBJECTS = \
"CMakeFiles/TASK5.dir/list/main.cpp.obj"

# External object files for target TASK5
TASK5_EXTERNAL_OBJECTS =

TASK5.exe: CMakeFiles/TASK5.dir/list/main.cpp.obj
TASK5.exe: CMakeFiles/TASK5.dir/build.make
TASK5.exe: CMakeFiles/TASK5.dir/linkLibs.rsp
TASK5.exe: CMakeFiles/TASK5.dir/objects1
TASK5.exe: CMakeFiles/TASK5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\siriuscxx\TASK5\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TASK5.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TASK5.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TASK5.dir/build: TASK5.exe
.PHONY : CMakeFiles/TASK5.dir/build

CMakeFiles/TASK5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TASK5.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TASK5.dir/clean

CMakeFiles/TASK5.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\siriuscxx\TASK5 C:\siriuscxx\TASK5 C:\siriuscxx\TASK5\build C:\siriuscxx\TASK5\build C:\siriuscxx\TASK5\build\CMakeFiles\TASK5.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TASK5.dir/depend
