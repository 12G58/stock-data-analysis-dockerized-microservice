# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/free/data-analytics-microservice

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/free/data-analytics-microservice

# Include any dependencies generated for this target.
include CMakeFiles/data-analytics-microservice.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/data-analytics-microservice.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/data-analytics-microservice.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/data-analytics-microservice.dir/flags.make

CMakeFiles/data-analytics-microservice.dir/codegen:
.PHONY : CMakeFiles/data-analytics-microservice.dir/codegen

CMakeFiles/data-analytics-microservice.dir/src/main.cpp.o: CMakeFiles/data-analytics-microservice.dir/flags.make
CMakeFiles/data-analytics-microservice.dir/src/main.cpp.o: src/main.cpp
CMakeFiles/data-analytics-microservice.dir/src/main.cpp.o: CMakeFiles/data-analytics-microservice.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/free/data-analytics-microservice/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/data-analytics-microservice.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/data-analytics-microservice.dir/src/main.cpp.o -MF CMakeFiles/data-analytics-microservice.dir/src/main.cpp.o.d -o CMakeFiles/data-analytics-microservice.dir/src/main.cpp.o -c /home/free/data-analytics-microservice/src/main.cpp

CMakeFiles/data-analytics-microservice.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/data-analytics-microservice.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/free/data-analytics-microservice/src/main.cpp > CMakeFiles/data-analytics-microservice.dir/src/main.cpp.i

CMakeFiles/data-analytics-microservice.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/data-analytics-microservice.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/free/data-analytics-microservice/src/main.cpp -o CMakeFiles/data-analytics-microservice.dir/src/main.cpp.s

CMakeFiles/data-analytics-microservice.dir/src/data_fetcher.cpp.o: CMakeFiles/data-analytics-microservice.dir/flags.make
CMakeFiles/data-analytics-microservice.dir/src/data_fetcher.cpp.o: src/data_fetcher.cpp
CMakeFiles/data-analytics-microservice.dir/src/data_fetcher.cpp.o: CMakeFiles/data-analytics-microservice.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/free/data-analytics-microservice/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/data-analytics-microservice.dir/src/data_fetcher.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/data-analytics-microservice.dir/src/data_fetcher.cpp.o -MF CMakeFiles/data-analytics-microservice.dir/src/data_fetcher.cpp.o.d -o CMakeFiles/data-analytics-microservice.dir/src/data_fetcher.cpp.o -c /home/free/data-analytics-microservice/src/data_fetcher.cpp

CMakeFiles/data-analytics-microservice.dir/src/data_fetcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/data-analytics-microservice.dir/src/data_fetcher.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/free/data-analytics-microservice/src/data_fetcher.cpp > CMakeFiles/data-analytics-microservice.dir/src/data_fetcher.cpp.i

CMakeFiles/data-analytics-microservice.dir/src/data_fetcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/data-analytics-microservice.dir/src/data_fetcher.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/free/data-analytics-microservice/src/data_fetcher.cpp -o CMakeFiles/data-analytics-microservice.dir/src/data_fetcher.cpp.s

CMakeFiles/data-analytics-microservice.dir/src/data_processor.cpp.o: CMakeFiles/data-analytics-microservice.dir/flags.make
CMakeFiles/data-analytics-microservice.dir/src/data_processor.cpp.o: src/data_processor.cpp
CMakeFiles/data-analytics-microservice.dir/src/data_processor.cpp.o: CMakeFiles/data-analytics-microservice.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/free/data-analytics-microservice/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/data-analytics-microservice.dir/src/data_processor.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/data-analytics-microservice.dir/src/data_processor.cpp.o -MF CMakeFiles/data-analytics-microservice.dir/src/data_processor.cpp.o.d -o CMakeFiles/data-analytics-microservice.dir/src/data_processor.cpp.o -c /home/free/data-analytics-microservice/src/data_processor.cpp

CMakeFiles/data-analytics-microservice.dir/src/data_processor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/data-analytics-microservice.dir/src/data_processor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/free/data-analytics-microservice/src/data_processor.cpp > CMakeFiles/data-analytics-microservice.dir/src/data_processor.cpp.i

CMakeFiles/data-analytics-microservice.dir/src/data_processor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/data-analytics-microservice.dir/src/data_processor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/free/data-analytics-microservice/src/data_processor.cpp -o CMakeFiles/data-analytics-microservice.dir/src/data_processor.cpp.s

# Object files for target data-analytics-microservice
data__analytics__microservice_OBJECTS = \
"CMakeFiles/data-analytics-microservice.dir/src/main.cpp.o" \
"CMakeFiles/data-analytics-microservice.dir/src/data_fetcher.cpp.o" \
"CMakeFiles/data-analytics-microservice.dir/src/data_processor.cpp.o"

# External object files for target data-analytics-microservice
data__analytics__microservice_EXTERNAL_OBJECTS =

data-analytics-microservice: CMakeFiles/data-analytics-microservice.dir/src/main.cpp.o
data-analytics-microservice: CMakeFiles/data-analytics-microservice.dir/src/data_fetcher.cpp.o
data-analytics-microservice: CMakeFiles/data-analytics-microservice.dir/src/data_processor.cpp.o
data-analytics-microservice: CMakeFiles/data-analytics-microservice.dir/build.make
data-analytics-microservice: CMakeFiles/data-analytics-microservice.dir/compiler_depend.ts
data-analytics-microservice: CMakeFiles/data-analytics-microservice.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/free/data-analytics-microservice/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable data-analytics-microservice"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/data-analytics-microservice.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/data-analytics-microservice.dir/build: data-analytics-microservice
.PHONY : CMakeFiles/data-analytics-microservice.dir/build

CMakeFiles/data-analytics-microservice.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/data-analytics-microservice.dir/cmake_clean.cmake
.PHONY : CMakeFiles/data-analytics-microservice.dir/clean

CMakeFiles/data-analytics-microservice.dir/depend:
	cd /home/free/data-analytics-microservice && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/free/data-analytics-microservice /home/free/data-analytics-microservice /home/free/data-analytics-microservice /home/free/data-analytics-microservice /home/free/data-analytics-microservice/CMakeFiles/data-analytics-microservice.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/data-analytics-microservice.dir/depend

