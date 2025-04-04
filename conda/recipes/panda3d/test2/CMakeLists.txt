cmake_minimum_required(VERSION 3.15)

# The entire purpose of this project is to test a correct installation of
# panda3d, by linking a simple executable against it.
project(Panda3dTestConda)

message("==== CMAKE_CXX_COMPILER_ID = ${CMAKE_CXX_COMPILER_ID}")
message("==== CMAKE_CXX_SIMULATE_ID = ${CMAKE_CXX_SIMULATE_ID}")
message("==== CMAKE_CXX_COMPILER_FRONTEND_VARIANT = ${CMAKE_CXX_COMPILER_FRONTEND_VARIANT}")

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

find_package(Panda3d REQUIRED)
find_package(Eigen3 REQUIRED CONFIG)

find_package(OpenMP REQUIRED)

# find_package(MyOpenCV REQUIRED)
find_package(OpenCV REQUIRED core imgproc highgui calib3d features2d)
add_library(TestLib SHARED testlib.cpp testlib.h)

find_package(OpenMP REQUIRED)

find_package(ZLIB REQUIRED)

set(opt_libs "")
foreach(lib_ ${OpenMP_CXX_LIB_NAMES})
    if("x${lib_}" STREQUAL "xpthread")
      if(CMAKE_THREAD_LIBS_INIT)
        list(APPEND opt_libs "${CMAKE_THREAD_LIBS_INIT}")
      endif()
    else()
      list(APPEND opt_libs ${OpenMP_${lib_}_LIBRARY})
    endif()
  endforeach()
  
  message("== OpenCV_FOUND = ${OpenCV_FOUND}")
  message("== OpenCV_INCLUDE_DIRS = ${OpenCV_INCLUDE_DIRS}")
  message("== OpenCV_LIBRARIES = ${OpenCV_LIBRARIES}")
  message("== OpenCV_LIBS = ${OpenCV_LIBS}")



# target_include_directories(TestLib PRIVATE ${OpenCV_INCLUDE_DIRS})

set(ExtraWinLibs "winmm.lib  rpcrt4.lib  ws2_32.lib")

target_link_libraries(TestLib PUBLIC 
  # OpenMP::OpenMP_CXX
  ${opt_libs}
  ${ExtraWinLibs}
  opencv_core
  opencv_imgproc
  opencv_highgui
  opencv_calib3d
  opencv_features2d
  Eigen3::Eigen
  panda3d::panda
  panda3d::p3direct
  panda3d::pandaexpress
  panda3d::p3dtoolconfig
  panda3d::p3dtool
  panda3d::p3framework
  ZLIB::ZLIB)

set(CMAKE_SHARED_LINKER_FLAGS "/machine:x64 /INCREMENTAL:NO /DEBUG /NODEFAULTLIB:libc")

set(CMAKE_CXX_FLAGS "/DWIN32 /D_WINDOWS /W3 /GR /EHsc  -Wall -Wextra -Xclang -fopenmp /Gy /bigobj /MD /O2 /Ob2 /DNDEBUG")
set(CMAKE_C_FLAGS "/DWIN32 /D_WINDOWS /W3  -Wall -Wextra -Xclang -fopenmp /MD /O2 /Ob2 /DNDEBUG")

message("==== CMAKE_C_FLAGS = ${CMAKE_C_FLAGS}")
message("==== CMAKE_CXX_FLAGS = ${CMAKE_CXX_FLAGS}")
# message("== before CMAKE_SHARED_LINKER_FLAGS = ${CMAKE_SHARED_LINKER_FLAGS}")
# string(REPLACE "/INCREMENTAL " "/INCREMENTAL:NO " CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS}")
# message("== after CMAKE_SHARED_LINKER_FLAGS = ${CMAKE_SHARED_LINKER_FLAGS}")
# message("== OpenMP_CXX_FLAGS = ${OpenMP_CXX_FLAGS}")
# add_executable(TestExe test.cpp)
# target_link_libraries(TestExe PUBLIC 
#   Eigen3::Eigen
#   panda3d::panda
#   panda3d::pandaexpress
#   panda3d::p3dtoolconfig
#   panda3d::p3dtool
#   panda3d::p3framework)