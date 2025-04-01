cmake_minimum_required(VERSION 3.15)

# The entire purpose of this project is to test a correct installation of
# panda3d, by linking a simple executable against it.
project(Panda3dTestConda)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

find_package(Panda3d REQUIRED)
find_package(Eigen3 REQUIRED CONFIG)

find_package(OpenMP REQUIRED)

find_package(MyOpenCV REQUIRED)

add_library(TestLib SHARED testlib.cpp testlib.h)

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

target_link_libraries(TestLib PUBLIC 
  # OpenMP::OpenMP_CXX
  ${OpenCV_LIBRARIES}
  ${opt_libs}
  Eigen3::Eigen
  panda3d::panda
  panda3d::p3direct
  panda3d::pandaexpress
  panda3d::p3dtoolconfig
  panda3d::p3dtool
  panda3d::p3framework)

message("== before CMAKE_SHARED_LINKER_FLAGS = ${CMAKE_SHARED_LINKER_FLAGS}")
string(REPLACE "/INCREMENTAL " "/INCREMENTAL:NO " CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS}")
message("== after CMAKE_SHARED_LINKER_FLAGS = ${CMAKE_SHARED_LINKER_FLAGS}")
message("== OpenMP_CXX_FLAGS = ${OpenMP_CXX_FLAGS}")
# add_executable(TestExe test.cpp)
# target_link_libraries(TestExe PUBLIC 
#   Eigen3::Eigen
#   panda3d::panda
#   panda3d::pandaexpress
#   panda3d::p3dtoolconfig
#   panda3d::p3dtool
#   panda3d::p3framework)
