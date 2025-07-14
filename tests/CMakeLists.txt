add_executable(test_vfs test_vfs.cpp)
target_include_directories(test_vfs PRIVATE ../include)
target_link_libraries(test_vfs PRIVATE vfs_lib)
add_test(NAME test_vfs COMMAND test_vfs)

add_executable(test_path test_path.cpp)
target_include_directories(test_path PRIVATE ../include)
target_link_libraries(test_path PRIVATE vfs_lib)
add_test(NAME test_path COMMAND test_path)

add_executable(test_serialization test_serialization.cpp)
target_include_directories(test_serialization PRIVATE ../include)
target_link_libraries(test_serialization PRIVATE vfs_lib)
add_test(NAME test_serialization COMMAND test_serialization)
