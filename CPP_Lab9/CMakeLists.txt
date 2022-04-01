# CMakeList.txt : CMake project for HelloJava, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
project(HelloJava)					  # Create project "simple_example"
set(CMAKE_CXX_STANDARD 11)            # Enable c++11 standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Add executable target with source files listed in SOURCE_FILES variable
#SHARED means make .dll instead of .lib

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}   /openmp")

add_library(MyCPPLibrary0 SHARED "HelloJava.h" "HelloJava.cpp" "HelloJava.java")

target_include_directories( MyCPPLibrary0 PRIVATE
	"C:\\Program Files\\Java\\jdk1.8.0_221\\include"
	"C:\\Program Files\\Java\\jdk1.8.0_221\\include\\win32")
	
