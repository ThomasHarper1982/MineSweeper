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
CMAKE_SOURCE_DIR = /home/thomas/Documents/Projects/MineSweeper

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/thomas/Documents/Projects/MineSweeper/build

# Include any dependencies generated for this target.
include CMakeFiles/MineSweeper.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MineSweeper.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MineSweeper.dir/flags.make

CMakeFiles/MineSweeper.dir/src/main.cpp.o: CMakeFiles/MineSweeper.dir/flags.make
CMakeFiles/MineSweeper.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thomas/Documents/Projects/MineSweeper/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MineSweeper.dir/src/main.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MineSweeper.dir/src/main.cpp.o -c /home/thomas/Documents/Projects/MineSweeper/src/main.cpp

CMakeFiles/MineSweeper.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MineSweeper.dir/src/main.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thomas/Documents/Projects/MineSweeper/src/main.cpp > CMakeFiles/MineSweeper.dir/src/main.cpp.i

CMakeFiles/MineSweeper.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MineSweeper.dir/src/main.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thomas/Documents/Projects/MineSweeper/src/main.cpp -o CMakeFiles/MineSweeper.dir/src/main.cpp.s

CMakeFiles/MineSweeper.dir/src/game.cpp.o: CMakeFiles/MineSweeper.dir/flags.make
CMakeFiles/MineSweeper.dir/src/game.cpp.o: ../src/game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thomas/Documents/Projects/MineSweeper/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MineSweeper.dir/src/game.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MineSweeper.dir/src/game.cpp.o -c /home/thomas/Documents/Projects/MineSweeper/src/game.cpp

CMakeFiles/MineSweeper.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MineSweeper.dir/src/game.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thomas/Documents/Projects/MineSweeper/src/game.cpp > CMakeFiles/MineSweeper.dir/src/game.cpp.i

CMakeFiles/MineSweeper.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MineSweeper.dir/src/game.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thomas/Documents/Projects/MineSweeper/src/game.cpp -o CMakeFiles/MineSweeper.dir/src/game.cpp.s

CMakeFiles/MineSweeper.dir/src/controller.cpp.o: CMakeFiles/MineSweeper.dir/flags.make
CMakeFiles/MineSweeper.dir/src/controller.cpp.o: ../src/controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thomas/Documents/Projects/MineSweeper/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MineSweeper.dir/src/controller.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MineSweeper.dir/src/controller.cpp.o -c /home/thomas/Documents/Projects/MineSweeper/src/controller.cpp

CMakeFiles/MineSweeper.dir/src/controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MineSweeper.dir/src/controller.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thomas/Documents/Projects/MineSweeper/src/controller.cpp > CMakeFiles/MineSweeper.dir/src/controller.cpp.i

CMakeFiles/MineSweeper.dir/src/controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MineSweeper.dir/src/controller.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thomas/Documents/Projects/MineSweeper/src/controller.cpp -o CMakeFiles/MineSweeper.dir/src/controller.cpp.s

CMakeFiles/MineSweeper.dir/src/renderer.cpp.o: CMakeFiles/MineSweeper.dir/flags.make
CMakeFiles/MineSweeper.dir/src/renderer.cpp.o: ../src/renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thomas/Documents/Projects/MineSweeper/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/MineSweeper.dir/src/renderer.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MineSweeper.dir/src/renderer.cpp.o -c /home/thomas/Documents/Projects/MineSweeper/src/renderer.cpp

CMakeFiles/MineSweeper.dir/src/renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MineSweeper.dir/src/renderer.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thomas/Documents/Projects/MineSweeper/src/renderer.cpp > CMakeFiles/MineSweeper.dir/src/renderer.cpp.i

CMakeFiles/MineSweeper.dir/src/renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MineSweeper.dir/src/renderer.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thomas/Documents/Projects/MineSweeper/src/renderer.cpp -o CMakeFiles/MineSweeper.dir/src/renderer.cpp.s

CMakeFiles/MineSweeper.dir/src/Array2D.cpp.o: CMakeFiles/MineSweeper.dir/flags.make
CMakeFiles/MineSweeper.dir/src/Array2D.cpp.o: ../src/Array2D.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thomas/Documents/Projects/MineSweeper/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/MineSweeper.dir/src/Array2D.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MineSweeper.dir/src/Array2D.cpp.o -c /home/thomas/Documents/Projects/MineSweeper/src/Array2D.cpp

CMakeFiles/MineSweeper.dir/src/Array2D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MineSweeper.dir/src/Array2D.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thomas/Documents/Projects/MineSweeper/src/Array2D.cpp > CMakeFiles/MineSweeper.dir/src/Array2D.cpp.i

CMakeFiles/MineSweeper.dir/src/Array2D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MineSweeper.dir/src/Array2D.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thomas/Documents/Projects/MineSweeper/src/Array2D.cpp -o CMakeFiles/MineSweeper.dir/src/Array2D.cpp.s

CMakeFiles/MineSweeper.dir/src/GameState.cpp.o: CMakeFiles/MineSweeper.dir/flags.make
CMakeFiles/MineSweeper.dir/src/GameState.cpp.o: ../src/GameState.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/thomas/Documents/Projects/MineSweeper/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/MineSweeper.dir/src/GameState.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MineSweeper.dir/src/GameState.cpp.o -c /home/thomas/Documents/Projects/MineSweeper/src/GameState.cpp

CMakeFiles/MineSweeper.dir/src/GameState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MineSweeper.dir/src/GameState.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/thomas/Documents/Projects/MineSweeper/src/GameState.cpp > CMakeFiles/MineSweeper.dir/src/GameState.cpp.i

CMakeFiles/MineSweeper.dir/src/GameState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MineSweeper.dir/src/GameState.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/thomas/Documents/Projects/MineSweeper/src/GameState.cpp -o CMakeFiles/MineSweeper.dir/src/GameState.cpp.s

# Object files for target MineSweeper
MineSweeper_OBJECTS = \
"CMakeFiles/MineSweeper.dir/src/main.cpp.o" \
"CMakeFiles/MineSweeper.dir/src/game.cpp.o" \
"CMakeFiles/MineSweeper.dir/src/controller.cpp.o" \
"CMakeFiles/MineSweeper.dir/src/renderer.cpp.o" \
"CMakeFiles/MineSweeper.dir/src/Array2D.cpp.o" \
"CMakeFiles/MineSweeper.dir/src/GameState.cpp.o"

# External object files for target MineSweeper
MineSweeper_EXTERNAL_OBJECTS =

MineSweeper: CMakeFiles/MineSweeper.dir/src/main.cpp.o
MineSweeper: CMakeFiles/MineSweeper.dir/src/game.cpp.o
MineSweeper: CMakeFiles/MineSweeper.dir/src/controller.cpp.o
MineSweeper: CMakeFiles/MineSweeper.dir/src/renderer.cpp.o
MineSweeper: CMakeFiles/MineSweeper.dir/src/Array2D.cpp.o
MineSweeper: CMakeFiles/MineSweeper.dir/src/GameState.cpp.o
MineSweeper: CMakeFiles/MineSweeper.dir/build.make
MineSweeper: /usr/lib/x86_64-linux-gnu/libSDL2_ttf.so
MineSweeper: /usr/lib/x86_64-linux-gnu/libSDL2_ttf.so
MineSweeper: CMakeFiles/MineSweeper.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/thomas/Documents/Projects/MineSweeper/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable MineSweeper"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MineSweeper.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MineSweeper.dir/build: MineSweeper

.PHONY : CMakeFiles/MineSweeper.dir/build

CMakeFiles/MineSweeper.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MineSweeper.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MineSweeper.dir/clean

CMakeFiles/MineSweeper.dir/depend:
	cd /home/thomas/Documents/Projects/MineSweeper/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/thomas/Documents/Projects/MineSweeper /home/thomas/Documents/Projects/MineSweeper /home/thomas/Documents/Projects/MineSweeper/build /home/thomas/Documents/Projects/MineSweeper/build /home/thomas/Documents/Projects/MineSweeper/build/CMakeFiles/MineSweeper.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MineSweeper.dir/depend

