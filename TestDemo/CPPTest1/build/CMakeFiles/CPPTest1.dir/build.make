# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/zhumeng/Library/Mobile Documents/com~apple~CloudDocs/个人电脑/开发/github/DemoForLearning/TestDemo/CPPTest1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/zhumeng/Library/Mobile Documents/com~apple~CloudDocs/个人电脑/开发/github/DemoForLearning/TestDemo/CPPTest1/build"

# Include any dependencies generated for this target.
include CMakeFiles/CPPTest1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CPPTest1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CPPTest1.dir/flags.make

CMakeFiles/CPPTest1.dir/main.cpp.o: CMakeFiles/CPPTest1.dir/flags.make
CMakeFiles/CPPTest1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/zhumeng/Library/Mobile Documents/com~apple~CloudDocs/个人电脑/开发/github/DemoForLearning/TestDemo/CPPTest1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CPPTest1.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPPTest1.dir/main.cpp.o -c "/Users/zhumeng/Library/Mobile Documents/com~apple~CloudDocs/个人电脑/开发/github/DemoForLearning/TestDemo/CPPTest1/main.cpp"

CMakeFiles/CPPTest1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPPTest1.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/zhumeng/Library/Mobile Documents/com~apple~CloudDocs/个人电脑/开发/github/DemoForLearning/TestDemo/CPPTest1/main.cpp" > CMakeFiles/CPPTest1.dir/main.cpp.i

CMakeFiles/CPPTest1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPPTest1.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/zhumeng/Library/Mobile Documents/com~apple~CloudDocs/个人电脑/开发/github/DemoForLearning/TestDemo/CPPTest1/main.cpp" -o CMakeFiles/CPPTest1.dir/main.cpp.s

# Object files for target CPPTest1
CPPTest1_OBJECTS = \
"CMakeFiles/CPPTest1.dir/main.cpp.o"

# External object files for target CPPTest1
CPPTest1_EXTERNAL_OBJECTS =

CPPTest1: CMakeFiles/CPPTest1.dir/main.cpp.o
CPPTest1: CMakeFiles/CPPTest1.dir/build.make
CPPTest1: CMakeFiles/CPPTest1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/zhumeng/Library/Mobile Documents/com~apple~CloudDocs/个人电脑/开发/github/DemoForLearning/TestDemo/CPPTest1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CPPTest1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CPPTest1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CPPTest1.dir/build: CPPTest1

.PHONY : CMakeFiles/CPPTest1.dir/build

CMakeFiles/CPPTest1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CPPTest1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CPPTest1.dir/clean

CMakeFiles/CPPTest1.dir/depend:
	cd "/Users/zhumeng/Library/Mobile Documents/com~apple~CloudDocs/个人电脑/开发/github/DemoForLearning/TestDemo/CPPTest1/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/zhumeng/Library/Mobile Documents/com~apple~CloudDocs/个人电脑/开发/github/DemoForLearning/TestDemo/CPPTest1" "/Users/zhumeng/Library/Mobile Documents/com~apple~CloudDocs/个人电脑/开发/github/DemoForLearning/TestDemo/CPPTest1" "/Users/zhumeng/Library/Mobile Documents/com~apple~CloudDocs/个人电脑/开发/github/DemoForLearning/TestDemo/CPPTest1/build" "/Users/zhumeng/Library/Mobile Documents/com~apple~CloudDocs/个人电脑/开发/github/DemoForLearning/TestDemo/CPPTest1/build" "/Users/zhumeng/Library/Mobile Documents/com~apple~CloudDocs/个人电脑/开发/github/DemoForLearning/TestDemo/CPPTest1/build/CMakeFiles/CPPTest1.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/CPPTest1.dir/depend

