# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.14.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.14.5/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/harrys/Desktop/chess_knight

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/harrys/Desktop/chess_knight/build

# Include any dependencies generated for this target.
include CMakeFiles/chessKnightMoves.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/chessKnightMoves.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chessKnightMoves.dir/flags.make

CMakeFiles/chessKnightMoves.dir/chessKnightMoves.c.o: CMakeFiles/chessKnightMoves.dir/flags.make
CMakeFiles/chessKnightMoves.dir/chessKnightMoves.c.o: ../chessKnightMoves.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/harrys/Desktop/chess_knight/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/chessKnightMoves.dir/chessKnightMoves.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/chessKnightMoves.dir/chessKnightMoves.c.o   -c /Users/harrys/Desktop/chess_knight/chessKnightMoves.c

CMakeFiles/chessKnightMoves.dir/chessKnightMoves.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/chessKnightMoves.dir/chessKnightMoves.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/harrys/Desktop/chess_knight/chessKnightMoves.c > CMakeFiles/chessKnightMoves.dir/chessKnightMoves.c.i

CMakeFiles/chessKnightMoves.dir/chessKnightMoves.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/chessKnightMoves.dir/chessKnightMoves.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/harrys/Desktop/chess_knight/chessKnightMoves.c -o CMakeFiles/chessKnightMoves.dir/chessKnightMoves.c.s

# Object files for target chessKnightMoves
chessKnightMoves_OBJECTS = \
"CMakeFiles/chessKnightMoves.dir/chessKnightMoves.c.o"

# External object files for target chessKnightMoves
chessKnightMoves_EXTERNAL_OBJECTS =

chessKnightMoves: CMakeFiles/chessKnightMoves.dir/chessKnightMoves.c.o
chessKnightMoves: CMakeFiles/chessKnightMoves.dir/build.make
chessKnightMoves: CMakeFiles/chessKnightMoves.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/harrys/Desktop/chess_knight/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable chessKnightMoves"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chessKnightMoves.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chessKnightMoves.dir/build: chessKnightMoves

.PHONY : CMakeFiles/chessKnightMoves.dir/build

CMakeFiles/chessKnightMoves.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/chessKnightMoves.dir/cmake_clean.cmake
.PHONY : CMakeFiles/chessKnightMoves.dir/clean

CMakeFiles/chessKnightMoves.dir/depend:
	cd /Users/harrys/Desktop/chess_knight/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/harrys/Desktop/chess_knight /Users/harrys/Desktop/chess_knight /Users/harrys/Desktop/chess_knight/build /Users/harrys/Desktop/chess_knight/build /Users/harrys/Desktop/chess_knight/build/CMakeFiles/chessKnightMoves.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/chessKnightMoves.dir/depend
