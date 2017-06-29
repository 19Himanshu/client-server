
# CMAKE for seqgen project
# ~/SeqSoft/seqgen/src
message(STATUS "***** START client-server CMAKE ****")
cmake_minimum_required (VERSION 2.8.12)
message(STATUS "Processing: ${CMAKE_CURRENT_SOURCE_DIR}")

# Name the Xcode project: GEN
project(GEN C CXX)

# Recognize the location of other cmake modules 
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
# I'm going to put all my own code (e.g. *.cpp, *.hpp, etc.) in the following directory("ies")
set(SUBDIRS
    client-server
    )

set(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)
set(CMAKE_BUILD_WITH_INSTALL_RPATH true)
set(CMAKE_LIBRARY_PATH $ENV{LD_LIBRARY_PATH})    


# Include directories of the project itself
include_directories(
    ${PROJECT_BINARY_DIR}
    ${HEADER_SUBDIRS}
    )
get_directory_property(include_directories INCLUDE_DIRECTORIES)
message(STATUS "SUBDIRS ='${SUBDIRS}'")
message(STATUS "PROJECT_BINARY_DIR ='${PROJECT_BINARY_DIR}'")
message(STATUS "HEADER_SUBDIRS ='${HEADER_SUBDIRS}'")
message(STATUS "INCLUDE_DIRECTORIES='${include_directories}'")

# ********************************************************
# ==================== COMPILE FLAGS ====================
set(EXTRA_FLAGS "-std=c++11 -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} ${EXTRA_FLAGS} -v")
message(STATUS "CMAKE_CXX_FLAGS='${CMAKE_CXX_FLAGS}'")
# ==================== COMPILE FLAGS ====================
# ********************************************************

# ********************************************************
# ===================== LINKER FLAGS =====================
set(CMAKE_EXE_LINKER_FLAGS "-Wl -v")
message(STATUS "CMAKE_EXE_LINKER_FLAGS='${CMAKE_EXE_LINKER_FLAGS}'")
# ===================== LINKER FLAGS =====================
# ********************************************************

# Need this for make to work, adds subdirectories to the build
# Each of these subdirectories will require CMakeLists.txt files
### Descend into subdirectories
foreach(dir ${SUBDIRS})
    add_subdirectory(${dir})
endforeach()

# SeqRunch is the name of my executable as defined in ~/seqode/CMakeLists.txt
# set_target_properties(SeqRunch PROPERTIES XCODE_ATTRIBUTE_CC "/usr/local/opt/llvm/bin/clang")
