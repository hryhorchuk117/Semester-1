# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /snap/clion/58/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/58/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/maksimka117/CLionProjects/lab_5_new_version

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/maksimka117/CLionProjects/lab_5_new_version/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab_5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab_5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab_5.dir/flags.make

CMakeFiles/lab_5.dir/main.cpp.o: CMakeFiles/lab_5.dir/flags.make
CMakeFiles/lab_5.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maksimka117/CLionProjects/lab_5_new_version/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab_5.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab_5.dir/main.cpp.o -c /home/maksimka117/CLionProjects/lab_5_new_version/main.cpp

CMakeFiles/lab_5.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab_5.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maksimka117/CLionProjects/lab_5_new_version/main.cpp > CMakeFiles/lab_5.dir/main.cpp.i

CMakeFiles/lab_5.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab_5.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maksimka117/CLionProjects/lab_5_new_version/main.cpp -o CMakeFiles/lab_5.dir/main.cpp.s

# Object files for target lab_5
lab_5_OBJECTS = \
"CMakeFiles/lab_5.dir/main.cpp.o"

# External object files for target lab_5
lab_5_EXTERNAL_OBJECTS =

lab_5: CMakeFiles/lab_5.dir/main.cpp.o
lab_5: CMakeFiles/lab_5.dir/build.make
lab_5: CMakeFiles/lab_5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maksimka117/CLionProjects/lab_5_new_version/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab_5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab_5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab_5.dir/build: lab_5

.PHONY : CMakeFiles/lab_5.dir/build

CMakeFiles/lab_5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab_5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab_5.dir/clean

CMakeFiles/lab_5.dir/depend:
	cd /home/maksimka117/CLionProjects/lab_5_new_version/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maksimka117/CLionProjects/lab_5_new_version /home/maksimka117/CLionProjects/lab_5_new_version /home/maksimka117/CLionProjects/lab_5_new_version/cmake-build-debug /home/maksimka117/CLionProjects/lab_5_new_version/cmake-build-debug /home/maksimka117/CLionProjects/lab_5_new_version/cmake-build-debug/CMakeFiles/lab_5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab_5.dir/depend

