# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2020.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\github\Coursera Tasks\database"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\github\Coursera Tasks\database\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/database.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/database.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/database.dir/flags.make

CMakeFiles/database.dir/main.cpp.obj: CMakeFiles/database.dir/flags.make
CMakeFiles/database.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\github\Coursera Tasks\database\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/database.dir/main.cpp.obj"
	D:\comp\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\database.dir\main.cpp.obj -c "D:\github\Coursera Tasks\database\main.cpp"

CMakeFiles/database.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/database.dir/main.cpp.i"
	D:\comp\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\github\Coursera Tasks\database\main.cpp" > CMakeFiles\database.dir\main.cpp.i

CMakeFiles/database.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/database.dir/main.cpp.s"
	D:\comp\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\github\Coursera Tasks\database\main.cpp" -o CMakeFiles\database.dir\main.cpp.s

# Object files for target database
database_OBJECTS = \
"CMakeFiles/database.dir/main.cpp.obj"

# External object files for target database
database_EXTERNAL_OBJECTS =

database.exe: CMakeFiles/database.dir/main.cpp.obj
database.exe: CMakeFiles/database.dir/build.make
database.exe: CMakeFiles/database.dir/linklibs.rsp
database.exe: CMakeFiles/database.dir/objects1.rsp
database.exe: CMakeFiles/database.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\github\Coursera Tasks\database\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable database.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\database.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/database.dir/build: database.exe

.PHONY : CMakeFiles/database.dir/build

CMakeFiles/database.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\database.dir\cmake_clean.cmake
.PHONY : CMakeFiles/database.dir/clean

CMakeFiles/database.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\github\Coursera Tasks\database" "D:\github\Coursera Tasks\database" "D:\github\Coursera Tasks\database\cmake-build-debug" "D:\github\Coursera Tasks\database\cmake-build-debug" "D:\github\Coursera Tasks\database\cmake-build-debug\CMakeFiles\database.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/database.dir/depend

