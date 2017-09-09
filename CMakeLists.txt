cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_FLAGS "-std=c++11")

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
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(
  ${CMAKE_BINARY_DIR}/googletest-src
  ${CMAKE_BINARY_DIR}/googletest-build
)
target_include_directories(
  gmock_main
  SYSTEM
  BEFORE
  INTERFACE
  "${gtest_SOURCE_DIR}/include"
  "${gmock_SOURCE_DIR}/include"
)

enable_testing()

add_subdirectory(sorting)
add_subdirectory(strings)
