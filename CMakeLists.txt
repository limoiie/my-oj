cmake_minimum_required(VERSION 3.10)
project(oj)

set(CMAKE_CXX_STANDARD 17)

include(GoogleTest.cmake)

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
        problems/leetcode131.h
        )