cmake_minimum_required(VERSION 3.4.1)

project("nativehelper")

# prefabPublishing does not support header only lib
# https://issuetracker.google.com/issues/173348031

#add_library(nativehelper_header_only INTERFACE)
#target_include_directories(nativehelper_header_only INTERFACE header_only_include/nativehelper)

add_library(nativehelper_header_only STATIC dummy.cpp)
target_link_libraries(nativehelper_header_only)