# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /home/mxc/下载/clion-2017.1.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/mxc/下载/clion-2017.1.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mxc/CLionProjects/FirstAIFramework

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mxc/CLionProjects/FirstAIFramework/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/FirstAIFramework.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FirstAIFramework.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FirstAIFramework.dir/flags.make

CMakeFiles/FirstAIFramework.dir/main.cpp.o: CMakeFiles/FirstAIFramework.dir/flags.make
CMakeFiles/FirstAIFramework.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mxc/CLionProjects/FirstAIFramework/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FirstAIFramework.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FirstAIFramework.dir/main.cpp.o -c /home/mxc/CLionProjects/FirstAIFramework/main.cpp

CMakeFiles/FirstAIFramework.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FirstAIFramework.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mxc/CLionProjects/FirstAIFramework/main.cpp > CMakeFiles/FirstAIFramework.dir/main.cpp.i

CMakeFiles/FirstAIFramework.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FirstAIFramework.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mxc/CLionProjects/FirstAIFramework/main.cpp -o CMakeFiles/FirstAIFramework.dir/main.cpp.s

CMakeFiles/FirstAIFramework.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/FirstAIFramework.dir/main.cpp.o.requires

CMakeFiles/FirstAIFramework.dir/main.cpp.o.provides: CMakeFiles/FirstAIFramework.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/FirstAIFramework.dir/build.make CMakeFiles/FirstAIFramework.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/FirstAIFramework.dir/main.cpp.o.provides

CMakeFiles/FirstAIFramework.dir/main.cpp.o.provides.build: CMakeFiles/FirstAIFramework.dir/main.cpp.o


CMakeFiles/FirstAIFramework.dir/src/TestHello.cpp.o: CMakeFiles/FirstAIFramework.dir/flags.make
CMakeFiles/FirstAIFramework.dir/src/TestHello.cpp.o: ../src/TestHello.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mxc/CLionProjects/FirstAIFramework/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/FirstAIFramework.dir/src/TestHello.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FirstAIFramework.dir/src/TestHello.cpp.o -c /home/mxc/CLionProjects/FirstAIFramework/src/TestHello.cpp

CMakeFiles/FirstAIFramework.dir/src/TestHello.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FirstAIFramework.dir/src/TestHello.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mxc/CLionProjects/FirstAIFramework/src/TestHello.cpp > CMakeFiles/FirstAIFramework.dir/src/TestHello.cpp.i

CMakeFiles/FirstAIFramework.dir/src/TestHello.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FirstAIFramework.dir/src/TestHello.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mxc/CLionProjects/FirstAIFramework/src/TestHello.cpp -o CMakeFiles/FirstAIFramework.dir/src/TestHello.cpp.s

CMakeFiles/FirstAIFramework.dir/src/TestHello.cpp.o.requires:

.PHONY : CMakeFiles/FirstAIFramework.dir/src/TestHello.cpp.o.requires

CMakeFiles/FirstAIFramework.dir/src/TestHello.cpp.o.provides: CMakeFiles/FirstAIFramework.dir/src/TestHello.cpp.o.requires
	$(MAKE) -f CMakeFiles/FirstAIFramework.dir/build.make CMakeFiles/FirstAIFramework.dir/src/TestHello.cpp.o.provides.build
.PHONY : CMakeFiles/FirstAIFramework.dir/src/TestHello.cpp.o.provides

CMakeFiles/FirstAIFramework.dir/src/TestHello.cpp.o.provides.build: CMakeFiles/FirstAIFramework.dir/src/TestHello.cpp.o


# Object files for target FirstAIFramework
FirstAIFramework_OBJECTS = \
"CMakeFiles/FirstAIFramework.dir/main.cpp.o" \
"CMakeFiles/FirstAIFramework.dir/src/TestHello.cpp.o"

# External object files for target FirstAIFramework
FirstAIFramework_EXTERNAL_OBJECTS =

FirstAIFramework: CMakeFiles/FirstAIFramework.dir/main.cpp.o
FirstAIFramework: CMakeFiles/FirstAIFramework.dir/src/TestHello.cpp.o
FirstAIFramework: CMakeFiles/FirstAIFramework.dir/build.make
FirstAIFramework: /usr/local/protobuf/lib/libprotobuf.so
FirstAIFramework: CMakeFiles/FirstAIFramework.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mxc/CLionProjects/FirstAIFramework/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable FirstAIFramework"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FirstAIFramework.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FirstAIFramework.dir/build: FirstAIFramework

.PHONY : CMakeFiles/FirstAIFramework.dir/build

CMakeFiles/FirstAIFramework.dir/requires: CMakeFiles/FirstAIFramework.dir/main.cpp.o.requires
CMakeFiles/FirstAIFramework.dir/requires: CMakeFiles/FirstAIFramework.dir/src/TestHello.cpp.o.requires

.PHONY : CMakeFiles/FirstAIFramework.dir/requires

CMakeFiles/FirstAIFramework.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FirstAIFramework.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FirstAIFramework.dir/clean

CMakeFiles/FirstAIFramework.dir/depend:
	cd /home/mxc/CLionProjects/FirstAIFramework/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mxc/CLionProjects/FirstAIFramework /home/mxc/CLionProjects/FirstAIFramework /home/mxc/CLionProjects/FirstAIFramework/cmake-build-debug /home/mxc/CLionProjects/FirstAIFramework/cmake-build-debug /home/mxc/CLionProjects/FirstAIFramework/cmake-build-debug/CMakeFiles/FirstAIFramework.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FirstAIFramework.dir/depend

