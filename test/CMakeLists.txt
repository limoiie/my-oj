add_executable(test_tree
        test_tree.cpp
        test_list.cpp)
target_link_libraries(test_tree gtest_main)
add_test(NAME tree_test COMMAND test_tree)