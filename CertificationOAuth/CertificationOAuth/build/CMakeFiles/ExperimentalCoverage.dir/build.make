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
CMAKE_SOURCE_DIR = "/Users/zhumeng/Library/Mobile Documents/com~apple~CloudDocs/个人电脑/开发/github/DemoForLearning/CertificationOAuth/CertificationOAuth"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/zhumeng/Library/Mobile Documents/com~apple~CloudDocs/个人电脑/开发/github/DemoForLearning/CertificationOAuth/CertificationOAuth/build"

# Utility rule file for ExperimentalCoverage.

# Include the progress variables for this target.
include CMakeFiles/ExperimentalCoverage.dir/progress.make

CMakeFiles/ExperimentalCoverage:
	/Applications/CMake.app/Contents/bin/ctest -D ExperimentalCoverage

ExperimentalCoverage: CMakeFiles/ExperimentalCoverage
ExperimentalCoverage: CMakeFiles/ExperimentalCoverage.dir/build.make

.PHONY : ExperimentalCoverage

# Rule to build all files generated by this target.
CMakeFiles/ExperimentalCoverage.dir/build: ExperimentalCoverage

.PHONY : CMakeFiles/ExperimentalCoverage.dir/build

CMakeFiles/ExperimentalCoverage.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ExperimentalCoverage.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ExperimentalCoverage.dir/clean

CMakeFiles/ExperimentalCoverage.dir/depend:
	cd "/Users/zhumeng/Library/Mobile Documents/com~apple~CloudDocs/个人电脑/开发/github/DemoForLearning/CertificationOAuth/CertificationOAuth/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/zhumeng/Library/Mobile Documents/com~apple~CloudDocs/个人电脑/开发/github/DemoForLearning/CertificationOAuth/CertificationOAuth" "/Users/zhumeng/Library/Mobile Documents/com~apple~CloudDocs/个人电脑/开发/github/DemoForLearning/CertificationOAuth/CertificationOAuth" "/Users/zhumeng/Library/Mobile Documents/com~apple~CloudDocs/个人电脑/开发/github/DemoForLearning/CertificationOAuth/CertificationOAuth/build" "/Users/zhumeng/Library/Mobile Documents/com~apple~CloudDocs/个人电脑/开发/github/DemoForLearning/CertificationOAuth/CertificationOAuth/build" "/Users/zhumeng/Library/Mobile Documents/com~apple~CloudDocs/个人电脑/开发/github/DemoForLearning/CertificationOAuth/CertificationOAuth/build/CMakeFiles/ExperimentalCoverage.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ExperimentalCoverage.dir/depend

