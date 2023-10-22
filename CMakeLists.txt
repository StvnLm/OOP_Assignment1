cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Add the Patient class source files and create a library
add_library(Patient ./src/patient.cpp)  # Replace 'patient.cpp' with the actual source file(s) for the Patient class


enable_testing()

add_executable(
  patient_test
  ./test/patient_test.cpp
)
target_link_libraries(
  patient_test
  GTest::gtest_main
)

add_executable(
  inpatient_test
  ./test/inpatient_test.cpp
)
target_link_libraries(
  inpatient_test
  GTest::gtest_main
  Patient 
)

include(GoogleTest)
gtest_discover_tests(patient_test)
gtest_discover_tests(inpatient_test)