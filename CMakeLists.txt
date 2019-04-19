cmake_minimum_required(VERSION 3.10)
project(oj)

# to use google-test on windows with cygwin, we need use -std=gnu++11
# instead of -std=c++11
add_definitions(-std=gnu++11)

# COMMENTED BY LIMO: to bulid google-test on windows with cygwin need
# -std=gnu++11 instead of -std=c++11. so I changed the source code in
# cmake-build-debug/googletest-src/CMakeLists.txt to build google-test
# with -std=gnu++11 instead of -std=c++11. and since I have change the
# google-test source code, I comment the following codes to avoid git
# sychronizing with the remote.
#
# NOTE: if you want to download or update google-test source code, you
# need to uncommend the following code and the code in
# cmake-build-debug/googletest-src/CMakeLists.txt
#
# Download and unpack googletest at configure time
configure_file(GoogleTest.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
       RESULT_VARIABLE result
       WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
   message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
       RESULT_VARIABLE result
       WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
   message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL
        )

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()
include_directories(.)

add_definitions(
        -DGTEST_DONT_DEFINE_TEST=1
)

add_subdirectory(test)


add_executable(oj main.cpp
        problems/base.h
        problems/leetcode215.h
        problems/leetcode169.h
        problems/leetcode036.h
        problems/leetcode303.h
        problems/leetcode032.h
        algorithm/tree_travel.h
        algorithm/tree.h
        algorithm/list.h 
        algorithm/utils.h
        problems/leetcode518.h 
        problems/leetcode147.h
        problems/leetcode041.h
        )