# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/wenhou/cmake-3.8.2-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /home/wenhou/cmake-3.8.2-Linux-x86_64/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wenhou/eaif4_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wenhou/eaif4_ws/build

# Include any dependencies generated for this target.
include hector_slam/hector_geotiff_plugins/CMakeFiles/hector_geotiff_plugins.dir/depend.make

# Include the progress variables for this target.
include hector_slam/hector_geotiff_plugins/CMakeFiles/hector_geotiff_plugins.dir/progress.make

# Include the compile flags for this target's objects.
include hector_slam/hector_geotiff_plugins/CMakeFiles/hector_geotiff_plugins.dir/flags.make

hector_slam/hector_geotiff_plugins/CMakeFiles/hector_geotiff_plugins.dir/src/trajectory_geotiff_plugin.cpp.o: hector_slam/hector_geotiff_plugins/CMakeFiles/hector_geotiff_plugins.dir/flags.make
hector_slam/hector_geotiff_plugins/CMakeFiles/hector_geotiff_plugins.dir/src/trajectory_geotiff_plugin.cpp.o: /home/wenhou/eaif4_ws/src/hector_slam/hector_geotiff_plugins/src/trajectory_geotiff_plugin.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wenhou/eaif4_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object hector_slam/hector_geotiff_plugins/CMakeFiles/hector_geotiff_plugins.dir/src/trajectory_geotiff_plugin.cpp.o"
	cd /home/wenhou/eaif4_ws/build/hector_slam/hector_geotiff_plugins && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hector_geotiff_plugins.dir/src/trajectory_geotiff_plugin.cpp.o -c /home/wenhou/eaif4_ws/src/hector_slam/hector_geotiff_plugins/src/trajectory_geotiff_plugin.cpp

hector_slam/hector_geotiff_plugins/CMakeFiles/hector_geotiff_plugins.dir/src/trajectory_geotiff_plugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hector_geotiff_plugins.dir/src/trajectory_geotiff_plugin.cpp.i"
	cd /home/wenhou/eaif4_ws/build/hector_slam/hector_geotiff_plugins && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wenhou/eaif4_ws/src/hector_slam/hector_geotiff_plugins/src/trajectory_geotiff_plugin.cpp > CMakeFiles/hector_geotiff_plugins.dir/src/trajectory_geotiff_plugin.cpp.i

hector_slam/hector_geotiff_plugins/CMakeFiles/hector_geotiff_plugins.dir/src/trajectory_geotiff_plugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hector_geotiff_plugins.dir/src/trajectory_geotiff_plugin.cpp.s"
	cd /home/wenhou/eaif4_ws/build/hector_slam/hector_geotiff_plugins && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wenhou/eaif4_ws/src/hector_slam/hector_geotiff_plugins/src/trajectory_geotiff_plugin.cpp -o CMakeFiles/hector_geotiff_plugins.dir/src/trajectory_geotiff_plugin.cpp.s

hector_slam/hector_geotiff_plugins/CMakeFiles/hector_geotiff_plugins.dir/src/trajectory_geotiff_plugin.cpp.o.requires:

.PHONY : hector_slam/hector_geotiff_plugins/CMakeFiles/hector_geotiff_plugins.dir/src/trajectory_geotiff_plugin.cpp.o.requires

hector_slam/hector_geotiff_plugins/CMakeFiles/hector_geotiff_plugins.dir/src/trajectory_geotiff_plugin.cpp.o.provides: hector_slam/hector_geotiff_plugins/CMakeFiles/hector_geotiff_plugins.dir/src/trajectory_geotiff_plugin.cpp.o.requires
	$(MAKE) -f hector_slam/hector_geotiff_plugins/CMakeFiles/hector_geotiff_plugins.dir/build.make hector_slam/hector_geotiff_plugins/CMakeFiles/hector_geotiff_plugins.dir/src/trajectory_geotiff_plugin.cpp.o.provides.build
.PHONY : hector_slam/hector_geotiff_plugins/CMakeFiles/hector_geotiff_plugins.dir/src/trajectory_geotiff_plugin.cpp.o.provides

hector_slam/hector_geotiff_plugins/CMakeFiles/hector_geotiff_plugins.dir/src/trajectory_geotiff_plugin.cpp.o.provides.build: hector_slam/hector_geotiff_plugins/CMakeFiles/hector_geotiff_plugins.dir/src/trajectory_geotiff_plugin.cpp.o


# Object files for target hector_geotiff_plugins
hector_geotiff_plugins_OBJECTS = \
"CMakeFiles/hector_geotiff_plugins.dir/src/trajectory_geotiff_plugin.cpp.o"

# External object files for target hector_geotiff_plugins
hector_geotiff_plugins_EXTERNAL_OBJECTS =

/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: hector_slam/hector_geotiff_plugins/CMakeFiles/hector_geotiff_plugins.dir/src/trajectory_geotiff_plugin.cpp.o
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: hector_slam/hector_geotiff_plugins/CMakeFiles/hector_geotiff_plugins.dir/build.make
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: /home/wenhou/eaif4_ws/devel/lib/libgeotiff_writer.so
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: /usr/lib/x86_64-linux-gnu/libQtGui.so
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: /usr/lib/x86_64-linux-gnu/libQtCore.so
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: /usr/lib/x86_64-linux-gnu/libtinyxml2.so
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: /opt/ros/kinetic/lib/libclass_loader.so
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: /usr/lib/libPocoFoundation.so
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: /usr/lib/x86_64-linux-gnu/libdl.so
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: /opt/ros/kinetic/lib/libroslib.so
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: /opt/ros/kinetic/lib/librospack.so
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: /usr/lib/x86_64-linux-gnu/libpython2.7.so
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: /usr/lib/x86_64-linux-gnu/libtinyxml.so
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: /opt/ros/kinetic/lib/libroscpp.so
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: /opt/ros/kinetic/lib/librosconsole.so
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: /opt/ros/kinetic/lib/libxmlrpcpp.so
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: /opt/ros/kinetic/lib/libroscpp_serialization.so
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: /opt/ros/kinetic/lib/librostime.so
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: /opt/ros/kinetic/lib/libcpp_common.so
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so: hector_slam/hector_geotiff_plugins/CMakeFiles/hector_geotiff_plugins.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wenhou/eaif4_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library /home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so"
	cd /home/wenhou/eaif4_ws/build/hector_slam/hector_geotiff_plugins && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hector_geotiff_plugins.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
hector_slam/hector_geotiff_plugins/CMakeFiles/hector_geotiff_plugins.dir/build: /home/wenhou/eaif4_ws/devel/lib/libhector_geotiff_plugins.so

.PHONY : hector_slam/hector_geotiff_plugins/CMakeFiles/hector_geotiff_plugins.dir/build

hector_slam/hector_geotiff_plugins/CMakeFiles/hector_geotiff_plugins.dir/requires: hector_slam/hector_geotiff_plugins/CMakeFiles/hector_geotiff_plugins.dir/src/trajectory_geotiff_plugin.cpp.o.requires

.PHONY : hector_slam/hector_geotiff_plugins/CMakeFiles/hector_geotiff_plugins.dir/requires

hector_slam/hector_geotiff_plugins/CMakeFiles/hector_geotiff_plugins.dir/clean:
	cd /home/wenhou/eaif4_ws/build/hector_slam/hector_geotiff_plugins && $(CMAKE_COMMAND) -P CMakeFiles/hector_geotiff_plugins.dir/cmake_clean.cmake
.PHONY : hector_slam/hector_geotiff_plugins/CMakeFiles/hector_geotiff_plugins.dir/clean

hector_slam/hector_geotiff_plugins/CMakeFiles/hector_geotiff_plugins.dir/depend:
	cd /home/wenhou/eaif4_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wenhou/eaif4_ws/src /home/wenhou/eaif4_ws/src/hector_slam/hector_geotiff_plugins /home/wenhou/eaif4_ws/build /home/wenhou/eaif4_ws/build/hector_slam/hector_geotiff_plugins /home/wenhou/eaif4_ws/build/hector_slam/hector_geotiff_plugins/CMakeFiles/hector_geotiff_plugins.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : hector_slam/hector_geotiff_plugins/CMakeFiles/hector_geotiff_plugins.dir/depend

