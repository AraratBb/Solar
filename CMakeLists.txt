cmake_minimum_required(VERSION 3.0)

add_executable(testPars testPars.cpp parser.cpp parser.h)

set_target_properties(
  testPars PROPERTIES
  CXX_STANDART 11
  CXX_STANDART_REQUIRED ON
)

target_link_libraries(testPars gtest gmock pthread)
