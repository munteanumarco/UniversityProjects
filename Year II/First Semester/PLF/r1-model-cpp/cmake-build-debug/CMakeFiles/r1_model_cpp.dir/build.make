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
CMAKE_COMMAND = C:\Users\Marco\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\203.7148.70\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Marco\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\203.7148.70\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\University\UniversityProjects\Year II\PLF\r1-model-cpp"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\University\UniversityProjects\Year II\PLF\r1-model-cpp\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/r1_model_cpp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/r1_model_cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/r1_model_cpp.dir/flags.make

CMakeFiles/r1_model_cpp.dir/lista.cpp.obj: CMakeFiles/r1_model_cpp.dir/flags.make
CMakeFiles/r1_model_cpp.dir/lista.cpp.obj: CMakeFiles/r1_model_cpp.dir/includes_CXX.rsp
CMakeFiles/r1_model_cpp.dir/lista.cpp.obj: ../lista.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\University\UniversityProjects\Year II\PLF\r1-model-cpp\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/r1_model_cpp.dir/lista.cpp.obj"
	C:\MinGW\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\r1_model_cpp.dir\lista.cpp.obj -c "C:\University\UniversityProjects\Year II\PLF\r1-model-cpp\lista.cpp"

CMakeFiles/r1_model_cpp.dir/lista.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/r1_model_cpp.dir/lista.cpp.i"
	C:\MinGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\University\UniversityProjects\Year II\PLF\r1-model-cpp\lista.cpp" > CMakeFiles\r1_model_cpp.dir\lista.cpp.i

CMakeFiles/r1_model_cpp.dir/lista.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/r1_model_cpp.dir/lista.cpp.s"
	C:\MinGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\University\UniversityProjects\Year II\PLF\r1-model-cpp\lista.cpp" -o CMakeFiles\r1_model_cpp.dir\lista.cpp.s

CMakeFiles/r1_model_cpp.dir/main.cpp.obj: CMakeFiles/r1_model_cpp.dir/flags.make
CMakeFiles/r1_model_cpp.dir/main.cpp.obj: CMakeFiles/r1_model_cpp.dir/includes_CXX.rsp
CMakeFiles/r1_model_cpp.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\University\UniversityProjects\Year II\PLF\r1-model-cpp\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/r1_model_cpp.dir/main.cpp.obj"
	C:\MinGW\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\r1_model_cpp.dir\main.cpp.obj -c "C:\University\UniversityProjects\Year II\PLF\r1-model-cpp\main.cpp"

CMakeFiles/r1_model_cpp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/r1_model_cpp.dir/main.cpp.i"
	C:\MinGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\University\UniversityProjects\Year II\PLF\r1-model-cpp\main.cpp" > CMakeFiles\r1_model_cpp.dir\main.cpp.i

CMakeFiles/r1_model_cpp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/r1_model_cpp.dir/main.cpp.s"
	C:\MinGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\University\UniversityProjects\Year II\PLF\r1-model-cpp\main.cpp" -o CMakeFiles\r1_model_cpp.dir\main.cpp.s

# Object files for target r1_model_cpp
r1_model_cpp_OBJECTS = \
"CMakeFiles/r1_model_cpp.dir/lista.cpp.obj" \
"CMakeFiles/r1_model_cpp.dir/main.cpp.obj"

# External object files for target r1_model_cpp
r1_model_cpp_EXTERNAL_OBJECTS =

r1_model_cpp.exe: CMakeFiles/r1_model_cpp.dir/lista.cpp.obj
r1_model_cpp.exe: CMakeFiles/r1_model_cpp.dir/main.cpp.obj
r1_model_cpp.exe: CMakeFiles/r1_model_cpp.dir/build.make
r1_model_cpp.exe: CMakeFiles/r1_model_cpp.dir/linklibs.rsp
r1_model_cpp.exe: CMakeFiles/r1_model_cpp.dir/objects1.rsp
r1_model_cpp.exe: CMakeFiles/r1_model_cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\University\UniversityProjects\Year II\PLF\r1-model-cpp\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable r1_model_cpp.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\r1_model_cpp.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/r1_model_cpp.dir/build: r1_model_cpp.exe

.PHONY : CMakeFiles/r1_model_cpp.dir/build

CMakeFiles/r1_model_cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\r1_model_cpp.dir\cmake_clean.cmake
.PHONY : CMakeFiles/r1_model_cpp.dir/clean

CMakeFiles/r1_model_cpp.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\University\UniversityProjects\Year II\PLF\r1-model-cpp" "C:\University\UniversityProjects\Year II\PLF\r1-model-cpp" "C:\University\UniversityProjects\Year II\PLF\r1-model-cpp\cmake-build-debug" "C:\University\UniversityProjects\Year II\PLF\r1-model-cpp\cmake-build-debug" "C:\University\UniversityProjects\Year II\PLF\r1-model-cpp\cmake-build-debug\CMakeFiles\r1_model_cpp.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/r1_model_cpp.dir/depend
