cmake_minimum_required(VERSION 3.2)

configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(
  COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download
)
execute_process(
  COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download
)
add_subdirectory(
  ${CMAKE_BINARY_DIR}/googletest-src
  ${CMAKE_BINARY_DIR}/googletest-build
)
target_include_directories(gmock_main SYSTEM BEFORE INTERFACE "${gtest_SOURCE_DIR}/include" "${gmock_SOURCE_DIR}/include")

add_library(
  string_searching STATIC
  string_searching.h
  string_searching.cc
)

enable_testing()
add_executable(string_searching_test string_searching_test.cc)
target_link_libraries(string_searching_test string_searching gmock_main)
add_test(NAME test COMMAND string_searching_test)
