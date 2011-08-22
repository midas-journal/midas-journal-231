#Change PROJECT_NAME to the name of your project
PROJECT(RunLengthFeaturesTest)

cmake_minimum_required(VERSION 2.4)

if(COMMAND cmake_policy)
  cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

#The following lines are required to use Dart
ENABLE_TESTING()
INCLUDE(Dart)

include (${CMAKE_ROOT}/Modules/FindITK.cmake)
if (USE_ITK_FILE)
  include(${USE_ITK_FILE})
endif(USE_ITK_FILE)

link_directories(
  ${ITK_LIBRARY_PATH}
)

#the following block of code is an example of how to build an executable in
#cmake.  Unmodified, it will add an executabale called "MyExe" to the project.
#MyExe will be built using the files MyClass.h and MyClass.cxx, and it will
#be linked to all the libraries you specified above.
#You can build more than one executable per project
IF(BUILD_TESTING)
SET(CurrentExe
    "itkRunLengthFeaturesTest"
    )
ADD_EXECUTABLE(${CurrentExe}
               ${CurrentExe}.cxx)
TARGET_LINK_LIBRARIES(${CurrentExe}
                      ${ITK_LIBRARIES})

ENDIF(BUILD_TESTING)
#the following line is an example of how to add a test to your project.
#Testname is the title for this particular test.  ExecutableToRun is the
#program which will be running this test.  It can either be a part of this
#project or an external executable.  After that list any args that are needed
#for this test.  Include as many tests as you like.  If your project doesn't have
#any tests you can comment out or delete the following line.
# ADD_TEST(Testname ExecutableToRun arg1 arg2 arg3)
ADD_TEST( RunLengthTest0 ${CurrentExe}
          ${CMAKE_SOURCE_DIR}/textures/1.0.00.png )
ADD_TEST( RunLengthTest1 ${CurrentExe}
          ${CMAKE_SOURCE_DIR}/textures/1.0.01.png )
ADD_TEST( RunLengthTest2 ${CurrentExe}
          ${CMAKE_SOURCE_DIR}/textures/1.0.02.png )
ADD_TEST( RunLengthTest3 ${CurrentExe}
          ${CMAKE_SOURCE_DIR}/textures/1.1.01.png )
ADD_TEST( RunLengthTest4 ${CurrentExe}
          ${CMAKE_SOURCE_DIR}/textures/1.1.02.png )
ADD_TEST( RunLengthTest5 ${CurrentExe}
          ${CMAKE_SOURCE_DIR}/textures/1.1.03.png )
ADD_TEST( RunLengthTest6 ${CurrentExe}
          ${CMAKE_SOURCE_DIR}/textures/1.1.04.png )
ADD_TEST( RunLengthTest7 ${CurrentExe}
          ${CMAKE_SOURCE_DIR}/textures/1.1.05.png )
ADD_TEST( RunLengthTest8 ${CurrentExe}
          ${CMAKE_SOURCE_DIR}/textures/1.1.06.png )
ADD_TEST( RunLengthTest9 ${CurrentExe}
          ${CMAKE_SOURCE_DIR}/textures/1.1.07.png )
ADD_TEST( RunLengthTest10 ${CurrentExe}
          ${CMAKE_SOURCE_DIR}/textures/1.1.08.png )
ADD_TEST( RunLengthTest11 ${CurrentExe}
          ${CMAKE_SOURCE_DIR}/textures/1.1.09.png )
ADD_TEST( RunLengthTest12 ${CurrentExe}
          ${CMAKE_SOURCE_DIR}/textures/1.1.10.png )
ADD_TEST( RunLengthTest13 ${CurrentExe}
          ${CMAKE_SOURCE_DIR}/textures/1.1.11.png )
ADD_TEST( RunLengthTest14 ${CurrentExe}
          ${CMAKE_SOURCE_DIR}/textures/1.1.12.png )
ADD_TEST( RunLengthTest15 ${CurrentExe}
          ${CMAKE_SOURCE_DIR}/textures/1.1.13.png )
