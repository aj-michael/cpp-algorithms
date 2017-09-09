add_library(
  string_searching STATIC
  string_searching.h
  string_searching.cc
)
add_executable(string_searching_test string_searching_test.cc)
target_link_libraries(string_searching_test string_searching gmock_main)
add_test(NAME test COMMAND string_searching_test)