# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_SOURCE_DIR = /root/cs210

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/cs210/build

# Include any dependencies generated for this target.
include CMakeFiles/ps5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ps5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ps5.dir/flags.make

CMakeFiles/ps5.dir/main.c.o: CMakeFiles/ps5.dir/flags.make
CMakeFiles/ps5.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/cs210/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ps5.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ps5.dir/main.c.o   -c /root/cs210/main.c

CMakeFiles/ps5.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ps5.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /root/cs210/main.c > CMakeFiles/ps5.dir/main.c.i

CMakeFiles/ps5.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ps5.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /root/cs210/main.c -o CMakeFiles/ps5.dir/main.c.s

CMakeFiles/ps5.dir/rpn.c.o: CMakeFiles/ps5.dir/flags.make
CMakeFiles/ps5.dir/rpn.c.o: ../rpn.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/cs210/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ps5.dir/rpn.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ps5.dir/rpn.c.o   -c /root/cs210/rpn.c

CMakeFiles/ps5.dir/rpn.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ps5.dir/rpn.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /root/cs210/rpn.c > CMakeFiles/ps5.dir/rpn.c.i

CMakeFiles/ps5.dir/rpn.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ps5.dir/rpn.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /root/cs210/rpn.c -o CMakeFiles/ps5.dir/rpn.c.s

CMakeFiles/ps5.dir/node.c.o: CMakeFiles/ps5.dir/flags.make
CMakeFiles/ps5.dir/node.c.o: ../node.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/cs210/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ps5.dir/node.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ps5.dir/node.c.o   -c /root/cs210/node.c

CMakeFiles/ps5.dir/node.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ps5.dir/node.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /root/cs210/node.c > CMakeFiles/ps5.dir/node.c.i

CMakeFiles/ps5.dir/node.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ps5.dir/node.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /root/cs210/node.c -o CMakeFiles/ps5.dir/node.c.s

CMakeFiles/ps5.dir/stack.c.o: CMakeFiles/ps5.dir/flags.make
CMakeFiles/ps5.dir/stack.c.o: ../stack.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/cs210/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/ps5.dir/stack.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ps5.dir/stack.c.o   -c /root/cs210/stack.c

CMakeFiles/ps5.dir/stack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ps5.dir/stack.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /root/cs210/stack.c > CMakeFiles/ps5.dir/stack.c.i

CMakeFiles/ps5.dir/stack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ps5.dir/stack.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /root/cs210/stack.c -o CMakeFiles/ps5.dir/stack.c.s

CMakeFiles/ps5.dir/errors.c.o: CMakeFiles/ps5.dir/flags.make
CMakeFiles/ps5.dir/errors.c.o: ../errors.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/cs210/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/ps5.dir/errors.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ps5.dir/errors.c.o   -c /root/cs210/errors.c

CMakeFiles/ps5.dir/errors.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ps5.dir/errors.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /root/cs210/errors.c > CMakeFiles/ps5.dir/errors.c.i

CMakeFiles/ps5.dir/errors.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ps5.dir/errors.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /root/cs210/errors.c -o CMakeFiles/ps5.dir/errors.c.s

# Object files for target ps5
ps5_OBJECTS = \
"CMakeFiles/ps5.dir/main.c.o" \
"CMakeFiles/ps5.dir/rpn.c.o" \
"CMakeFiles/ps5.dir/node.c.o" \
"CMakeFiles/ps5.dir/stack.c.o" \
"CMakeFiles/ps5.dir/errors.c.o"

# External object files for target ps5
ps5_EXTERNAL_OBJECTS =

ps5: CMakeFiles/ps5.dir/main.c.o
ps5: CMakeFiles/ps5.dir/rpn.c.o
ps5: CMakeFiles/ps5.dir/node.c.o
ps5: CMakeFiles/ps5.dir/stack.c.o
ps5: CMakeFiles/ps5.dir/errors.c.o
ps5: CMakeFiles/ps5.dir/build.make
ps5: CMakeFiles/ps5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/cs210/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable ps5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ps5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ps5.dir/build: ps5

.PHONY : CMakeFiles/ps5.dir/build

CMakeFiles/ps5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ps5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ps5.dir/clean

CMakeFiles/ps5.dir/depend:
	cd /root/cs210/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/cs210 /root/cs210 /root/cs210/build /root/cs210/build /root/cs210/build/CMakeFiles/ps5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ps5.dir/depend

