# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/runner/work/peach/peach

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/runner/work/peach/peach/build

# Include any dependencies generated for this target.
include gui/CMakeFiles/gui.dir/depend.make

# Include the progress variables for this target.
include gui/CMakeFiles/gui.dir/progress.make

# Include the compile flags for this target's objects.
include gui/CMakeFiles/gui.dir/flags.make

gui/qrc_qml.cpp: ../resources/layout/main.qml
gui/qrc_qml.cpp: ../resources/layout/qml.qrc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/runner/work/peach/peach/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating qrc_qml.cpp"
	cd /home/runner/work/peach/peach/build/gui && /usr/lib/qt5/bin/rcc --name qml --output /home/runner/work/peach/peach/build/gui/qrc_qml.cpp /home/runner/work/peach/peach/resources/layout/qml.qrc

gui/CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.o: gui/CMakeFiles/gui.dir/flags.make
gui/CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.o: gui/gui_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/peach/peach/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object gui/CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.o"
	cd /home/runner/work/peach/peach/build/gui && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.o -c /home/runner/work/peach/peach/build/gui/gui_autogen/mocs_compilation.cpp

gui/CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.i"
	cd /home/runner/work/peach/peach/build/gui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/work/peach/peach/build/gui/gui_autogen/mocs_compilation.cpp > CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.i

gui/CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.s"
	cd /home/runner/work/peach/peach/build/gui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/work/peach/peach/build/gui/gui_autogen/mocs_compilation.cpp -o CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.s

gui/CMakeFiles/gui.dir/execute.cpp.o: gui/CMakeFiles/gui.dir/flags.make
gui/CMakeFiles/gui.dir/execute.cpp.o: ../gui/execute.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/peach/peach/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object gui/CMakeFiles/gui.dir/execute.cpp.o"
	cd /home/runner/work/peach/peach/build/gui && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gui.dir/execute.cpp.o -c /home/runner/work/peach/peach/gui/execute.cpp

gui/CMakeFiles/gui.dir/execute.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gui.dir/execute.cpp.i"
	cd /home/runner/work/peach/peach/build/gui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/work/peach/peach/gui/execute.cpp > CMakeFiles/gui.dir/execute.cpp.i

gui/CMakeFiles/gui.dir/execute.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gui.dir/execute.cpp.s"
	cd /home/runner/work/peach/peach/build/gui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/work/peach/peach/gui/execute.cpp -o CMakeFiles/gui.dir/execute.cpp.s

gui/CMakeFiles/gui.dir/qrc_qml.cpp.o: gui/CMakeFiles/gui.dir/flags.make
gui/CMakeFiles/gui.dir/qrc_qml.cpp.o: gui/qrc_qml.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/peach/peach/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object gui/CMakeFiles/gui.dir/qrc_qml.cpp.o"
	cd /home/runner/work/peach/peach/build/gui && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gui.dir/qrc_qml.cpp.o -c /home/runner/work/peach/peach/build/gui/qrc_qml.cpp

gui/CMakeFiles/gui.dir/qrc_qml.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gui.dir/qrc_qml.cpp.i"
	cd /home/runner/work/peach/peach/build/gui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/work/peach/peach/build/gui/qrc_qml.cpp > CMakeFiles/gui.dir/qrc_qml.cpp.i

gui/CMakeFiles/gui.dir/qrc_qml.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gui.dir/qrc_qml.cpp.s"
	cd /home/runner/work/peach/peach/build/gui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/work/peach/peach/build/gui/qrc_qml.cpp -o CMakeFiles/gui.dir/qrc_qml.cpp.s

gui/CMakeFiles/gui.dir/Interface/Gui.cpp.o: gui/CMakeFiles/gui.dir/flags.make
gui/CMakeFiles/gui.dir/Interface/Gui.cpp.o: ../gui/Interface/Gui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/peach/peach/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object gui/CMakeFiles/gui.dir/Interface/Gui.cpp.o"
	cd /home/runner/work/peach/peach/build/gui && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gui.dir/Interface/Gui.cpp.o -c /home/runner/work/peach/peach/gui/Interface/Gui.cpp

gui/CMakeFiles/gui.dir/Interface/Gui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gui.dir/Interface/Gui.cpp.i"
	cd /home/runner/work/peach/peach/build/gui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/work/peach/peach/gui/Interface/Gui.cpp > CMakeFiles/gui.dir/Interface/Gui.cpp.i

gui/CMakeFiles/gui.dir/Interface/Gui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gui.dir/Interface/Gui.cpp.s"
	cd /home/runner/work/peach/peach/build/gui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/work/peach/peach/gui/Interface/Gui.cpp -o CMakeFiles/gui.dir/Interface/Gui.cpp.s

gui/CMakeFiles/gui.dir/Interface/GUICommands/GUICommand.cpp.o: gui/CMakeFiles/gui.dir/flags.make
gui/CMakeFiles/gui.dir/Interface/GUICommands/GUICommand.cpp.o: ../gui/Interface/GUICommands/GUICommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/peach/peach/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object gui/CMakeFiles/gui.dir/Interface/GUICommands/GUICommand.cpp.o"
	cd /home/runner/work/peach/peach/build/gui && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gui.dir/Interface/GUICommands/GUICommand.cpp.o -c /home/runner/work/peach/peach/gui/Interface/GUICommands/GUICommand.cpp

gui/CMakeFiles/gui.dir/Interface/GUICommands/GUICommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gui.dir/Interface/GUICommands/GUICommand.cpp.i"
	cd /home/runner/work/peach/peach/build/gui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/work/peach/peach/gui/Interface/GUICommands/GUICommand.cpp > CMakeFiles/gui.dir/Interface/GUICommands/GUICommand.cpp.i

gui/CMakeFiles/gui.dir/Interface/GUICommands/GUICommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gui.dir/Interface/GUICommands/GUICommand.cpp.s"
	cd /home/runner/work/peach/peach/build/gui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/work/peach/peach/gui/Interface/GUICommands/GUICommand.cpp -o CMakeFiles/gui.dir/Interface/GUICommands/GUICommand.cpp.s

gui/CMakeFiles/gui.dir/Interface/GUICommands/MutateCommand.cpp.o: gui/CMakeFiles/gui.dir/flags.make
gui/CMakeFiles/gui.dir/Interface/GUICommands/MutateCommand.cpp.o: ../gui/Interface/GUICommands/MutateCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/peach/peach/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object gui/CMakeFiles/gui.dir/Interface/GUICommands/MutateCommand.cpp.o"
	cd /home/runner/work/peach/peach/build/gui && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gui.dir/Interface/GUICommands/MutateCommand.cpp.o -c /home/runner/work/peach/peach/gui/Interface/GUICommands/MutateCommand.cpp

gui/CMakeFiles/gui.dir/Interface/GUICommands/MutateCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gui.dir/Interface/GUICommands/MutateCommand.cpp.i"
	cd /home/runner/work/peach/peach/build/gui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/work/peach/peach/gui/Interface/GUICommands/MutateCommand.cpp > CMakeFiles/gui.dir/Interface/GUICommands/MutateCommand.cpp.i

gui/CMakeFiles/gui.dir/Interface/GUICommands/MutateCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gui.dir/Interface/GUICommands/MutateCommand.cpp.s"
	cd /home/runner/work/peach/peach/build/gui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/work/peach/peach/gui/Interface/GUICommands/MutateCommand.cpp -o CMakeFiles/gui.dir/Interface/GUICommands/MutateCommand.cpp.s

gui/CMakeFiles/gui.dir/Interface/GUICommands/SplitCommand.cpp.o: gui/CMakeFiles/gui.dir/flags.make
gui/CMakeFiles/gui.dir/Interface/GUICommands/SplitCommand.cpp.o: ../gui/Interface/GUICommands/SplitCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/peach/peach/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object gui/CMakeFiles/gui.dir/Interface/GUICommands/SplitCommand.cpp.o"
	cd /home/runner/work/peach/peach/build/gui && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gui.dir/Interface/GUICommands/SplitCommand.cpp.o -c /home/runner/work/peach/peach/gui/Interface/GUICommands/SplitCommand.cpp

gui/CMakeFiles/gui.dir/Interface/GUICommands/SplitCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gui.dir/Interface/GUICommands/SplitCommand.cpp.i"
	cd /home/runner/work/peach/peach/build/gui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/work/peach/peach/gui/Interface/GUICommands/SplitCommand.cpp > CMakeFiles/gui.dir/Interface/GUICommands/SplitCommand.cpp.i

gui/CMakeFiles/gui.dir/Interface/GUICommands/SplitCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gui.dir/Interface/GUICommands/SplitCommand.cpp.s"
	cd /home/runner/work/peach/peach/build/gui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/work/peach/peach/gui/Interface/GUICommands/SplitCommand.cpp -o CMakeFiles/gui.dir/Interface/GUICommands/SplitCommand.cpp.s

gui/CMakeFiles/gui.dir/Interface/GUICommands/MoveCommand.cpp.o: gui/CMakeFiles/gui.dir/flags.make
gui/CMakeFiles/gui.dir/Interface/GUICommands/MoveCommand.cpp.o: ../gui/Interface/GUICommands/MoveCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/peach/peach/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object gui/CMakeFiles/gui.dir/Interface/GUICommands/MoveCommand.cpp.o"
	cd /home/runner/work/peach/peach/build/gui && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gui.dir/Interface/GUICommands/MoveCommand.cpp.o -c /home/runner/work/peach/peach/gui/Interface/GUICommands/MoveCommand.cpp

gui/CMakeFiles/gui.dir/Interface/GUICommands/MoveCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gui.dir/Interface/GUICommands/MoveCommand.cpp.i"
	cd /home/runner/work/peach/peach/build/gui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/work/peach/peach/gui/Interface/GUICommands/MoveCommand.cpp > CMakeFiles/gui.dir/Interface/GUICommands/MoveCommand.cpp.i

gui/CMakeFiles/gui.dir/Interface/GUICommands/MoveCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gui.dir/Interface/GUICommands/MoveCommand.cpp.s"
	cd /home/runner/work/peach/peach/build/gui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/work/peach/peach/gui/Interface/GUICommands/MoveCommand.cpp -o CMakeFiles/gui.dir/Interface/GUICommands/MoveCommand.cpp.s

gui/CMakeFiles/gui.dir/Interface/GUICommands/StopCommand.cpp.o: gui/CMakeFiles/gui.dir/flags.make
gui/CMakeFiles/gui.dir/Interface/GUICommands/StopCommand.cpp.o: ../gui/Interface/GUICommands/StopCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/peach/peach/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object gui/CMakeFiles/gui.dir/Interface/GUICommands/StopCommand.cpp.o"
	cd /home/runner/work/peach/peach/build/gui && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gui.dir/Interface/GUICommands/StopCommand.cpp.o -c /home/runner/work/peach/peach/gui/Interface/GUICommands/StopCommand.cpp

gui/CMakeFiles/gui.dir/Interface/GUICommands/StopCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gui.dir/Interface/GUICommands/StopCommand.cpp.i"
	cd /home/runner/work/peach/peach/build/gui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/work/peach/peach/gui/Interface/GUICommands/StopCommand.cpp > CMakeFiles/gui.dir/Interface/GUICommands/StopCommand.cpp.i

gui/CMakeFiles/gui.dir/Interface/GUICommands/StopCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gui.dir/Interface/GUICommands/StopCommand.cpp.s"
	cd /home/runner/work/peach/peach/build/gui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/work/peach/peach/gui/Interface/GUICommands/StopCommand.cpp -o CMakeFiles/gui.dir/Interface/GUICommands/StopCommand.cpp.s

gui/CMakeFiles/gui.dir/Interface/Models/PlayerScoreModel.cpp.o: gui/CMakeFiles/gui.dir/flags.make
gui/CMakeFiles/gui.dir/Interface/Models/PlayerScoreModel.cpp.o: ../gui/Interface/Models/PlayerScoreModel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/peach/peach/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object gui/CMakeFiles/gui.dir/Interface/Models/PlayerScoreModel.cpp.o"
	cd /home/runner/work/peach/peach/build/gui && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gui.dir/Interface/Models/PlayerScoreModel.cpp.o -c /home/runner/work/peach/peach/gui/Interface/Models/PlayerScoreModel.cpp

gui/CMakeFiles/gui.dir/Interface/Models/PlayerScoreModel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gui.dir/Interface/Models/PlayerScoreModel.cpp.i"
	cd /home/runner/work/peach/peach/build/gui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/work/peach/peach/gui/Interface/Models/PlayerScoreModel.cpp > CMakeFiles/gui.dir/Interface/Models/PlayerScoreModel.cpp.i

gui/CMakeFiles/gui.dir/Interface/Models/PlayerScoreModel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gui.dir/Interface/Models/PlayerScoreModel.cpp.s"
	cd /home/runner/work/peach/peach/build/gui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/work/peach/peach/gui/Interface/Models/PlayerScoreModel.cpp -o CMakeFiles/gui.dir/Interface/Models/PlayerScoreModel.cpp.s

# Object files for target gui
gui_OBJECTS = \
"CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/gui.dir/execute.cpp.o" \
"CMakeFiles/gui.dir/qrc_qml.cpp.o" \
"CMakeFiles/gui.dir/Interface/Gui.cpp.o" \
"CMakeFiles/gui.dir/Interface/GUICommands/GUICommand.cpp.o" \
"CMakeFiles/gui.dir/Interface/GUICommands/MutateCommand.cpp.o" \
"CMakeFiles/gui.dir/Interface/GUICommands/SplitCommand.cpp.o" \
"CMakeFiles/gui.dir/Interface/GUICommands/MoveCommand.cpp.o" \
"CMakeFiles/gui.dir/Interface/GUICommands/StopCommand.cpp.o" \
"CMakeFiles/gui.dir/Interface/Models/PlayerScoreModel.cpp.o"

# External object files for target gui
gui_EXTERNAL_OBJECTS =

bin/gui: gui/CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.o
bin/gui: gui/CMakeFiles/gui.dir/execute.cpp.o
bin/gui: gui/CMakeFiles/gui.dir/qrc_qml.cpp.o
bin/gui: gui/CMakeFiles/gui.dir/Interface/Gui.cpp.o
bin/gui: gui/CMakeFiles/gui.dir/Interface/GUICommands/GUICommand.cpp.o
bin/gui: gui/CMakeFiles/gui.dir/Interface/GUICommands/MutateCommand.cpp.o
bin/gui: gui/CMakeFiles/gui.dir/Interface/GUICommands/SplitCommand.cpp.o
bin/gui: gui/CMakeFiles/gui.dir/Interface/GUICommands/MoveCommand.cpp.o
bin/gui: gui/CMakeFiles/gui.dir/Interface/GUICommands/StopCommand.cpp.o
bin/gui: gui/CMakeFiles/gui.dir/Interface/Models/PlayerScoreModel.cpp.o
bin/gui: gui/CMakeFiles/gui.dir/build.make
bin/gui: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.9.5
bin/gui: /usr/lib/x86_64-linux-gnu/libQt5Quick.so.5.9.5
bin/gui: lib/libsrc.so
bin/gui: /usr/lib/x86_64-linux-gnu/libQt5Qml.so.5.9.5
bin/gui: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.9.5
bin/gui: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.9.5
bin/gui: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.9.5
bin/gui: gui/CMakeFiles/gui.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/runner/work/peach/peach/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable ../bin/gui"
	cd /home/runner/work/peach/peach/build/gui && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gui.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
gui/CMakeFiles/gui.dir/build: bin/gui

.PHONY : gui/CMakeFiles/gui.dir/build

gui/CMakeFiles/gui.dir/clean:
	cd /home/runner/work/peach/peach/build/gui && $(CMAKE_COMMAND) -P CMakeFiles/gui.dir/cmake_clean.cmake
.PHONY : gui/CMakeFiles/gui.dir/clean

gui/CMakeFiles/gui.dir/depend: gui/qrc_qml.cpp
	cd /home/runner/work/peach/peach/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/runner/work/peach/peach /home/runner/work/peach/peach/gui /home/runner/work/peach/peach/build /home/runner/work/peach/peach/build/gui /home/runner/work/peach/peach/build/gui/CMakeFiles/gui.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : gui/CMakeFiles/gui.dir/depend

