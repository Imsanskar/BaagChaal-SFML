# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/imsanskar/Desktop/PROJECTS/BaagChaal-SFML

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/imsanskar/Desktop/PROJECTS/BaagChaal-SFML

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/imsanskar/Desktop/PROJECTS/BaagChaal-SFML/CMakeFiles /home/imsanskar/Desktop/PROJECTS/BaagChaal-SFML/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/imsanskar/Desktop/PROJECTS/BaagChaal-SFML/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Baagchaal

# Build rule for target.
Baagchaal: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Baagchaal
.PHONY : Baagchaal

# fast build rule for target.
Baagchaal/fast:
	$(MAKE) -f CMakeFiles/Baagchaal.dir/build.make CMakeFiles/Baagchaal.dir/build
.PHONY : Baagchaal/fast

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/Baagchaal.dir/build.make CMakeFiles/Baagchaal.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/Baagchaal.dir/build.make CMakeFiles/Baagchaal.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/Baagchaal.dir/build.make CMakeFiles/Baagchaal.dir/main.cpp.s
.PHONY : main.cpp.s

src/AI.o: src/AI.cpp.o

.PHONY : src/AI.o

# target to build an object file
src/AI.cpp.o:
	$(MAKE) -f CMakeFiles/Baagchaal.dir/build.make CMakeFiles/Baagchaal.dir/src/AI.cpp.o
.PHONY : src/AI.cpp.o

src/AI.i: src/AI.cpp.i

.PHONY : src/AI.i

# target to preprocess a source file
src/AI.cpp.i:
	$(MAKE) -f CMakeFiles/Baagchaal.dir/build.make CMakeFiles/Baagchaal.dir/src/AI.cpp.i
.PHONY : src/AI.cpp.i

src/AI.s: src/AI.cpp.s

.PHONY : src/AI.s

# target to generate assembly for a file
src/AI.cpp.s:
	$(MAKE) -f CMakeFiles/Baagchaal.dir/build.make CMakeFiles/Baagchaal.dir/src/AI.cpp.s
.PHONY : src/AI.cpp.s

src/Cell.o: src/Cell.cpp.o

.PHONY : src/Cell.o

# target to build an object file
src/Cell.cpp.o:
	$(MAKE) -f CMakeFiles/Baagchaal.dir/build.make CMakeFiles/Baagchaal.dir/src/Cell.cpp.o
.PHONY : src/Cell.cpp.o

src/Cell.i: src/Cell.cpp.i

.PHONY : src/Cell.i

# target to preprocess a source file
src/Cell.cpp.i:
	$(MAKE) -f CMakeFiles/Baagchaal.dir/build.make CMakeFiles/Baagchaal.dir/src/Cell.cpp.i
.PHONY : src/Cell.cpp.i

src/Cell.s: src/Cell.cpp.s

.PHONY : src/Cell.s

# target to generate assembly for a file
src/Cell.cpp.s:
	$(MAKE) -f CMakeFiles/Baagchaal.dir/build.make CMakeFiles/Baagchaal.dir/src/Cell.cpp.s
.PHONY : src/Cell.cpp.s

src/Game.o: src/Game.cpp.o

.PHONY : src/Game.o

# target to build an object file
src/Game.cpp.o:
	$(MAKE) -f CMakeFiles/Baagchaal.dir/build.make CMakeFiles/Baagchaal.dir/src/Game.cpp.o
.PHONY : src/Game.cpp.o

src/Game.i: src/Game.cpp.i

.PHONY : src/Game.i

# target to preprocess a source file
src/Game.cpp.i:
	$(MAKE) -f CMakeFiles/Baagchaal.dir/build.make CMakeFiles/Baagchaal.dir/src/Game.cpp.i
.PHONY : src/Game.cpp.i

src/Game.s: src/Game.cpp.s

.PHONY : src/Game.s

# target to generate assembly for a file
src/Game.cpp.s:
	$(MAKE) -f CMakeFiles/Baagchaal.dir/build.make CMakeFiles/Baagchaal.dir/src/Game.cpp.s
.PHONY : src/Game.cpp.s

src/LoadBoard.o: src/LoadBoard.cpp.o

.PHONY : src/LoadBoard.o

# target to build an object file
src/LoadBoard.cpp.o:
	$(MAKE) -f CMakeFiles/Baagchaal.dir/build.make CMakeFiles/Baagchaal.dir/src/LoadBoard.cpp.o
.PHONY : src/LoadBoard.cpp.o

src/LoadBoard.i: src/LoadBoard.cpp.i

.PHONY : src/LoadBoard.i

# target to preprocess a source file
src/LoadBoard.cpp.i:
	$(MAKE) -f CMakeFiles/Baagchaal.dir/build.make CMakeFiles/Baagchaal.dir/src/LoadBoard.cpp.i
.PHONY : src/LoadBoard.cpp.i

src/LoadBoard.s: src/LoadBoard.cpp.s

.PHONY : src/LoadBoard.s

# target to generate assembly for a file
src/LoadBoard.cpp.s:
	$(MAKE) -f CMakeFiles/Baagchaal.dir/build.make CMakeFiles/Baagchaal.dir/src/LoadBoard.cpp.s
.PHONY : src/LoadBoard.cpp.s

src/Mainmenu.o: src/Mainmenu.cpp.o

.PHONY : src/Mainmenu.o

# target to build an object file
src/Mainmenu.cpp.o:
	$(MAKE) -f CMakeFiles/Baagchaal.dir/build.make CMakeFiles/Baagchaal.dir/src/Mainmenu.cpp.o
.PHONY : src/Mainmenu.cpp.o

src/Mainmenu.i: src/Mainmenu.cpp.i

.PHONY : src/Mainmenu.i

# target to preprocess a source file
src/Mainmenu.cpp.i:
	$(MAKE) -f CMakeFiles/Baagchaal.dir/build.make CMakeFiles/Baagchaal.dir/src/Mainmenu.cpp.i
.PHONY : src/Mainmenu.cpp.i

src/Mainmenu.s: src/Mainmenu.cpp.s

.PHONY : src/Mainmenu.s

# target to generate assembly for a file
src/Mainmenu.cpp.s:
	$(MAKE) -f CMakeFiles/Baagchaal.dir/build.make CMakeFiles/Baagchaal.dir/src/Mainmenu.cpp.s
.PHONY : src/Mainmenu.cpp.s

src/Piece.o: src/Piece.cpp.o

.PHONY : src/Piece.o

# target to build an object file
src/Piece.cpp.o:
	$(MAKE) -f CMakeFiles/Baagchaal.dir/build.make CMakeFiles/Baagchaal.dir/src/Piece.cpp.o
.PHONY : src/Piece.cpp.o

src/Piece.i: src/Piece.cpp.i

.PHONY : src/Piece.i

# target to preprocess a source file
src/Piece.cpp.i:
	$(MAKE) -f CMakeFiles/Baagchaal.dir/build.make CMakeFiles/Baagchaal.dir/src/Piece.cpp.i
.PHONY : src/Piece.cpp.i

src/Piece.s: src/Piece.cpp.s

.PHONY : src/Piece.s

# target to generate assembly for a file
src/Piece.cpp.s:
	$(MAKE) -f CMakeFiles/Baagchaal.dir/build.make CMakeFiles/Baagchaal.dir/src/Piece.cpp.s
.PHONY : src/Piece.cpp.s

src/goats.o: src/goats.cpp.o

.PHONY : src/goats.o

# target to build an object file
src/goats.cpp.o:
	$(MAKE) -f CMakeFiles/Baagchaal.dir/build.make CMakeFiles/Baagchaal.dir/src/goats.cpp.o
.PHONY : src/goats.cpp.o

src/goats.i: src/goats.cpp.i

.PHONY : src/goats.i

# target to preprocess a source file
src/goats.cpp.i:
	$(MAKE) -f CMakeFiles/Baagchaal.dir/build.make CMakeFiles/Baagchaal.dir/src/goats.cpp.i
.PHONY : src/goats.cpp.i

src/goats.s: src/goats.cpp.s

.PHONY : src/goats.s

# target to generate assembly for a file
src/goats.cpp.s:
	$(MAKE) -f CMakeFiles/Baagchaal.dir/build.make CMakeFiles/Baagchaal.dir/src/goats.cpp.s
.PHONY : src/goats.cpp.s

src/quitGame.o: src/quitGame.cpp.o

.PHONY : src/quitGame.o

# target to build an object file
src/quitGame.cpp.o:
	$(MAKE) -f CMakeFiles/Baagchaal.dir/build.make CMakeFiles/Baagchaal.dir/src/quitGame.cpp.o
.PHONY : src/quitGame.cpp.o

src/quitGame.i: src/quitGame.cpp.i

.PHONY : src/quitGame.i

# target to preprocess a source file
src/quitGame.cpp.i:
	$(MAKE) -f CMakeFiles/Baagchaal.dir/build.make CMakeFiles/Baagchaal.dir/src/quitGame.cpp.i
.PHONY : src/quitGame.cpp.i

src/quitGame.s: src/quitGame.cpp.s

.PHONY : src/quitGame.s

# target to generate assembly for a file
src/quitGame.cpp.s:
	$(MAKE) -f CMakeFiles/Baagchaal.dir/build.make CMakeFiles/Baagchaal.dir/src/quitGame.cpp.s
.PHONY : src/quitGame.cpp.s

src/tigers.o: src/tigers.cpp.o

.PHONY : src/tigers.o

# target to build an object file
src/tigers.cpp.o:
	$(MAKE) -f CMakeFiles/Baagchaal.dir/build.make CMakeFiles/Baagchaal.dir/src/tigers.cpp.o
.PHONY : src/tigers.cpp.o

src/tigers.i: src/tigers.cpp.i

.PHONY : src/tigers.i

# target to preprocess a source file
src/tigers.cpp.i:
	$(MAKE) -f CMakeFiles/Baagchaal.dir/build.make CMakeFiles/Baagchaal.dir/src/tigers.cpp.i
.PHONY : src/tigers.cpp.i

src/tigers.s: src/tigers.cpp.s

.PHONY : src/tigers.s

# target to generate assembly for a file
src/tigers.cpp.s:
	$(MAKE) -f CMakeFiles/Baagchaal.dir/build.make CMakeFiles/Baagchaal.dir/src/tigers.cpp.s
.PHONY : src/tigers.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... Baagchaal"
	@echo "... edit_cache"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... src/AI.o"
	@echo "... src/AI.i"
	@echo "... src/AI.s"
	@echo "... src/Cell.o"
	@echo "... src/Cell.i"
	@echo "... src/Cell.s"
	@echo "... src/Game.o"
	@echo "... src/Game.i"
	@echo "... src/Game.s"
	@echo "... src/LoadBoard.o"
	@echo "... src/LoadBoard.i"
	@echo "... src/LoadBoard.s"
	@echo "... src/Mainmenu.o"
	@echo "... src/Mainmenu.i"
	@echo "... src/Mainmenu.s"
	@echo "... src/Piece.o"
	@echo "... src/Piece.i"
	@echo "... src/Piece.s"
	@echo "... src/goats.o"
	@echo "... src/goats.i"
	@echo "... src/goats.s"
	@echo "... src/quitGame.o"
	@echo "... src/quitGame.i"
	@echo "... src/quitGame.s"
	@echo "... src/tigers.o"
	@echo "... src/tigers.i"
	@echo "... src/tigers.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

