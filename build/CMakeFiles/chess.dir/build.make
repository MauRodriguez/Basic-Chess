# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mauricio/Documents/Chess

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mauricio/Documents/Chess/build

# Include any dependencies generated for this target.
include CMakeFiles/chess.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/chess.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chess.dir/flags.make

CMakeFiles/chess.dir/src/drawer/drawer.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/drawer/drawer.cpp.o: ../src/drawer/drawer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mauricio/Documents/Chess/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/chess.dir/src/drawer/drawer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess.dir/src/drawer/drawer.cpp.o -c /home/mauricio/Documents/Chess/src/drawer/drawer.cpp

CMakeFiles/chess.dir/src/drawer/drawer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/drawer/drawer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mauricio/Documents/Chess/src/drawer/drawer.cpp > CMakeFiles/chess.dir/src/drawer/drawer.cpp.i

CMakeFiles/chess.dir/src/drawer/drawer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/drawer/drawer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mauricio/Documents/Chess/src/drawer/drawer.cpp -o CMakeFiles/chess.dir/src/drawer/drawer.cpp.s

CMakeFiles/chess.dir/src/drawer/mbutton.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/drawer/mbutton.cpp.o: ../src/drawer/mbutton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mauricio/Documents/Chess/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/chess.dir/src/drawer/mbutton.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess.dir/src/drawer/mbutton.cpp.o -c /home/mauricio/Documents/Chess/src/drawer/mbutton.cpp

CMakeFiles/chess.dir/src/drawer/mbutton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/drawer/mbutton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mauricio/Documents/Chess/src/drawer/mbutton.cpp > CMakeFiles/chess.dir/src/drawer/mbutton.cpp.i

CMakeFiles/chess.dir/src/drawer/mbutton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/drawer/mbutton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mauricio/Documents/Chess/src/drawer/mbutton.cpp -o CMakeFiles/chess.dir/src/drawer/mbutton.cpp.s

CMakeFiles/chess.dir/src/game/game.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/game/game.cpp.o: ../src/game/game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mauricio/Documents/Chess/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/chess.dir/src/game/game.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess.dir/src/game/game.cpp.o -c /home/mauricio/Documents/Chess/src/game/game.cpp

CMakeFiles/chess.dir/src/game/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/game/game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mauricio/Documents/Chess/src/game/game.cpp > CMakeFiles/chess.dir/src/game/game.cpp.i

CMakeFiles/chess.dir/src/game/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/game/game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mauricio/Documents/Chess/src/game/game.cpp -o CMakeFiles/chess.dir/src/game/game.cpp.s

CMakeFiles/chess.dir/src/chess/chess.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/chess/chess.cpp.o: ../src/chess/chess.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mauricio/Documents/Chess/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/chess.dir/src/chess/chess.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess.dir/src/chess/chess.cpp.o -c /home/mauricio/Documents/Chess/src/chess/chess.cpp

CMakeFiles/chess.dir/src/chess/chess.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/chess/chess.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mauricio/Documents/Chess/src/chess/chess.cpp > CMakeFiles/chess.dir/src/chess/chess.cpp.i

CMakeFiles/chess.dir/src/chess/chess.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/chess/chess.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mauricio/Documents/Chess/src/chess/chess.cpp -o CMakeFiles/chess.dir/src/chess/chess.cpp.s

CMakeFiles/chess.dir/src/chess/piece.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/chess/piece.cpp.o: ../src/chess/piece.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mauricio/Documents/Chess/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/chess.dir/src/chess/piece.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess.dir/src/chess/piece.cpp.o -c /home/mauricio/Documents/Chess/src/chess/piece.cpp

CMakeFiles/chess.dir/src/chess/piece.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/chess/piece.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mauricio/Documents/Chess/src/chess/piece.cpp > CMakeFiles/chess.dir/src/chess/piece.cpp.i

CMakeFiles/chess.dir/src/chess/piece.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/chess/piece.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mauricio/Documents/Chess/src/chess/piece.cpp -o CMakeFiles/chess.dir/src/chess/piece.cpp.s

CMakeFiles/chess.dir/src/main.cpp.o: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mauricio/Documents/Chess/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/chess.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chess.dir/src/main.cpp.o -c /home/mauricio/Documents/Chess/src/main.cpp

CMakeFiles/chess.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mauricio/Documents/Chess/src/main.cpp > CMakeFiles/chess.dir/src/main.cpp.i

CMakeFiles/chess.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mauricio/Documents/Chess/src/main.cpp -o CMakeFiles/chess.dir/src/main.cpp.s

# Object files for target chess
chess_OBJECTS = \
"CMakeFiles/chess.dir/src/drawer/drawer.cpp.o" \
"CMakeFiles/chess.dir/src/drawer/mbutton.cpp.o" \
"CMakeFiles/chess.dir/src/game/game.cpp.o" \
"CMakeFiles/chess.dir/src/chess/chess.cpp.o" \
"CMakeFiles/chess.dir/src/chess/piece.cpp.o" \
"CMakeFiles/chess.dir/src/main.cpp.o"

# External object files for target chess
chess_EXTERNAL_OBJECTS =

chess: CMakeFiles/chess.dir/src/drawer/drawer.cpp.o
chess: CMakeFiles/chess.dir/src/drawer/mbutton.cpp.o
chess: CMakeFiles/chess.dir/src/game/game.cpp.o
chess: CMakeFiles/chess.dir/src/chess/chess.cpp.o
chess: CMakeFiles/chess.dir/src/chess/piece.cpp.o
chess: CMakeFiles/chess.dir/src/main.cpp.o
chess: CMakeFiles/chess.dir/build.make
chess: CMakeFiles/chess.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mauricio/Documents/Chess/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable chess"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chess.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chess.dir/build: chess

.PHONY : CMakeFiles/chess.dir/build

CMakeFiles/chess.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/chess.dir/cmake_clean.cmake
.PHONY : CMakeFiles/chess.dir/clean

CMakeFiles/chess.dir/depend:
	cd /home/mauricio/Documents/Chess/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mauricio/Documents/Chess /home/mauricio/Documents/Chess /home/mauricio/Documents/Chess/build /home/mauricio/Documents/Chess/build /home/mauricio/Documents/Chess/build/CMakeFiles/chess.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/chess.dir/depend

