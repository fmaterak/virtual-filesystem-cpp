file(GLOB_RECURSE SRC_FILES "*.cpp")
add_library(vfs_lib ${SRC_FILES})
target_include_directories(vfs_lib PUBLIC ../include)

add_executable(vfs_app main.cpp)
target_link_libraries(vfs_app PRIVATE vfs_lib)
target_link_libraries(vfs_lib PUBLIC nlohmann_json::nlohmann_json)
