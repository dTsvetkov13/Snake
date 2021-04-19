cmake_minimum_required( VERSION 3.7 )

project( Snake )

# this is needed to be able to use the protobuf_generate_cpp function
# because it is deprecated in the newer versions of the protobuf vcpkg
# package on windows.
if(WIN32)
  set(protobuf_MODULE_COMPATIBLE TRUE)
endif()

# On MacOS clang complains if this is not set
set (CMAKE_CXX_STANDARD 11)

add_subdirectory(src)

add_executable(${PROJECT_NAME} ${SRC_LIST})

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})