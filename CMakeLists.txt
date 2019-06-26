cmake_minimum_required(VERSION 3.10)
project(oj)

# to use google-test on windows with cygwin, we need use -std=gnu++11
# instead of -std=c++11
add_definitions(-std=gnu++11)

include(GoogleTest.cmake)
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
        problems/leetcode131.h
        problems/leetcode518.h
        problems/leetcode147.h
        problems/leetcode041.h
        )