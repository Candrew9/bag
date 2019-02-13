cmake_minimum_required(VERSION 3.5)
project(hw1 CXX)

# Require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create unit tests 
#   In the following, notice that ArrayBag.cpp is NOT listed.  
#   Instead, ArrayBag.cpp is #included by NewArrayBag.h to support templates.
add_executable(hw1_test BagInterface.h ArrayBag.h hw1_test.cpp catch.hpp)

# The following will not be graded at the autograder. 
#  It is primarily for your convenience 
#  to experiment with your own main() function in hw1_main.cpp.
add_executable(hw1_main BagInterface.h ArrayBag.h hw1_main.cpp)

# Unit tests 
enable_testing(unittest hw1_test)

# A rule to create the submission zip file
set(CODE_TO_SUBMIT BagInterface.h ArrayBag.h ArrayBag.cpp hw1_test.cpp)
add_custom_target(submission COMMAND
    ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/hw1_submission.zip" --format=zip
    ${CODE_TO_SUBMIT}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

