# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/m0narch/Downloads/clion-2019.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/m0narch/Downloads/clion-2019.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/m0narch/Documents/Code/repo-Team16/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/m0narch/Documents/Code/repo-Team16/src/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/src.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/src.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/src.dir/flags.make

CMakeFiles/src.dir/Candidate.cpp.o: CMakeFiles/src.dir/flags.make
CMakeFiles/src.dir/Candidate.cpp.o: ../Candidate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m0narch/Documents/Code/repo-Team16/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/src.dir/Candidate.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/src.dir/Candidate.cpp.o -c /home/m0narch/Documents/Code/repo-Team16/src/Candidate.cpp

CMakeFiles/src.dir/Candidate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/Candidate.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m0narch/Documents/Code/repo-Team16/src/Candidate.cpp > CMakeFiles/src.dir/Candidate.cpp.i

CMakeFiles/src.dir/Candidate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/Candidate.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m0narch/Documents/Code/repo-Team16/src/Candidate.cpp -o CMakeFiles/src.dir/Candidate.cpp.s

CMakeFiles/src.dir/Candidates.cpp.o: CMakeFiles/src.dir/flags.make
CMakeFiles/src.dir/Candidates.cpp.o: ../Candidates.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m0narch/Documents/Code/repo-Team16/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/src.dir/Candidates.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/src.dir/Candidates.cpp.o -c /home/m0narch/Documents/Code/repo-Team16/src/Candidates.cpp

CMakeFiles/src.dir/Candidates.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/Candidates.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m0narch/Documents/Code/repo-Team16/src/Candidates.cpp > CMakeFiles/src.dir/Candidates.cpp.i

CMakeFiles/src.dir/Candidates.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/Candidates.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m0narch/Documents/Code/repo-Team16/src/Candidates.cpp -o CMakeFiles/src.dir/Candidates.cpp.s

CMakeFiles/src.dir/main.cpp.o: CMakeFiles/src.dir/flags.make
CMakeFiles/src.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m0narch/Documents/Code/repo-Team16/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/src.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/src.dir/main.cpp.o -c /home/m0narch/Documents/Code/repo-Team16/src/main.cpp

CMakeFiles/src.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m0narch/Documents/Code/repo-Team16/src/main.cpp > CMakeFiles/src.dir/main.cpp.i

CMakeFiles/src.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m0narch/Documents/Code/repo-Team16/src/main.cpp -o CMakeFiles/src.dir/main.cpp.s

# Object files for target src
src_OBJECTS = \
"CMakeFiles/src.dir/Candidate.cpp.o" \
"CMakeFiles/src.dir/Candidates.cpp.o" \
"CMakeFiles/src.dir/main.cpp.o"

# External object files for target src
src_EXTERNAL_OBJECTS =

src: CMakeFiles/src.dir/Candidate.cpp.o
src: CMakeFiles/src.dir/Candidates.cpp.o
src: CMakeFiles/src.dir/main.cpp.o
src: CMakeFiles/src.dir/build.make
src: CMakeFiles/src.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/m0narch/Documents/Code/repo-Team16/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable src"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/src.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/src.dir/build: src

.PHONY : CMakeFiles/src.dir/build

CMakeFiles/src.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/src.dir/cmake_clean.cmake
.PHONY : CMakeFiles/src.dir/clean

CMakeFiles/src.dir/depend:
	cd /home/m0narch/Documents/Code/repo-Team16/src/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/m0narch/Documents/Code/repo-Team16/src /home/m0narch/Documents/Code/repo-Team16/src /home/m0narch/Documents/Code/repo-Team16/src/cmake-build-debug /home/m0narch/Documents/Code/repo-Team16/src/cmake-build-debug /home/m0narch/Documents/Code/repo-Team16/src/cmake-build-debug/CMakeFiles/src.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/src.dir/depend

